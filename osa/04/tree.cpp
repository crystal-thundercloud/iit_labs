#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct tree {
    node* root;
    int nodeCount;

    void newTree() {
        root = NULL;
        nodeCount = 0;
    }

    int addNode(int val) { // 1 - добавление элемента
        node* nd = new node(val);
        if (nodeCount==0) {
            root = nd;
            nodeCount++;
            return 0;
        }
        else {
            node* rt = root;
            for (int i = 0; i <= nodeCount; i++) {
                if (nd->data == rt->data)  return 2;
                else if (rt->left != NULL && nd->data < rt->data) {
                    rt = rt->left;
                }
                else if (rt->right != NULL && nd->data > rt->data) {
                    rt = rt->right;
                }
            }
            if (nd->data < rt->data) {
                rt->left = nd;
            }
            else {
                rt->right = nd;
            }
        }
        nodeCount++;
        return 1;
    }

    int findNode(int val) { // 2 - поиск элемента
        node* nd = root;
        int j = 1;
        if (nodeCount>0) {
            for (int i = 0; i <= nodeCount; i++) {
                if (nd->data==val) return j;
                else if (nd->left!=NULL && val<nd->data) {
                    nd = nd->left;
                }
                else if (nd->right!=NULL&&val>nd->data) {
                    nd = nd->right;
                }
                j++;
            }
            return 0;
        }
        else return -1;
    }

    vector <int>* returnTree(node* nd, vector <int>* v = new vector <int>) { // 3 - обход дерева
        vector <int>* vec = v;
        if (nd!=NULL) {
            returnTree(nd->left, vec);
            vec->push_back(nd->data);
            returnTree(nd->right, vec);
        }
        return vec;
    }
};

void printTree(vector<int>* v) {
    //vector<int> &vr = *v; //один из вариантов вывода *v через vr[i]. нашла вариант попроще, но этот оставлю, чтобы был как референс (может, пригодится)
    for (int i = 0; i < v->size(); i++) {
        cout << (*v)[i] << " "; // ещё можно через v->operator[](i) (тоже будет как референс на будущее)
    }
}
/*
    Разработать программу синтеза и обхода бинарного дерева. 

    Для заданной последовательности данных с помощью созданной программы построить и сохранить в файле бинарное дерево. 
    Используя функцию обхода в разработанной программе произвести чтение структуры бинарного дерева и выполнить его обход, сохранив последовательность прохождения вершин в текстовом файле (.txt).
    Операции по работе с деревом: 
        Добавить элемент
        Поиск элемента
        Обход дерева
*/

int main() {
    setlocale(LC_ALL, "RU");

    int ans = -1, value;
    tree tr;
    tr.newTree();

    do {
		while (ans < 1 || ans > 4) {
			cout << "\nКакое действие с деревом вы хотите совершить?"
				<< "\n1. Добавить элемент"
				<< "\n2. Найти элемент по значению"
				<< "\n3. Совершить обход дерева"
				<< "\n4. Завершить работу"
				<< endl;
			cin >> ans;
		}

		if (ans == 1) {
            cout << "Введите значение добавляемого элемента: ";
            cin >> value;
            value = tr.addNode(value);

            if (value == 0) cout << "Добавлен корневой элемент";
            else if (value == 1) cout << "Элемент успешно добавлен";
            else cout << "Элемент с данным значением уже существует";


        }

		else if (ans == 2) {
            cout << "Введите значение искомого элемента: ";
            cin >> value;
            value = tr.findNode(value);

            if (value == -1) cout << "Дерево пустое";
            else if (value == 0) cout << "Элемент с заданным значением не найден";
            else cout << "Элемент найден на строке #" << value << endl;
        }

		else if (ans == 3) {
            vector <int> *v = tr.returnTree(tr.root);
            printTree(v);
        }

        else goto end;

        cout << "\nВведите 99, чтобы продолжить, номер пункта, чтобы сразу начать работу с ним, и 4, чтобы завершить работу: ";
		cin >> ans;
	}

	while (ans != 4);
    end:
    return 0;
}