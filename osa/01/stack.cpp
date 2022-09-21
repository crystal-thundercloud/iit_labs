#include <iostream>
using namespace std;

class stack {
private:
	int* st;
	//int* head;
	int size;
	int headnum;
public:
	stack(int sz=1) {
		st = new int[sz];
		//head = &st[0];
		headnum = 0;
		size = sz;
	}

	bool push(int el) {
		if (headnum < size) {
			st[headnum] = el;
			headnum++;
			return true;
		}
		else return false;
	}

	int pop() {
		if (headnum > 0) {
			int el = st[headnum-1];
			st[headnum-1] = 0;
			headnum--;
			return el;
		}
		else return 5329987;
	}
};

/*
    Стек 

    Необходимо разработать программу, реализующую работу со стеком.

    Программа должна содержать функции:
        вставки
        извлечения

    Необходимо предусмотреть: 
        контроль на переполнение
        контроль на отсутствие элементов
        отображение на экране значения извлекаемого элемента
*/

int main() {
	//setlocale(LC_ALL, "Russian");
	int n, l, k;
	bool bl;

	do {
		cout << "Vvedite razmer stecka (>0): ";
		cin >> n;
	} while (n < 0);

	do {
		cout << "Vvedite kolichestvo popytok zapolnit ili ochistit steck (>0): ";
		cin >> l;
	} while (l < 0);

	stack st(n);

	cout << "Zapolnite steck elementami" << endl;
	for (int i = 0; i < l; i++) {
		cout << "element ";
		cin >> n;
		bl = st.push(n);
		if (bl) cout << "yspeshno dobavlen"<<endl;
		else cout << "ne dobavlen: steck perepolnen"<<endl;
	}

	cout << "\nOchistka stecka:" << endl;
	for (int i = 0; i < l; i++) {
		k = st.pop();
		if (k!= 5329987) cout << "element " << k << " ydalen" << endl;
		else cout << "dostignyt konec steka" << endl;
	}

	cout << "\nZapolnenie posle ochistki (/2):" << endl;
	for (int i = 0; i < l/2; i++) {
		int r = rand();
		bl = st.push(r);
		if (bl) cout << "element " << r << " yspeshno dobavlen" << endl;
		else cout << "ne dobavlen: steck perepolnen" << endl;
	}

	cout << "\nYdalenie (/2):" << endl;
	for (int i = 0; i < l / 2; i++) {
		k = st.pop();
		if (k != 5329987) cout << "element " << k << " ydalen" << endl;
		else cout << "dostignyt konec steka" << endl;
	}
	
    return 0;
}
