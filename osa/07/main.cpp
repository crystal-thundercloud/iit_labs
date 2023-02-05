#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>

#define matrixSize 18

using namespace std;

class BreadFirstSearch {
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

    void findDistances(int matrixArr[matrixSize][matrixSize], queue <int> markedPoints, bool visitedPoints[], int startPoint, int endPoint, int parentPoints[matrixSize]) {
        markedPoints.push(startPoint);
        visitedPoints[startPoint] = true;

        while (markedPoints.size() > 0) {
            int point = markedPoints.front();
            markedPoints.pop();
            for (int i = 0; i < matrixSize; i++) {
                if (!visitedPoints[i] && i!=point && matrixArr[point][i] != 0 && i != point) {
                    markedPoints.push(i);
                    visitedPoints[i] = true;
                    parentPoints[i] = point;
                    if (i == endPoint) return;
                }
            }
        }
    }
};

/*
    Написать программу поиска в ширину, реализующую алгоритм поиска пути на графе между двумя вершинами. 

    Результат выдавать перечислением вершин в порядке их обхода.
*/

int main() {
    setlocale(LC_ALL, "RU");

    BreadFirstSearch bfs;

    int startPoint = -1, endPoint = -1;

    int origMatrix[matrixSize][matrixSize];
    int minDistances[matrixSize];
    bool visitedPoints[matrixSize];

    bfs.readMatrixFromFile("matrix.txt", origMatrix);
    bfs.dropDistances(minDistances, visitedPoints);

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

    queue<int> markedPoints;
    int parentPoints[matrixSize];
    parentPoints[startPoint] = startPoint;

    bfs.findDistances(origMatrix, markedPoints, visitedPoints, startPoint, endPoint, parentPoints);

    int point = endPoint;
    vector<int> pathPoints;

    while (point != startPoint) {
        pathPoints.push_back(point);
        point = parentPoints[point];
    }
    pathPoints.push_back(startPoint);

    cout << "Результат поиска в ширину: " << endl;

    for (int i = pathPoints.size() - 1; i >= 0; i--) {
        if (i > 0) cout << pathPoints[i] << " -> ";
        else cout << pathPoints[i];
    }

    cout << endl;
    return 0;
}