#include <iostream>
using namespace std;

class queue {
private:
	int* qu;
	int size;
	int headnum;
	int tailnum;
	bool fullqu;
public:
	queue(int sz = 1) {
		qu = new int[sz];
		headnum = 0;
		tailnum = 0;
		size = sz;
		fullqu = false;
	}

	bool push(int el) {
		if (fullqu == false) {
			if (headnum >= 0 && headnum <= tailnum) {
				if (tailnum < size) {
					qu[tailnum] = el;
					tailnum++;
					return true;
				}
				else if (headnum == 0) {
					fullqu = true;
					return false;
				}

				else {
					tailnum = 0;
				}
			}

			else if (headnum > 0 && headnum >= tailnum) {
				if (tailnum < headnum) {
					qu[tailnum] = el;
					tailnum++;
					return true;
				}

				else {
					fullqu = true;
					return false;
				}
			}
		}

		else return false;
		
	}

	int pop() {
		if (headnum >= 0 && headnum <= tailnum) {
			if (headnum < tailnum) {
				int el = qu[headnum];
				qu[headnum] = 0;
				headnum++;
				return el;
			}

			else {
				fullqu = false;
				return 5329987;
			}
		}

		else if (headnum > 0 && headnum >= tailnum) {
			if (headnum < size) {
				int el = qu[headnum];
				qu[headnum] = 0;
				headnum++;
				return el;
			}

			else if (tailnum > 0) headnum = 0;

			else {
				fullqu = false;
				return 5329987;
			}
		}

		else return 5329987;
	}
};
/*
    Очередь.

    Необходимо разработать программу, реализующую работу с очередью.

    Программа должна содержать функции:
        вставки
        извлечения

    Необходимо предусмотреть: 
        контроль на переполнение
        контроль на отсутствие элементов
        отображение на экране значения извлекаемого элемента
*/

int main() {
	int n, l, k;
	bool bl;

	do {
		cout << "Vvedite razmer ocheredi (>0): ";
		cin >> n;
	} while (n < 0);

	do {
		cout << "Vvedite kolichestvo popytok zapolnit ili ochistit ochered (>0): ";
		cin >> l;
	} while (l < 0);

	queue qu(n);

	cout << "Zapolnite ochered elementami" << endl;
	for (int i = 0; i < l; i++) {
		cout << "element ";
		cin >> n;
		bl = qu.push(n);
		if (bl) cout << "yspeshno dobavlen" << endl;
		else cout << "ne dobavlen: ochered perepolnena" << endl;
	}

	cout << "\nOchistka ocheredi:" << endl;
	for (int i = 0; i < l; i++) {
		k = qu.pop();
		if (k != 5329987) cout << "element " << k << " ydalen" << endl;
		else cout << "ochered pysta" << endl;
	}

	cout << "\nZapolnenie posle ochistki (/2):" << endl;
	for (int i = 0; i < l / 2; i++) {
		int r = rand();
		bl = qu.push(r);
		if (bl) cout << "element " << r << " yspeshno dobavlen" << endl;
		else cout << "ne dobavlen: ochered perepolnena" << endl;
	}

	cout << "\nOchistka ocheredi:" << endl;
	for (int i = 0; i < l; i++) {
		k = qu.pop();
		if (k != 5329987) cout << "element " << k << " ydalen" << endl;
		else cout << "ochered pysta" << endl;
	}

    return 0;
}
