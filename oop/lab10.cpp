#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class publication { //1+2 - публикация
private:
    string title;
    float price;
public:
    virtual void getdata() {
        cout << "Введите название: ";
        cin >> title;
        cout << "Введите цену: ";
        cin >> price;
    }
    virtual void putdata() {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << endl;
    }
    // 5 - превышение размера
    virtual bool isOversize() const = 0;
};

class book : public publication { //1+2 - книга
private:
    int pages;
public:
    void getdata() {
        publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
    }
    void putdata() {
        publication::putdata();
        cout << "Количество страниц: " << pages << endl;
    }
    // 5 - превышение размера
    bool isOversize() const {
        if (pages > 800) return true;
        else return false;
    }
};

class tape : public publication { // 1+2 - кассета
private:
    float time;
public:
    void getdata() {
        publication::getdata();
        cout << "Введите время записи книги в минутах: ";
        cin >> time;
    }
    void putdata() {
        publication::putdata();
        cout << "Время записи книги в минутах: " << time << endl;
    }
    // 5 - превышение размера
    bool isOversize() const {
        if (time > 90) return true;
        else return false;
    }

};

class Distance { // 3 - расстояние
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }
    Distance(int ft, float in) : feet(ft), inches(in) { }
    Distance(double flfit) {
        feet = static_cast<int>(flfit);
        inches = 12 * (flfit - feet);
    }

    void showdist() {
        cout << feet << "\'" << inches << '\"';
    }

    friend float square(Distance d) {
        float fltfeet = d.feet + d.inches / 12;
        float feetsqrd = fltfeet * fltfeet;
        return feetsqrd;
    }

    friend Distance operator* (Distance d1, Distance d2) {
        float fltfeet1 = (d1.feet * 12) + d1.inches;
        float fltfeet2 = (d2.feet * 12) + d2.inches;
        float multfeet = (fltfeet1 * fltfeet2)/12;
        return Distance(multfeet);
    }
};

class Array { // 4 - массив
private:
    int* ptr;
    int size;
public:
    Array(int s) {
        size = s;
        ptr = new int[s];
    }

    Array(Array& a) {
        size = a.size;
        ptr = new int[size];
        for (int j = 0; j < size; j++)
            *(ptr + j) = *(a.ptr + j);
    };

    ~Array() {
        delete[] ptr;
    }

    int& operator[](int j) {
        return *(ptr + j);
    }

    Array& operator=(Array& a) {
        delete[] ptr;
        size = a.size;
        ptr = new int[a.size];
        for (int j = 0; j < a.size; j++)
            *(ptr + j) = *(a.ptr + j);
        return *this;
    }
};

class BMoney { // 6 - деньги
private:
    long double money;
    string kon;
public:
    BMoney() {
        money = 0.0;
    }
    explicit BMoney(long double n) : money(n) { }
    void getmoney() {
        cout << "Введите число в формате $123,456,789.00: ";
        cin.ignore();
        getline(cin, kon);
    }
    void Idtoms() {
        string dollar = "";
        string falcon = "0 000 000 000 000 000.00";
        dollar += to_string(money);
        int n;
        for (int i = 0; i < dollar.length(); i++) {
            if (dollar[i] == ',') {
                n = i;
                break;
            }
        }
        for (int i = n; i < dollar.length(); i++) {
            dollar.pop_back();
        }
        int j = dollar.length() - 1;
        for (int i = falcon.length() - 1; i > -1; i--) {
            if (j != -1) {
                if (falcon[i] != ' ')
                    falcon[i] = dollar[j];
                else {
                    i--;
                    falcon[i] = dollar[j];
                }
                j--;
            }
            else
                break;
        }
        kon = "$";
        for (int i = 0; i < falcon.length(); i++) {
            if (falcon[i] == ' ' || falcon[i] == '0')
                continue;
            else {
                j = i;
                break;
            }
        }
        for (int i = j; i < falcon.length(); i++) {
            kon.push_back(falcon[i]);
        }
        kon.push_back('\0');
    }
    void mstold() {
        int n = 0;
        string nok;
        for (int i = 0; i < kon.length(); i++) {
            if (kon[i] != ',')
                nok.push_back(kon[i]);
            money = stold(nok);
            if (kon[i] == '.') {
                n = i;
                break;
            }
        }
        long double N;
        nok.clear();
        for (int i = n + 1; i < kon.length(); i++) {
            nok.push_back(kon[i]);
        }
        N = stold(nok);
        money = money + N / 100;
        nok.clear();
    }
    void display() {
        cout << kon << endl;
    }
    BMoney operator+ (BMoney x) {
        BMoney y;
        y.money = money + x.money;
        return(y);
    }
    BMoney operator- (BMoney x) {
        BMoney y;
        y.money = abs(money - x.money);
        return(y);
    }
    BMoney operator* (long double x) {
        BMoney y;
        y.money = money * x;
        return(y);
    }
    long double operator/ (BMoney x) {
        long double t;
        t = money / x.money;
        return (t);
    }
    BMoney operator/ (long double x) {
        BMoney y;
        y.money = money / x;
        return(y);
    }
    friend BMoney operator* (long double n, BMoney m) {
        return BMoney(n * m.money);
    };
    friend long double operator/ (long double n, BMoney m) {
        return (n / m.money);
    };
    // 7 - округление денег
    friend BMoney round(BMoney m) {
        long double i, f;
        f = modfl(m.money, &i);
        if (f < 0.50) return BMoney(i);
        else return BMoney(i + 1.0);
    }

};

class token { // 8 - вычисления дробей и рациональных чисел
public:
	virtual float getNumber() const = 0;
	virtual char getOperator() const = 0;
};

class OPerator : public token { // 8 - вычисления дробей и рациональных чисел
private:
	char oper;
public:
	OPerator(char op) : oper(op) { }
	char getOperator() const {
		return oper;
	}
	float getNumber() const {
		return 0.0;
	}
};

class number : public token { // 8 - вычисления дробей и рациональных чисел
private:
	float fnum;
public:
	number(float n) : fnum(n) { }
	float getNumber() const {
		return fnum;
	}
	char getOperator() const {
		return '0';
	}
};

class stack { // 8 - вычисления дробей и рациональных чисел
private:
	token* atoken[100];
	int top;
public:
	stack() {
		top = 0;
	}
	void push(token* var) {
		atoken[++top] = var;
	}
	token* pop() {
		return atoken[top--];
	}
	int gettop() const {
		return top;
	}
	bool isNumber() const {
		number* pNum;
		if (pNum = dynamic_cast<number*>(atoken[top]))
			return true;
		else
			return false;
	}
};

struct link { // 10 - указатели
	int data;
	link* next;
};

class linklist { // 10 - указатели
private:
	link* first;
public:
	linklist() {
		first = NULL;
	}
	~linklist() {
		link* current = first;
		while (current != NULL) {
			first = current->next;
			delete current;
			cout << "Элемент списка удалён." << endl;
			current = first;
		}
	};
	linklist(linklist& li) {
		link* current = li.first;
		while (current) {
			additem(current->data);
			current = current->next;
		}
	}
	void additem(int d) {
		link* newlink = new link;
		newlink->data = d;
		newlink->next = first;
		first = newlink;
	};
	void display() {
		link* current = first;
		while (current != NULL) {
			cout << current->data << endl;
			current = current->next;
		}
	};
	linklist& operator= (linklist& li) {
		if (this == &li)
			return *this;
		link* current = first;
		while (current) {
			first = current->next;
			delete current;
			current = first;
		}
		current = li.first;
		while (current) {
			additem(current->data);
			current = current->next;
		}
		return *this;
	}
};

// 11 - анализ чисел с плавающей запятой
const int LEN = 80;
const int MAX = 40;
class Token { // 11 - анализ чисел с плавающей запятой
public:
	virtual float getNumber() const = 0;
	virtual char getOperator() const = 0;
};

class Operator : public Token { // 11 - анализ чисел с плавающей запятой
private:
	char oper;
public:
	Operator(char op) : oper(op) { }
	char getOperator() const {
		return oper;
	}
	float getNumber() const {
		return 0.0f;
	}
};

class Number : public Token { // 11 - анализ чисел с плавающей запятой
private:
	float fnum;
public:
	Number(float n) : fnum(n) { }
	float getNumber() const {
		return fnum;
	}
	char getOperator() const {
		return '0';
	}
};

class Stack { // 11 - анализ чисел с плавающей запятой
private:
	Token* atoken[MAX];
	int top;
public:
	Stack() {
		top = 0;
	}
	void push(Token* var) {
		atoken[++top] = var;
	}
	Token* pop() {
		return atoken[top--];
	}
	int gettop() {
		return top;
	}
	bool isNumber() const {
		Number* pNum;
		if (pNum = dynamic_cast<Number*>(atoken[top]))
			return true;
		else
			return false;
	}
};

class express { // 11 - анализ чисел с плавающей запятой
private:
	Stack s;
	char* pStr;
	int len;
public:
	express(char* ptr) {
		pStr = ptr;
		len = strlen(pStr);
	}
	void parse() {
		char ch;
		Token* lastval;
		Token* lastop;
		float ans;
		Number* ptrN;
		Operator* ptrO;
		char* pCurrent = pStr;
		while (pCurrent[0]) {
			ch = pCurrent[0];
			if (ch >= '0' && ch <= '9') {
				ans = strtof(pCurrent, &pCurrent);
				pCurrent++;
				float st = 0.1;
				float rod;
				if (pCurrent[0] == '0')
					st *= 0.1;
				rod = strtof(pCurrent, &pCurrent);
				float chislo = rod;
				float razryd = 1;
				while (chislo > 9) {
					chislo /= 10;
					razryd++;
				}
				ans += rod * pow(st, razryd);
				ptrN = new Number(ans);
				s.push(ptrN);
			}
			else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
				if (s.gettop() == 1) {
					ptrO = new Operator(ch);
					s.push(ptrO);
				}
				else {
					lastval = s.pop();
					lastop = s.pop();
					if ((ch == '*' || ch == '/') && (lastop->getOperator() == '+' || lastop->getOperator() == '-')) {
						s.push(lastop);
						s.push(lastval);
					}
					else {
						switch (lastop->getOperator()) {
						case '+':
							ans = s.pop()->getNumber() + lastval->getNumber();
							ptrN = new Number(ans);
							s.push(ptrN);
							break;
						case '-':
							ans = s.pop()->getNumber() - lastval->getNumber();
							ptrN = new Number(ans);
							s.push(ptrN);
							break;
						case '*':
							ans = s.pop()->getNumber() * lastval->getNumber();
							ptrN = new Number(ans);
							s.push(ptrN);
							break;
						case '/':
							ans = s.pop()->getNumber() / lastval->getNumber();
							ptrN = new Number(ans);
							s.push(ptrN);
							break;
						default:
							cout << "\nНеизвестный знак операции\n";
							exit(1);
						}
					}
					Operator* ptrO = new Operator(ch);
					s.push(ptrO);
				}
				pCurrent++;
			}
			else {
				cout << "Неразрешенный символ в арифметическом выражении\n";
				exit(1);
			}
		}
	}
	float solve() {
		Token* lastval;
		float ans;
		Number* ptrN;
		while (s.gettop() > 1) {
			lastval = s.pop();
			switch (s.pop()->getOperator()) {
			case '+':
				ans = s.pop()->getNumber() + lastval->getNumber();
				ptrN = new Number(ans);
				s.push(ptrN);
				break;
			case '-':
				ans = s.pop()->getNumber() - lastval->getNumber();
				ptrN = new Number(ans);
				s.push(ptrN);
				break;
			case '*':
				ans = s.pop()->getNumber() * lastval->getNumber();
				ptrN = new Number(ans);
				s.push(ptrN);
				break;
			case '/':
				ans = s.pop()->getNumber() / lastval->getNumber();
				ptrN = new Number(ans);
				s.push(ptrN);
				break;
			default:
				cout << "\nНеизвестный оператор";
				exit(1);
			}
		}
		return s.pop()->getNumber();
	}
};

int main()
{
    setlocale(LC_ALL, "Russian");
    
    cout << R"(1. Пусть имеется та же издательская компания, которая описана в упражнении 1 лабораторной работы по наследованию, которая
продает и книги, и аудио версии печатной продукции. Как и в том упражнении, создайте класс publication, хранящий
название (фактически, строку) и цену (типа float) публикации. Создайте два порожденных класса: book, в котором
происходит изменение счетчика страниц (типа int), и tape, в котором происходит изменение счетчика записанных на
кассету минут. Каждый из классов должен иметь метод getdata(), запрашивающий информацию у пользователя, и
putdata() для вывода данных на экран. 
+
2. Напишите main(), где создавался бы массив указателей на класс publication. В цикле запрашивайте у пользователя
данные о конкретной книге или кассете, используйте new для создания нового объекта book или tape. Сопоставляйте
указатель в массиве с объектом. Когда пользователь закончит ввод исходных данных, выведите результат для всех
введенных книг и кассет, используя цикл for и единственное выражение. )" << endl;
    
    publication* publarr[100]{};
    int n = 0;

    do {
        cout << "Ввести данные книги или пленки?b,t: ";
        cin.get();

        if (cin.get() == 'b') publarr[n] = new book;
        else publarr[n] = new tape;

        publarr[n++]->getdata();
        cout << "Ввести данные другой публикации?y,n: ";
        cin.get();
    } while (cin.get()=='y');

    for (int j = 0; j < n; j++) publarr[j]->putdata();
    
    cout << "\n" << R"(3. В классе Distance, как показано в примерах ниже, создайте перегружаемую операцию умножения *, чтобы можно было
умножать два расстояния. Сделайте эту функцию дружественной, тогда можно будет использовать выражение типа
Wdist = 7.5 * dist2. Вам понадобится конструктор с одним аргументом для перевода величин из формата чисел с
плавающей запятой в формат Distance. Напишите какой-либо main() на свое усмотрение для того, чтобы несколькими
способами проверить работу этой перегружаемой операции. )" << endl;

    Distance dist1(3, 6.0);
    Distance dist2(2, 3.0);
    Distance dist3;
    cout << "Расстояние 1: ";
    dist1.showdist();
    cout << "\nРасстояние 2: ";
    dist2.showdist();
    cout << "\nРасстояние 1*2: ";
    dist3 = dist1 * dist2;
    dist3.showdist();
    cout << "\nРасстояние 1*2*10: ";
    dist3 = 10.0 * dist3;
    dist3.showdist();
    cout << endl;
    
    cout << "\n" << R"(4. Как уже говорилось, классы можно заставлять вести себя как массивы. Пример ниже показывает один из способов
создания такого класса. Взяв за основу приведенную программу, добавьте перегружаемое присваивание и перегружаемый
конструктор копирования к классу Array. Затем добавьте к main() выражение Array arr2(arrl); и arr3=arrl; для
проверки того, что перегружаемые операции работают. Конструктор копирования должен создать новый объект Array со
своим собственным местом в памяти, выделенным для хранения элементов массива. И конструктор копирования, и оператор
присваивания должны копировать содержимое старого объекта класса Array в новый. )" << endl;
    
    const int ASIZE = 10;
    Array arr1(ASIZE);

    for (int j = 0; j < ASIZE; j++) arr1[j] = j * j * 3;

    Array arr2(arr1);
    Array arr3 = arr2;

    for (int j = 0; j < ASIZE; j++) cout << arr1[j] << ' ';
    cout << endl;
    for (int j = 0; j < ASIZE; j++) cout << arr2[j] << ' ';
    cout << endl;
    for (int j = 0; j < ASIZE; j++) cout << arr3[j] << ' ';
    cout << endl;
    
    cout << "\n" << R"(5. Взяв за основу программу из упражнения 1 этой лабораторной, добавьте метод типа bool, называющийся isOveersize(),
к классам book и tape. Допустим, книга, в которой больше 800 страниц, или кассета со временем проигрывания более
90 минут, будут считаться объектами с превышением размера. К этой функции можно обращаться из main(), а результат
ее работы выводить в виде строки «Превышение размера!» для соответствующих книг и кассет. Допустим, объекты
классов book и tape должны быть доступны через указатели на них, хранящиеся в массиве типа publication. )" << endl;

    publication* pubPtr[100]{};
    n = 0;

    do {
        cout << "Ввести данные книги или пленки?b,t: ";
        cin.get();

        if (cin.get() == 'b') pubPtr[n] = new book;
        else pubPtr[n] = new tape;

        pubPtr[n++]->getdata();
        cout << "Ввести данные другой публикации?y,n: ";
        cin.get();
    } while (cin.get() == 'y');

    for (int j = 0; j < n; j++) {
        pubPtr[j]->putdata();
        if (pubPtr[j]->isOversize()) cout << "Размер публикации превышает лимиты."<< endl;
        else cout << endl;
    }
    
    cout << "\n" << R"(6. Возьмите за основу программу из упражнения 8 лабораторной про перегрузку операций, где было перегружено пять
арифметических операций для работы с денежным форматом. Добавьте два оператора, которые не были перегружены 
в том упражнении: long double * bМопеу //умножать число на деньги
long double / bМопеу //делить число на деньги 
Эти операции требуют наличия дружественных функций, так как справа от оператора находится объект, а слева — 
обычное число. Убедитесь, что main() позволяет пользователю ввести две денежные строки и число с плавающей запятой,
а затем корректно выполняет все семь арифметических действий с соответствующими парами значений. )" << endl;

    BMoney m1, m2, mres;
    long double num, res;
    m1.getmoney();
    m1.mstold();
    m2.getmoney();
    m2.mstold();
    cout << "Введите вещественное число: ";
    cin >> num;
    mres = m1 + m2;
    mres.Idtoms();
    mres.display();
    mres = m1 - m2;
    mres.Idtoms();
    mres.display();
    mres = m1 * num;
    mres.Idtoms();
    mres.display();
    res = m1 / m2;
    cout << res << endl;
    mres = m1 / num;
    mres.Idtoms();
    mres.display();
    mres = num * m1;
    mres.Idtoms();
    mres.display();
    res = num / m1;
    cout << res << endl;
    
    cout << "\n" << R"(7. Как и в предыдущем упражнении, возьмите за основу программу из упражнения 8 лабораторной по перегрузке операций.
На этот раз от вас требуется добавить функцию, округляющую значение bМопеу до ближайшего доллара: mo2 = round(mol); 
Как известно, значения, не превышающие $0.49, округляются вниз, а числа от $0.50 и более округляются вверх. Можно
использовать библиотечную функцию modfl(): Она разбивает переменную типа long double на целую и дробную части.
Если дробная часть меньше 0.50, функция просто возвращает целую часть числа. В противном случае возвращается
увеличенная на 1 целая часть. В main() проверьте работоспособность функции путем передачи в нее последовательно
значений, одни из которых меньше $0.49, другие — больше $0.50. )" << endl;

    BMoney mo1, mo2;
    mo1.getmoney();
    mo1.mstold();
    mo2 = round(mo1);
    mo2.Idtoms();
    mo2.display();
    
    cout << "\n" << R"(8. Помните программу по вычислению математических выражений с дробями из предыдущей лабораторной работы?
Попробуйте доработать ее, чтобы она могла вычислять значения математических выражений с рациональными числами,
например типа float, а не только с одноразрядными числами: 3.14159 / 2.0 + 75.25 * 3,333 + 6.02 Во-первых, нужно
развить стек до такой степени, чтобы он мог хранить и операторы (типа char), и числа (типа float). Но как,
спрашивается, можно хранить в стеке значения двух разных типов? Ведь стек — это, по сути дела, массив. Надо еще
учесть, что типы char и float даже не совпадают по размеру! Даже указатели на разные типы данных (char* и float*)
компилятор не позволит хранить в одном массиве, несмотря на то, что они одинакового размера. Единственный способ
хранить в массиве два разных типа указателей — сделать эти типы наследниками одного и того же базового класса.
При этом базовому классу даже нет нужды иметь какие-то собственные данные, это может быть абстрактный класс,
из которого никакие объекты создаваться не будут. )" << endl;

	stack s;
	number n1(3.14159), n2(2.0), n3(75.25), n4(3.333), n5(6.02);
	OPerator plus('+'), mult('*'), minus('-'), div('/');
	s.push(&n1);
	s.push(&div);
	s.push(&n2);
	s.push(&plus);
	s.push(&n3);
	s.push(&mult);
	s.push(&n4);
	s.push(&plus);
	s.push(&n5);

	while (s.gettop() > 0) {
		if (s.isNumber()) cout << s.pop()->getNumber();
		else cout << s.pop()->getOperator();
	}
	cout << endl;
	
		cout << "\n" << R"(Задание 9 в отдельном файле.)" << endl;
	
	cout << "\n" << R"(10. Упражнение 4 в главе про перегрузку операций включало в себя добавление к классу Linklist перегружаемого
деструктора. Допустим, мы заполняем объект этого класса данными, а затем присваиваем один класс целиком другому,
используя стандартный оператор присваивания: list2 = listl; Допустим, что впоследствии мы удалим объект класса
Listl. Можем ли мы все еще использовать list2 для доступа к введенным данным? Увы, нет, так как при удалении listl
все его ссылки были удалены. Единственное, что было известно объекту linklist про удаленный объект, это указатель
на него. Но его удалили, указатель в List2 стал недееспособным, и все попытки получить доступ к данным приведут к
получению мусора вместо данных, а в худшем случае — к зависанию программы. Один из способов избежать этих проблем
 — перегрузить оператор присваивания, чтобы он вместе с объектом копировал бы все его ссылки. Но тогда придется
пройти по всей цепочке, поочередно копируя все ссылки. Как отмечалось ранее, следует также перегружать конструктор
копирования. Чтобы была возможность удалять объекты linklist в main(), можно создавать их с помощью указателя и new.
В таком случае проще будет проверять работу новых операций. Не переживайте, если обнаружите, что в процессе
копирования порядок следования данных изменился. )" << endl;
	
	linklist* list1 = new linklist;
	list1->additem(11);
	list1->additem(26);
	list1->additem(47);
	list1->additem(85);
	list1->display();
	linklist list2(*list1);
	linklist list3;
	list3 = *list1;
	delete list1;
	list2.display();
	list3.display();
	
	cout << "\n" << R"(11. Выполните изменения в предложенной программе соответствии с упражнением 7. То есть заставьте программу
анализировать выражения, содержащие числа в формате с плавающей запятой. Совместите классы, предложенные в
упражнении 7, с алгоритмами из программы, приведённой ниже. Вам придется работать с указателями на символы вместо
работы с самими символами.)" << endl;

	char string[LEN];
	cout << "Введите выражение: ";
	ws(cin);
	cin.get(string, LEN);
	express* eptr = new express(string);
	eptr->parse();
	cout << "Результат вычисления выражения: " << eptr->solve();
	delete eptr;



    return 0;
}
