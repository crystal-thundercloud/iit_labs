#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#define matrixSize 18

using namespace std;

class RecursiveDepthFirstSearch {
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

    void dropDistances(int distances[], bool visitedPoints[]) {
        for (int i = 0; i < matrixSize; i++) {
            distances[i] = 999;
            visitedPoints[i] = false;
        }
    }

    void findDistances(int matrixArr[matrixSize][matrixSize], bool visitedPoints[], int startPoint, int parentPoints[matrixSize]) {
        for (int i = 0; i < matrixSize; i++) {
            if (!visitedPoints[i] && matrixArr[startPoint][i] != 0) {
                parentPoints[i] = startPoint;
                visitedPoints[i] = true;
                findDistances(matrixArr, visitedPoints, i, parentPoints);
            }
        }
    }
};

/*
    Написать программу поиска в глубину с использованием рекурсии, реализующую алгоритм поиска пути на не взвешенном графе между двумя вершинами. 

    Результат выдавать перечислением вершин в порядке их обхода.
*/

int main() {
    setlocale(LC_ALL, "RU");

    RecursiveDepthFirstSearch rdfs;

    int startPoint = -1, endPoint = -1;

    int origMatrix[matrixSize][matrixSize];
    int minDistances[matrixSize];
    bool visitedPoints[matrixSize];

    rdfs.readMatrixFromFile("matrix.txt", origMatrix);
    rdfs.dropDistances(minDistances, visitedPoints);

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

    int parentPoints[matrixSize];
    parentPoints[startPoint] = startPoint;
    visitedPoints[startPoint] = true;

    rdfs.findDistances(origMatrix, visitedPoints, startPoint, parentPoints);

    int point = endPoint;
    vector<int> pathPoints;

    while (point != startPoint) {
        pathPoints.push_back(point);
        point = parentPoints[point];
    }
    pathPoints.push_back(startPoint);

    cout << "Результат рекурсивного поиска в глубину: " << endl;

    for (int i = pathPoints.size() - 1; i >= 0; i--) {
        if (i > 0) cout << pathPoints[i] << " -> ";
        else cout << pathPoints[i];
    }   

    cout << endl;
    return 0;
}