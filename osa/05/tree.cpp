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

class tree {
    private:
    node* root;
    int nodeCount;

    public:
    void newTree() {
        root = NULL;
        nodeCount = 0;
    }

    int addNode(int val) { // 1 - добавление элемента
        node* nodeToAdd = new node(val);
        if (nodeCount==0) {
            root = nodeToAdd;
            nodeCount++;
            return 0;
        }
        else {
            node* parentNode = root;
            for (int i = 0; i <= nodeCount; i++) {
                if (nodeToAdd->data == parentNode->data)  return 2;
                else if (parentNode->left != NULL && nodeToAdd->data < parentNode->data) {
                    parentNode = parentNode->left;
                }
                else if (parentNode->right != NULL && nodeToAdd->data > parentNode->data) {
                    parentNode = parentNode->right;
                }
            }
            if (nodeToAdd->data < parentNode->data) {
                parentNode->left = nodeToAdd;
            }
            else {
                parentNode->right = nodeToAdd;
            }
        }
        nodeCount++;
        return 1;
    }    

    int findNode(int val) { // 2 - поиск элемента
        node* nd = root;
        int strNum = 1;
        if (nodeCount>0) {
            for (int i = 0; i <= nodeCount; i++) {
                if (nd->data==val) return strNum;
                else if (nd->left != NULL && val < nd->data)
                    nd = nd->left;
                else if (nd->right != NULL && val > nd->data)
                    nd = nd->right;
                strNum++;
            }
            return 0;
        }
        else return -1;
    }

    void returnTree(node* nd, vector<int> *vec) { // 3 - обход дерева (вспомогательное)
        if (nd!=NULL) {
            returnTree(nd->left, vec);
            vec->push_back(nd->data);
            returnTree(nd->right, vec);
        }
    }
    
    vector <int> *returnFullTree() { // 3 - обход дерева
        vector<int> *vec = new vector<int>;
        returnTree(root, vec);
        return vec;
    }

    int removeNode(int val) { // 4 - удаление элемента
        node* foundNodeParent = root;
        node *foundNode = NULL;
        if (nodeCount == 0) return -1;
        for (int i = 0; i < nodeCount; i++) {
            if (foundNodeParent->data==val) foundNode = foundNodeParent;
            else if (foundNodeParent->left != NULL && foundNodeParent->left->data == val)
                foundNode = foundNodeParent->left;
            else if (foundNodeParent->right != NULL && foundNodeParent->right->data == val)
                foundNode = foundNodeParent->right;
            else if (foundNodeParent->left != NULL && val < foundNodeParent->data)
                foundNodeParent = foundNodeParent->left;
            else if (foundNodeParent->right != NULL && val > foundNodeParent->data)
                foundNodeParent = foundNodeParent->right;
        }

        if (foundNode != NULL){ // если элемент с заданным значением найден
            if (nodeCount == 1 && foundNode == root) root = NULL; //если это единственный элемент и корень - очищаем дерево

            else if (foundNode->left == NULL && foundNode->right == NULL) { // если у элемента нет потомков - просто удаляем его и ссылку на него из родителя
                if (foundNodeParent->left == foundNode)
                    foundNodeParent->left = NULL;
                else if (foundNodeParent->right == foundNode)
                    foundNodeParent->right = NULL;
                foundNode = NULL;
            }

            else if (foundNode->left != NULL && foundNode->right == NULL) { // если есть только левый потомок - заменяем ссылку родителя с найденного жлемента на потомка
                if (foundNode==root)
                    root = foundNode->left;
                else if (foundNodeParent->left == foundNode)
                    foundNodeParent->left = foundNode->left;
                else if (foundNodeParent->right == foundNode)
                    foundNodeParent->right = foundNode->left;
                foundNode = foundNode->left;
            }

            else if (foundNode->left == NULL && foundNode->right != NULL) { // то же для только правого
                if (foundNode==root)
                    root = foundNode->right;
                else if (foundNodeParent->left == foundNode)
                    foundNodeParent->left = foundNode->right;
                else if (foundNodeParent->right == foundNode)
                    foundNodeParent->right = foundNode->right;
                foundNode = foundNode->right;
            }

            else { // если есть оба потомка - заменяем на самый правый в левом поддереве либо самый левой в правом (какой окажется ниже)
                node *leftBranchMax, *leftBranchMaxParent, *rightBranchMin, *rightBranchMinParent;
                int lStrNum = 1, rStrNum = 1;

                leftBranchMaxParent = foundNode->left; // находим значения заменяющего элемента и его родителя в левом поддереве
                if (leftBranchMaxParent->right!=NULL) {
                    leftBranchMax = leftBranchMaxParent->right;
                    lStrNum++;
                    while (leftBranchMax->right!=NULL) {
                        leftBranchMax = leftBranchMaxParent->right;
                        if (leftBranchMax->right!=NULL)
                            leftBranchMaxParent = leftBranchMaxParent->right;
                        lStrNum++;
                    }
                }
                
                else {
                    leftBranchMax = foundNode->left;
                    leftBranchMaxParent = foundNode;
                }

                rightBranchMinParent = foundNode->right; // находим значения заменяющего элемента и его родителя в правом поддереве
                if (rightBranchMinParent->left!=NULL) {
                    rightBranchMin = rightBranchMinParent->left;
                    rStrNum++;
                    while (rightBranchMin->left!=NULL) {
                        rightBranchMin = rightBranchMinParent->left;
                        if (rightBranchMin->left!=NULL)
                            rightBranchMinParent = rightBranchMinParent->left;
                        rStrNum++;
                    }
                }

                else {
                    rightBranchMin = foundNode->right;
                    rightBranchMinParent = foundNode;
                }

                if (lStrNum >= rStrNum) { // если в левом поддереве подхоодящий для замещения элемент наравне с правым или ниже, то замещаем на него
                    if (lStrNum > 1) leftBranchMaxParent->right = leftBranchMax->left;
                    else leftBranchMaxParent->left = leftBranchMax->left;

                    leftBranchMax->left = foundNode->left;
                    leftBranchMax->right = foundNode->right;

                    if (foundNode == root)
                        root = leftBranchMax;

                    else if (foundNodeParent == foundNode) 
                        foundNode = leftBranchMax;

                    else if (foundNodeParent->left == foundNode) 
                        foundNodeParent->left = leftBranchMax;
                        
                    else if (foundNodeParent->right == foundNode) 
                        foundNodeParent->right = leftBranchMax;
                }

                else { // иначе замещаем на правый
                    if (rStrNum > 1) rightBranchMinParent->left = rightBranchMin->right;
                    else rightBranchMinParent->right = rightBranchMin->right;

                    rightBranchMin->left = foundNode->left;
                    rightBranchMin->right = foundNode->right;

                    if (foundNode == root)
                        root = rightBranchMin;
                    else if (foundNodeParent == foundNode) 
                        foundNode = rightBranchMin;

                    else if (foundNodeParent->left == foundNode)
                        foundNodeParent->left = rightBranchMin;
                        
                    else if (foundNodeParent->right == foundNode)
                        foundNodeParent->right = rightBranchMin;
                }
            }
            nodeCount--;
            return 1;
        }

        else
            return 0;
    }
};

void printTree(vector<int> *v) {
    for (int i = 0; i < v->size(); i++) {
        cout << (*v)[i] << " ";
    }
}

/*
    В предыдущую программу по работе с деревом добавить метод удаления элемента. 
    
    Операции по работе с деревом: 
        Добавить элемент
        Поиск элемента
        Обход дерева
        Удаление элемента 
*/

int main() {
    setlocale(LC_ALL, "RU");

    int answer = -1, value, result;
    tree tree1;
    tree1.newTree();

    do {
		while (answer < 1 || answer > 5) {
			cout << "\nКакое действие с деревом вы хотите совершить?"
				<< "\n1. Добавить элемент"
				<< "\n2. Найти элемент по значению"
				<< "\n3. Совершить обход дерева"
				<< "\n4. Удалить элемент"
				<< "\n5. Завершить работу"
				<< endl;
			cin >> answer;
		}

		if (answer == 1) {
            cout << "Введите значение добавляемого элемента: ";
            cin >> value;
            result = tree1.addNode(value);

            if (result == 0) cout << "Добавлен корневой элемент";
            else if (result == 1) cout << "Элемент успешно добавлен";
            else cout << "Элемент с данным значением уже существует";
        }

		else if (answer == 2) {
            cout << "Введите значение искомого элемента: ";
            cin >> value;
            result = tree1.findNode(value);

            if (result == -1) cout << "Дерево пустое";
            else if (result == 0) cout << "Элемент с заданным значением не найден";
            else cout << "Элемент найден на строке #" << result << endl;
        }

		else if (answer == 3) {
            vector <int> *v = tree1.returnFullTree();
            if (v->size()==0) cout << "Дерево пустое";
            else printTree(v);
        }

		else if (answer == 4) {
            cout << "Введите значение удаляемого элемента: ";
            cin >> value;
            result = tree1.removeNode(value);

            if (result == -1) cout << "Дерево пустое";
            else if (result == 0) cout << "Элемент с заданным значением не найден";
            else cout << "Элемент успешно удалён" << endl;
        }

        else goto end;

        cout << "\nВведите 99, чтобы продолжить, номер пункта, чтобы сразу начать работу с ним, и 5, чтобы завершить работу: ";
		cin >> answer;
	}

	while (answer != 5);
    end:
    return 0;
}