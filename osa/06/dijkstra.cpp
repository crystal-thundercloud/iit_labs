#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#define matrixSize 10

using namespace std;

class Dejkstra {
public:
    void readMatrixFromFile(string fileName, int matrixArr[matrixSize][matrixSize]) {
        fstream matrixFile;
        matrixFile.open(fileName);
        for (int i = 0; i < matrixSize; i++) {
            for (int j = 0; j < matrixSize; j++) {
                matrixFile >> matrixArr[i][j];
            }
        }
        matrixFile.close();
    }

    void writeResultInFile(string fileName, vector <int> *pathPoints, int startPoint, int endPoint) {
        ofstream resultFile(fileName);
        resultFile << startPoint << "\n" << endPoint << "\n";

        for (int i = pathPoints->size() - 1; i >= 0; i--) {
            if ((*pathPoints)[i] != startPoint && (*pathPoints)[i] != endPoint) resultFile << (*pathPoints)[i] << " ";
        }
        resultFile.close();
    }

    void dropDistances(int distances[], bool visitedPoints[]) {
        for (int i = 0; i < matrixSize; i++) {
            distances[i] = 999;
            visitedPoints[i] = false;
        }
    }

    void findMinDistances(int matrixArr[matrixSize][matrixSize], int minDistances[], bool visitedPoints[], int startPoint, int endPoint) {
        int minValue = 999, minValueIndex = 0;

        for (int i = 0; i < matrixSize; i++) {
            minDistances[i] = matrixArr[startPoint][i];
            if (matrixArr[startPoint][i] > 0 && matrixArr[startPoint][i] < minValue) {
                minValue = matrixArr[startPoint][i];
                minValueIndex = i;
            }
        }

        visitedPoints[startPoint] = true;
            
        int localStartPoint = minValueIndex;
        int localMinValue = minValue;

        for (int k = 0; k < matrixSize-1; k++) {
            minValue = 999;
            visitedPoints[localStartPoint] = true;

            for (int i = 0; i < matrixSize; i++) {
                if (matrixArr[localStartPoint][i] > 0 && (matrixArr[localStartPoint][i] + localMinValue < minDistances[i] || minDistances[i] == 0) && !visitedPoints[i]) {
                    minDistances[i] = matrixArr[localStartPoint][i] + localMinValue;
                }
                if (minDistances[i] > 0 && minDistances[i] < minValue && !visitedPoints[i]) {
                    minValue = minDistances[i];
                    minValueIndex = i;
                }
            }

            localMinValue = minValue;
            localStartPoint = minValueIndex;
        }
    }

    vector <int> *getPathPoints(int origMatrix[matrixSize][matrixSize], vector <int> *pathPoints, int startPoint, int endPoint, int pathLength, int tempLength, int index) {
        if (pathPoints->back() != startPoint) {
            for (int i = 0; i < matrixSize; i++) {
                if (origMatrix[i][index] <= tempLength && origMatrix[i][index] != 0 && i != index && i != endPoint && find(pathPoints->begin(), pathPoints->end(), i) == pathPoints->end()) {
                    pathPoints->push_back(i);

                    if (pathPoints->back() == startPoint && tempLength == 0) return pathPoints;

                    getPathPoints(origMatrix, pathPoints, startPoint, endPoint, pathLength, tempLength-origMatrix[i][index], i);
                    if (pathPoints->back() == startPoint) return pathPoints;
                    pathPoints->pop_back();

                    if (tempLength == origMatrix[i][index]) return pathPoints;
                }
            }
        }
        return pathPoints;
    }
};

/*
    Написать алгоритм Дейкстры. 

    Граф задается в файле в виде матрицы. 
    Входные данные: начальная и конечная вершина.
    После завершения обхода графа результат должен быть записан в файл путем добавления строки в формате:
        начальная вершина,
        конечная вершина,
        промежуточные вершины от начальной до конечной. 
    Исходный граф должен содержать не менее 10-ти вершин и 30-ти связей между ними.
*/

int main() {
    setlocale(LC_ALL, "RU");

    Dejkstra dejkstra;

    int startPoint = -1, endPoint = -1;

    int origMatrix[matrixSize][matrixSize];
    int minDistances[matrixSize];
    bool visitedPoints[matrixSize];

    dejkstra.readMatrixFromFile("matrix.txt", origMatrix);
    dejkstra.dropDistances(minDistances, visitedPoints);

    cout << "Исходная матрица с номерами вершин: " << endl;
    for (int i = 0; i < matrixSize; i++) {
        if (i==0) cout << setw(9) << i << " ";
        else cout << setw(3) << i << " ";
    }
    
    for (int i = 0; i < matrixSize*4; i++) {
        if (i==0) cout << "\n     -";
        else cout << "-";
    }
    cout  << endl;

    for (int i = 0; i < matrixSize; i++) {
        cout << setw(3) << i << " | ";
        for (int j = 0; j < matrixSize; j++) {
             cout << setw(3) << origMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nВведите вершины для построения пути (индексы от 0 до " << matrixSize - 1 << " включительно, старт!=начало)" << endl;
    do {
        cout << "Стартовая вершина: ";
        cin >> startPoint;
    } while (startPoint < 0 || startPoint > matrixSize - 1);

    do {
        cout << "Конечная вершина: ";
        cin >> endPoint;
    } while (endPoint < 0 || endPoint > matrixSize - 1 || endPoint == startPoint);

    dejkstra.findMinDistances(origMatrix, minDistances, visitedPoints, startPoint, endPoint);

    cout << "Длина минимального пути из " << startPoint << " в " << endPoint << ": " << minDistances[endPoint] << endl;

    vector<int> *pathPoints = new vector<int>;
    pathPoints->push_back(endPoint);
    pathPoints = dejkstra.getPathPoints(origMatrix, pathPoints, startPoint, endPoint, minDistances[endPoint], minDistances[endPoint], endPoint);

    cout << "Конечный путь: ";
    for (int i = pathPoints->size() - 1; i >= 0; i--) {
        if (i > 0) cout << setw(3) << (*pathPoints)[i] << setw(5) << " -> ";
        else cout << setw(3) << (*pathPoints)[i];
    }

    cout << endl;

    // pathPoints.erase(remove(pathPoints->begin(), pathPoints->end(), startPoint), pathPoints->end());
    // pathPoints.erase(remove(pathPoints->begin(), pathPoints->end(), endPoint), pathPoints->end());

    dejkstra.writeResultInFile("result.txt", pathPoints, startPoint, endPoint);

    return 0;
}
