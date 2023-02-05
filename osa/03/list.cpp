#include <iostream>
#include <string>
#include <vector>

//ввод и вывод строк на русском
#include <Windows.h>

using namespace std;

struct call { //структура для переговоров: дата и продолжительность
	string date, duration;
};

struct Entry { //структура для записи: имя, число переговоров, массив структур переговоров
	string name;
	int callsNum;
	call* callArr;
	Entry(call* callsArr=NULL, string nm="", int clnm=0) {
		name = nm;
		callsNum = clnm;
		callArr = callsArr;
	}

	string getField(int index, int callsIndex=0) {
		if (index == 1) return name;
		else if (index == 2) return to_string(callsNum);
		else if (index == 3) return callArr[callsIndex].date;
		else if (index == 4) return callArr[callsIndex].duration;
		else return "";
	}

};

bool operator ==(Entry en1, Entry en2) { //оператор сравнения классов для быстрого поиска узла с данными значениями
	if (en1.name == en2.name && en1.callsNum == en2.callsNum) {
		if (en1.callsNum > 0) {
			int counter = 0;
			for (int i=0; i<en1.callsNum; i++) {
				if (en1.callArr[i].date == en2.callArr[i].date && en1.callArr[i].duration == en2.callArr[i].duration) counter++;
			}
			if (counter==en1.callsNum) return true;
			else return false;
		}
		return true;
	}
	return false;
}

struct Node { //структура узла: запись, ссылка на следующую запись, инициация узла
	Entry entry;
	Node* nextNode;
	Node(Entry ent) {
		entry = ent;
		nextNode = NULL;
	};
};

class List {
private:
	Node* root;
	Node* top;
public:
	int nodeCount;
	List() { //0 - создание списка
		root = NULL;
		top = NULL;
		nodeCount = 0;
	}
	
	void addTopNode(Entry ent) { //1 - добавление элемента в конец списка
		Node* nd = new Node(ent);
		if (nodeCount == 0) {
			root = nd;
			top = nd;
			nodeCount++;
		}
		else {
			top->nextNode = nd;
			top = nd;
			nodeCount++;
		}
	}

	void addRootNode(Entry ent) { //2 - добавление элемента в начало списка
		Node* nd = new Node(ent);
		if (nodeCount == 0) {
			root = nd;
			top = nd;
			nodeCount++;
		}
		else {
			nd->nextNode = root;
			root = nd;
			nodeCount++;
		}
	}

	int removeTopNode() { //3 - удаление конечного элемента
		if (top == NULL) return 0;
		else if (root == top) return removeRootNode();

		Node* nd = root;
		while (nd->nextNode != top) nd = nd->nextNode;
		nd->nextNode = NULL;
		delete top;
		top = nd;
		nodeCount--;
		if (nodeCount == 0) {
			top = NULL;
			root = NULL;
		}
		else if (nodeCount == 1) {
			top = root;
		}


		return 1;
	}

	int removeRootNode() { //4 - удаление начального элемента
		if (root == NULL) return 0;
		
		Node* nd = root;
		root = nd->nextNode;
		delete nd;
		nodeCount--;
		if (nodeCount == 0) {
			top = NULL;
			root = NULL;
		}
		else if (nodeCount == 1) {
			top = root;
		}

		return 1;
	}

	Entry findNodeByField(int field, string strval = "") {//5 - поиск элемента с заданным значением поля
		Node* nd = root;
		for (int i = 0; i < nodeCount; i++) {
			if (field == 1 || field == 2) {
				if (nd->entry.getField(field, 0) == strval) return nd->entry;
			}
			else if ((field == 3 || field == 4) && nd->entry.callsNum > 0) {
				for (int j = 0; j < nd->entry.callsNum; j++) {
					//cout << nd->entry.getField(field, j) << "   " << strval<<endl; несущий cout
					if (nd->entry.getField(field, j) == strval) {
						return nd->entry;
					}
				}
			}
			nd = nd->nextNode;
		}
		Entry en;
		en.name = "not found";
		return en;
	}

	void addAfterFoundNode(Entry foundEn, Entry en) { //6 - добавление элемента после найденного
		Node* foundNd = root;
		while (!(foundNd->entry==foundEn)) foundNd = foundNd->nextNode;
		Node* next = foundNd->nextNode;
		Node* addnode = new Node(en);
		foundNd->nextNode = addnode;
		addnode->nextNode = next;
		if (foundNd==top) top=addnode;
		nodeCount++;
	}

	int removeFoundNode(Entry foundEn) { //7 - удаление найденного элемента
		Node* foundNd = root;
		while (!(foundNd->entry==foundEn)) foundNd = foundNd->nextNode;
		if (root == foundNd) return removeRootNode();
		else if (top == foundNd) return removeTopNode();
		else {
			Node* prev = root;
			Node* next = foundNd->nextNode;
			while (prev->nextNode != foundNd) prev = prev->nextNode;
			prev->nextNode = next;
			delete foundNd;
			nodeCount--;
			return 1;
		}
	}

	vector<Entry> returnList() { //вспомогательное для вывода всего списка
		vector<Entry> vec;
		Node* nd = root;
		for (int i = 0; i < nodeCount; i++) {
			vec.push_back(nd->entry);
			nd = nd->nextNode;
		}
		return vec;
	}

};

void printAll(vector<Entry> vec) { //вывод всего списка
	for (int i = 0; i < vec.size(); i++) {
		cout << "\nФИО: " << vec[i].name
			<< "\nКоличество переговоров: " << vec[i].callsNum << endl;
		if (vec[i].callsNum > 0) {
			for (int j = 0; j < vec[i].callsNum; j++) {
				cout << "Дата переговоров #" << j + 1 << ": " << vec[i].callArr[j].date
					<< "\nПродолжительность переговоров #" << j + 1 << ": " << vec[i].callArr[j].duration << endl;
			}
		}
		cout << "-----------------------------------" << endl;
	}
}

Entry fillEntry() { //заполнение данных
	string name, temp;
	int callsNum;
	call* callsArr;
	cin.ignore();
	cout << "Введите ФИО: ";
	getline(cin, name);
	cout << "Введите количество переговоров: ";
	cin >> callsNum;

	if (callsNum > 0) {
		callsArr = new call[callsNum];
		for (int i = 0; i < callsNum; i++) {
			cout << "Дата переговоров #" << i + 1 << ": ";
			cin >> temp;
			callsArr[i].date = temp;
			cout << "Продолжительность переговоров #" << i + 1 << ": ";
			cin >> temp;
			callsArr[i].duration = temp;
		}
	}

	else callsArr = new call[0];

	Entry ent(callsArr, name, callsNum);
	return ent;
};

/*
	Односвязный список.

	Алгоритмы:
		Создание списка
		Добавление элемента в конец списка
		Добавление элемента в начало списка
		Удаление конечного элемента списка
		Удаление начального элемента списка
		Поиск элемента по заданному значению поля структуры
		Добавление элемента после найденного
		Удаление найденного элемента.

	Использовать указатели

	Вариант 12. Фамилия И.О., количество переговоров (для каждого - дата и продолжительность).
*/

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int ans=-1, callsNum, field, findInt=0;
	string name, findStr="";
	List list;
	
	do {
		start:
		while (ans < 1 || ans > 6) {
			cout << "\nКакое действие со списком вы хотите совершить?"
				<< "\n1. Добавить элемент в конец"
				<< "\n2. Добавить элемент в начало"
				<< "\n3. Удалить конечный элемент"
				<< "\n4. Удалить начальный элемент"
				<< "\n5. Найти элемент по заданному значению поля структуры"
				<< "\n6. Завершить работу"
				<< endl;
			cin >> ans;
		}

		if (ans == 1) {
			list.addTopNode(fillEntry());
			printAll(list.returnList());
		}

		else if (ans == 2) {
			list.addRootNode(fillEntry());
			printAll(list.returnList());
		}

		else if (ans == 3) {
			int result = list.removeTopNode();
			if (result == 1) cout << "Конечный элемент успешно удалён" << endl;
			else if (result == 0) cout << "Конечный элемент не удалён: список пуст" << endl;
			else cout << "Ошибка удаления элемента" << endl;
		}

		else if (ans == 4) {
			int result = list.removeRootNode();
			if (result == 1) cout << "Начальный элемент успешно удалён" << endl;
			else if (result == 0) cout << "Начальный элемент не удалён: список пуст" << endl;
			else cout << "Ошибка удаления элемента" << endl;
			
		}

		else if (ans == 5) {
			cout << "Введите номер необходимого поля структуры: "
				<< "\n1. ФИО"
				<< "\n2. Количество переговоров"
				<< "\n3. Дата переговоров"
				<< "\n4. Продолжительность переговоров" << endl;

			cin >> field;
			cin.ignore();
			cout << "Введите искомое значение: ";
			getline(cin, findStr);

			Entry nd = list.findNodeByField(field, findStr);
			
			if (nd.name!="not found") {
				cout << "\nФИО: " << nd.name
					<< "\nКоличество переговоров: " << nd.callsNum << endl;
				if (nd.callsNum > 0) {
					for (int j = 0; j < nd.callsNum; j++) {
						cout << "Дата переговоров #" << j + 1 << ": " << nd.callArr[j].date
							<< "\nПродолжительность переговоров #" << j + 1 << ": " << nd.callArr[j].duration << endl;
					}
				}

				do {
					cout << "\nВы можете совершить следующие действия: "
						<< "\n7. Добавить элемент после найденного"
						<< "\n8. Удалить найденный элемент"
						<< "\n9. Вернуться к списку основных действий"
						<< "\n0. Завершить работу" << endl;
					cin >> ans;
				}

				while ((ans < 7 && ans!=0) || ans > 9);

				if (ans == 7) {
					list.addAfterFoundNode(nd, fillEntry());
					cout << "Элемент успешно добавлен" << endl;
					printAll(list.returnList());

				}

				else if (ans == 8) {
					int res = list.removeFoundNode(nd);
					if (res) cout << "Найденный элемент удалён" << endl;
					printAll(list.returnList());
				}

				else if (ans == 9) goto start; //кто-то открыл для себя goto

				else goto end; //и будет этим немножко злоупотреблять

			}
			else cout << "Элемент с заданным значением поля не найден" << endl;
		}

		else goto end; //или множко

		cout << "\nВведите 99, чтобы продолжить, номер пункта, чтобы сразу начать работу с ним, и 0, чтобы завершить работу: ";
		cin >> ans;
	}

	while (ans != 0);
	end:
	return 0;
}