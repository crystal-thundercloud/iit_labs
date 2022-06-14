#include <iostream>
#include <cstring>
#include <math.h>
#include <iomanip>

using namespace std;

class publication { // 1 - публикация
private:
    string title;
    float price;
public:
    void getdata() {
        cout << "Название: ";
        cin >> title;
        cout << "Цена: ";
        cin >> price;
    }
    void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << endl;
    }
};

class sales { // 3 - продажи книг
private:
    float sell[3];
public:
    void getdata() {
        cout << "Введите выручку от продаж за 3 месяца через пробел: ";
        cin >> sell[0] >> sell[1] >> sell[2];
    }
    void putdata() const {
        cout << "Выручка от продаж за последние 3 месяца: " << sell[0] << " " << sell[1] << " " << sell[2] << endl;
    }
};

class book : public publication, public sales { // 1 - книга
private:
    int pages;
public:
    void getdata() {
        publication::getdata();
        cout << "Количество страниц: ";
        cin >> pages;
        sales::getdata(); // 3 - продажи
    }
    void putdata() const {
        publication::putdata();
        cout << "Количество страниц: " << pages << endl;
        sales::putdata(); // 3 - продажи
    }
};

class tape : public publication, public sales { // 1 - аудиокнига
private:
    float time;
public:
    void getdata() {
        publication::getdata();
        cout << "Время записи книги в минутах: ";
        cin >> time;
        sales::getdata(); // 3 - продажи
    }
    void putdata() {
        publication::putdata();
        cout << "Время записи книги в минутах: " << time<<endl;
        sales::putdata(); // 3 - продажи
    }
};

class String { // 2 - строка защищённая
protected:
    static const int SZ = 80;
    char str[SZ];
public:
    String() { str[0] = '\0'; }
    void display()const {
        cout << str << endl;
    }
    String(char s[]) {
        strcpy_s(str, s);
    }
    operator const char* () {
        return str;
    }
};

class Pstring : public String { // 2 - строка защищённая
public:
    Pstring() : String() {}
    Pstring(const char s[]) {
        if (strlen(s) < SZ) strcpy_s(str, s);
        else {
            int i;
            for (i = 0; i < SZ - 1; i++)
                str[i] = s[i];
            str[i] = '\0';
        }
    }
};

class disk : private publication, private sales { // 4 - диски
private:
    float time;
    int pages;
    char choose;
public:
    void getdata() {
        cout << "Введите тип диска (c - CD, d - DVD): ";
        cin >> choose;
        if (choose == 'c') {
            publication::getdata();
            cout << "Введите время аудиозаписи книги в минутах: ";
            cin >> time;
            sales::getdata();
        }
        else {
            publication::getdata();
            cout << "Введите количество отсканированных страниц книги: ";
            cin >> pages;
            sales::getdata();
        }
    }
    void putdata() const {
        if (choose == 'c') {
            publication::putdata();
            cout << "Время записи книги на CD в минутах: " << time << endl;
            sales::putdata();
        }
        else {
            publication::putdata();
            cout << "Количество отсканированных страниц на DVD: " << pages << endl;
            sales::putdata();
        }
    }
};

const int LEN = 80; // 5 - сотрудник
class Employee {
private:
    char name[LEN];
    unsigned long number;
public:
    void getdata()
    {
        cout << "Введите фамилию: ";
        cin >> name;
        cout << "Введите номер: №";
        cin >> number;
    }
    void putdata() const
    {
        cout << "Фамилия: " << name << endl;
        cout << "Номер: " << number << endl;
    }
};

class employee2 : public Employee { // 5 - сотрудник
private:
    double compensation;
    enum period {
        hourly,
        weekly,
        monthly
    };
    int how;
public:
    void getdata() {
        Employee::getdata();
        cout << "Введите период выплат ('h' hourly, 'w' еженедельная, 'm' ежемесячная): ";
        char ch;
        cin >> ch;
        how = (ch == 'h') ? hourly : ((ch=='w')? weekly : monthly);
        cout << "Введите сумму вознаграждения: ";
        cin >> compensation;
    }
    void putdata() {
        Employee::putdata();
        string howstr = (how==hourly)? "почасовая" : ((how==weekly)? "еженедельная" : "ежемесячная");
        cout << "Период выплат: " << howstr << endl;
        cout << "Сумма вознаграждения: " << compensation << endl;
    }
};

const int LIMIT = 80;
class safearray {
private:
    int arr[LIMIT];
public:
    int& operator[](int n) {
        if (n < 0 || n >= LIMIT) {
            cout << "   Ошибочный индекс!";
            exit(1);
        }
        return arr[n];
    }
};

class safe : public safearray { // 6 - безопасный массив
private:
    int lower;
    int upper;
public:
    safe(int low, int up) : lower(low), upper(up) {
        if (lower > upper) {
            cout << "Верхняя граница индекса массива меньше нижней.\n";
            exit(1);
        }
        if (upper - lower >= LIMIT) {
            cout << "В массиве не может быть больше " << LIMIT << " элементов.\n";
            exit(1);
        }
    }
    int& operator[] (int n) {
        if (n < lower || n > upper) {
            cout << "Неверный индекс.";
            exit(1);
        }
        return safearray::operator[] (n - lower);
    }
};

class Counter { // 7 - счётчик
protected:
    unsigned int count;
public:
    Counter() : count(0) { }
    Counter(int c) : count(c) { }
    unsigned int get_count() const {
        return count;
    }
    Counter operator++() {
        return Counter(++count);
    }
    Counter operator++(int) {
        return Counter(count++);
    }
};

class CountDn : public Counter { // 7 - счётчик
public:
    Counter operator--() {
        return Counter(--count);
    }
    Counter operator--(int) {
        return Counter(count--);
    }
};

class Pstring2 : public Pstring { // 8 - строки 2
public:
    Pstring2() : Pstring() {}
    Pstring2(const char s[]) : Pstring(s) {}
    Pstring2 left(Pstring2 source, unsigned int n) {
        int i;
        for (i = 0; i < n; i++)
            str[i] = source[i];
        str[i] = '\0';
        return Pstring2(str);
    }
    Pstring2 mid(Pstring2 source, unsigned int pos, unsigned int n) {
        int j = 0;
        for (int i = pos; i < pos + n; i++) str[j++] = source[i];
        str[j] = '\0';
        return Pstring2(str);
    }
    Pstring2 right(Pstring2 source, unsigned int n) {
        int j = 0;
        for (int i = strlen(source) - n; i < strlen(source); i++) str[j++] = source[i];
        str[j] = '\0';
        return Pstring2(str);
    }
};

class publication2 : public publication { // 9 - публикация + дата
private:
    int month;
    int day;
    int year;
public:
    void getdata() {
        publication::getdata();
        char trash;
        cout << "Введите дату выхода книги (например, 25/12/2002): ";
        cin >> day >> trash >> month >> trash >> year;
    }
    void putdata() {
        publication::putdata();
        cout << "Дата: " << month << "/" << day << "/" << year << endl;
    }
};

class manager : public Employee { // 10 - менеджер
private:
    char title[LEN];
    double dues;
public:
    void getdata() {
        Employee::getdata();
        cout << "Введите должность: ";
        cin >> title;
        cout << "Введите сумму взносов в гольф-клуб: ";
        cin >> dues;
    }
    void putdata() const {
        Employee::putdata();
        cout << "Должность: " << title << endl;
        cout << "Сумма взносов в гольф-клуб: " << dues << endl;
    }
};

class executive : public manager { // 10 - управляющий менеджер
private:
    int prem;
    int aks;
public:
    void getdata() {
        manager::getdata();
        cout << "Введите годовую премию: ";
        cin >> prem;
        cout << "Введите количество акций: ";
        cin >> aks;
    }
    void putdata() const {
        manager::putdata();
        cout << "Годовая премия: " << prem << endl;
        cout << "Количество акций: " << aks << endl;
    }
};

class Stack { // 11 - стэк
protected:
    static const int MAX = 7;;
    int st[MAX];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(int var) {
        st[++top] = var;
    }
    int pop() {
        return st[top--];
    }
};

class Stack2 : public Stack { // 11 - стэк
public:
    void push(int var) {
        if (top >= MAX - 1) {
            cout << "Cтек переполнен.";
        }
        Stack::push(var);
    }
    int pop() {
        if (top < 0) {
            cout << "Стек пуст.";
        }
        return Stack::pop();
    }
};

struct Para { // 11 - пара
    int x;
    int y;
};

class pairStack : public Stack2 {// 11 - стек пары
public:
    void push(Para unit) {
        Stack2::push(unit.x);
        Stack2::push(unit.y);
    }
    Para pop() {
        Para temp_unit{};
        temp_unit.y = Stack2::pop();
        temp_unit.x = Stack2::pop();
        return temp_unit;
    }
};

class sterling { // 12 - стерлинги
protected:
    long pounds;
    int shillings;
    int pences;
public:
    sterling() : pounds(0), shillings(0), pences(0) { }
    sterling(double df) {
        pounds = df;
        shillings = (df - pounds) * 20;
        pences = round(((df - pounds) * 20 - shillings) * 12);
    }
    sterling(long ps, int s, int p) : pounds(ps), shillings(s), pences(p) { }
    void getSterling() {
        char separator;
        cout << "   Введите сумму (фунты, шиллинги и пенсы через точку): ";
        cin >> pounds >> separator >> shillings >> separator >> pences;
    }
    void putSterling() const {
        cout << pounds << "." << shillings << "." << pences;
    }
    operator double() const {
        return (pounds + shillings / 20.0 + pences / 240.0);
    }
    sterling operator+ (sterling s) const {
        return sterling(double(sterling(pounds, shillings, pences)) + double(s));
    }
    sterling operator- (sterling s) const {
        return sterling(double(sterling(pounds, shillings, pences)) - double(s));
    }
    sterling operator* (double n) const {
        return sterling(double(sterling(pounds, shillings, pences)) * n);
    }
    double operator/ (sterling s) const {
        return (double(sterling(pounds, shillings, pences)) / double(s));
    }
    sterling operator/ (double n) const {
        return sterling(double(sterling(pounds, shillings, pences)) / n);
    }
};

class sterfrac : public sterling { // 12 - стерлинги дробные
private:
    int eighths;
public:
    sterfrac() : sterling(), eighths(0) { }
    sterfrac(double df) {
        pounds = df;
        shillings = (df - pounds) * 20;
        pences = ((df - pounds) * 20 - shillings) * 12;
        eighths = round((((df - pounds) * 20 - shillings) * 12 - pences) * 8);
    }
    sterfrac(long ps, int s, int p, int e) : sterling(ps, s, p), eighths(e) { }
    void getSterling() {
        char separator;
        int num, den;
        cout << "Введите сумму в формате '9.19.11-1/4': ";
        cin >> pounds >> separator >> shillings >> separator >> pences >> separator >> num >> separator >> den;
        if (den == 2) num = num * 4;
        if (den == 4) num = num * 2;
        eighths = num;
    }
    void putSterling() const {
        sterling::putSterling();
        cout << "-";
        switch (eighths) {
        case 2:
            cout << "1/4";
            break;
        case 4:
            cout << "1/2";
            break;
        case 6:
            cout << "3/4";
            break;
        default:
            cout << eighths << "/8";
        }
    }
    operator double() const {
        return (sterling::operator double() + eighths / 1920.0);
    }
    sterfrac operator+ (sterfrac s) const {
        return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) + double(s));
    }
    sterfrac operator- (sterfrac s) const {
        return sterfrac(abs(double(sterfrac(pounds, shillings, pences, eighths)) - double(s)));
    }
    sterfrac operator* (double n) const {
        return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) * n);
    }
    double operator/ (sterfrac s) const {
        return (double(sterfrac(pounds, shillings, pences, eighths)) / double(s));
    }
    sterfrac operator/ (double n) const {
        return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) / n);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << R"(1. Представьте себе издательскую компанию, которая торгует книгами и аудио-записями этих книг. Создайте класс
publication, в котором хранятся название (строка) и цена (типа float) книги. От этого класса наследуются еще два класса:
book, который содержит информацию о количестве страниц в книге (типа int), и type, который содержит время записи книги в
минутах (тип float). В каждом из этих трех классов должен быть метод getdata(), через который можно получать данные от
пользователя с клавиатуры, и putdata(), предназначенный для вывода этих данных. Напишите функцию main() программы для
проверки классов book и type. Создайте их объекты в программе и запросите пользователя ввести и вывести данные с
использованием методов getdata() и putdata().
+ 3. Начните с классов book, type и publication из упражнения 1. Добавьте базовый класс sales, в
котором содержится массив, состоящий из трех значений типа float, куда можно записать общую стоимость проданных книг за
последние три месяца. Включите в класс методы getdata() для получения значений стоимости от пользователя и putdata() для
вывода этих цифр. Измените классы book и type так, чтобы они стали производными обоих классов: publications и sales.
Объекты классов book и type должны вводить и выводить данные о продажах вместе с другими своими данными. Напишите
функцию main() для создания объектов классов book и type, чтобы протестировать возможности ввода/вывода данных. )" << endl;

    book book1;
    tape tape1;
    cout << "Введите данные книги: " << endl;
    book1.getdata();
    cout << "Введите данные аудиокниги: " << endl;
    tape1.getdata();
    cout << "Информация о книге: " << endl;
    book1.putdata();
    cout << "Информация об аудиокниге: " << endl;
    tape1.putdata();
    cout << endl;

    cout << "\n" << R"(2. Вспомните пример STRCONV из главы 8. Класс String в этом примере имеет дефект: у него нет защиты на тот случай, если
его объекты будут инициализированы слишком длинной строкой (константа SZ имеет значение 80). Например, определение
String s = "Эта строка имеет очень большую длину и мы можем быть уверены, что она не уместится в отведенный буфер, что
приведет к непредсказуемым последствиям."; будет причиной переполнения массива str строкой s с непредсказуемыми
последствиями вплоть до краха системы. Создадим класс Pstring, производный от класса String, в котором предотвратим
возможность переполнения буфера при определении слишком длинной строковой константы. Новый конструктор производного
класса будет копировать в str только SZ-1 символов, если строка окажется слишком длинной, и будет копировать строку
полностью, если она будет иметь длину меньшую, чем SZ. Напишите функцию main() программы для проверки ее работы со
строками разной длины. )" << endl;

    Pstring s11;
    char xstr[] = "Строка <80 символов";
    s11 = xstr;
    s11.display();
    Pstring s21 = "Строка >80 символов - лишние символы обрезаются: PI=3,141592653589793238462643383279...";
    s21.display();
    cout << endl;

    cout << "\n" << R"(4. Предположим, что издатель из упражнений 1 и 3 решил добавить к своей продукции версии книг на компьютерных дисках для
тех, кто любит читать книги на своих компьютерах. Добавьте класс disk, который, как book и type,является производным
класса publication. Класс disk должен включать в себя те же функции, что и в других классах. Полем только этого класса
будет тип диска: CD или DVD. Для хранения этих данных вы можете ввести тип enum. Пользователь должен выбрать подходящий
тип, набрав на клавиаtype с или d. )" << endl;

    disk d1;
    cout << "Введите информацию о книге на диске: " << endl;
    d1.getdata();
    cout << "Информация о книге на диске: " << endl;
    d1.putdata();

    cout << "\n" << R"(5. Создайте производный класс employee2 от базового класса employee из программы EMPLOY этой главы. Добавьте в новый
класс поле compensation типа double и поле period типа enum для обозначения периода оплаты работы служащего: почасовая,
понедельная или помесячная. Для простоты вы можете изменить классы laborer, manager и scientist так, чтобы они стали
производными нового класса employee2. Однако заметим, что во многих случаях создание отдельного класса compensation и
трех его производных классов manager2, scientist2 и laborer2 более соответствовало бы духу ООП. Затем можно применить
множественное наследование и сделать так, чтобы эти три новых класса стали производными класса compensation и
первоначальных классов manager, scientist и laborer. Таким путем можно избежать модификации исходных классов. )" << endl;

    employee2 m1{};
    cout << "Введите информацию о сотруднике: " << endl;
    m1.getdata();
    cout << "Информация о сотруднике: " << endl;
    m1.putdata();

    cout << "\n" << R"(6. Вспомним программу ARROVER3 из главы 8. Сохраним класс safearay таким же и, используя наследование, добавим к нему
возможность для пользователя определять верхнюю и нижнюю границы массива в конструкторе. Это похоже на упражнение 9 из
главы 8, за исключением того, что применено наследование для создания нового класса (можно назвать его safehilo) взамен
модификации исходного класса. )" << endl;

    int low, up;
    cout << "Введите нижнюю границу индекса массива: ";
    cin >> low;
    cout << "Введите верхнюю границу индекса массива: ";
    cin >> up;
    safe sa1(low, up);
    for (int j = low; j <= up; j++) sa1[j] = rand();

    for (int j = low; j <= up; j++) {
        int temp = sa1[j];
        cout << "Элемент " << j << " = " << temp << endl;
    }

    cout << "\n" << R"(7.Вспомним программу COUNTEN2 из этой главы. В ней можно увеличивать и уменьшать счетчик, используя префиксные операции.
Используя наследование, добавьте возможность использования постфиксных операций для случаев увеличения и уменьшения.)" << endl;

    CountDn c1;
    cout << "c1 = " << c1.get_count() << endl;
    ++c1;
    cout << "++c1 =" << c1.get_count() << endl;
    c1++;
    cout << "c1++ =" << c1.get_count() << endl;
    --c1;
    cout << "--c1 =" << c1.get_count() << endl;
    c1--;
    cout << "c1-- =" << c1.get_count() << endl;

    cout << "\n" << R"(8.В некоторых компьютерных языках, таких, как Visual Basic, есть операции, с помощью которых можно выделить часть строки
и присвоить ее другой строке. (В стандартном классе string предложены различные ходы.) Используя наследование, добавьте
такую возможность в класс Pstring из упражнения 2. В новом производном классе Pstring2 разместите три новых функции:
left(), mid() и right(). s2.left(s1, n) - в строку s2 помещаются n самых левых символов строки;
s1 s2.mid(s1, s, n) - в строку s2 помещаются n символов из строки, начиная с символа номер s;
s2.right(s1, n) - в строку s2 помещаются n самых правых символов строки s1.
Вы можете использовать цикл for для копирования символ за символом подходящих частей строки s1 во временный объект
класса Pstring2, который затем их возвратит. Для получения лучшего результата используйте в этих функциях возврат по
ссылке, чтобы они могли быть использованы с левой стороны знака «равно» для изменения части существующей строки. )" << endl;

    Pstring2 s1;

    cout << "Исходные строки: " << endl;

    char str[] = "Все ребята в нашем классе занимались карате";
    s1 = str;
    s1.display();
    Pstring2 s2 = "Страх и панику внушали всем вокруг.";
    s2.display();
    Pstring2 s3 = "Шаолинем называли в школе наш девятый дэ,\nВо главе стоял сенсей, он же физрук.\nА я (киийя!) в карате не понимал ни бэ ни мэ,\nА я, эх, я, увлекался рисованьем аниме.";
    s3.display();

    s2.left(s1, 10);
    cout << "Строка 1: left(s1, 10) = ";
    s2.display();
    s2.mid(s1, 11, 15);
    cout << "Строка 1: mid(s1, 11, 15) = ";
    s2.display();
    s2.right(s1, 17);
    cout << "Строка 1: right(s1, 17) = ";
    s2.display();

    cout << "\n" << R"(9.Вспомним классы publication, book и type из упражнения 1. Предположим, что мы хотим добавить в классы book и type дату
выхода книги. Создайте новый производный класс publication2, который является производным класса publication и включает
в себя поле, хранящее эту дату. Затем измените классы book и type так, чтобы они стали производными класса publication2
вместо publication. Сделайте необходимые изменения функций классов так, чтобы пользователь мог вводить и выводить дату
выхода книги. Для даты можно использовать класс data из упражнения 5 главы 6, который хранит дату в виде трех целых:
для месяца, для дня и для года. )" << endl;

    publication2 pub2;
    cout << "Введите данные о книге: " << endl;
    pub2.getdata();
    cout << "Данные о книге: " << endl;
    pub2.putdata();

    cout << "\n" << R"(10. В программе EMPMULT этой главы существует только один тип должности менеджера. В любой серьезной компании кроме
менеджеров существуют еще и управляющие. Создадим производный от класса manager класс executive. (Мы предполагаем, что
управляющий — это главный менеджер.) Добавочными данными этого класса будут размер годовой премии и количество его акций
в компании. Добавьте подходящие методы для этих данных, позволяющие их вводить и выводить. )" << endl;

    executive e{};
    e.getdata();
    cout << "Информация о главном менеджере:" << endl;
    e.putdata();

    cout << "\n" << R"(11. В различных ситуациях иногда требуется работать с двумя числами, объединенными в блок. Например, каждая из координат
экрана имеет горизонтальную составляющую (x) и вертикальную (y). Представьте такой блок чисел в качестве структуры pair,
которая содержит две переменные типа int. Теперь предположим, что мы хотим иметь возможность хранить переменные типа
pair в стеке. То есть мы хотим иметь возможность положить переменную типа pair в стек путем вызова метода push() с
переменной типа pair в качестве аргумента и вынуть ее из стека путем вызова метода pop(), возвращающего переменную типа
pair. Начнем с класса Stack2 программы STAKEN из этой главы. Создадим производный от него класс pairStack. В нем будут
содержаться два метода: перегружаемый метод push() и перегружаемый метод pop(). Метод pairStack::push() должен будет
сделать два вызова метода Stack2::push(), чтобы сохранить оба числа из пары, а метод pairStack::pop() должен будет
сделать два вызова метода Stack2::pop(). )" << endl;

    Para p1 = { 110, 21 };
    pairStack s12;
    s12.push(p1);
    Para p;
    p = s12.pop();
    cout << p.x << ", " << p.y << endl;
    p = s12.pop();

    cout << "\n" << R"(12. Рассмотрим старую Британскую платежную систему фунты-стерлингипенсы (см. упражнение 10 главы 4 «Структуры»). Пенни в
дальнейшем делятся на фартинги и полупенни. Фартинг — это 1/4 пенни. Существовали монеты фартинг, полфартинга и пенни.
Любые сочетания монет выражались через восьмые части пенни: 1/8 пенни — это полфартинга; 1/4 пенни — это фартинг; 3/8
пенни — это фартинг с половиной; 1/2 пенни — это полпенни; 5/8 пенни — это полфартинга плюс полпенни; 3/4 пенни — это
полпенни плюс фартинг; 7/8 пенни — это полпенни плюс фартинг с половиной. Давайте предположим, что мы хотим добавить в
класс sterling возможность пользоваться этими дробными частями пенни. Формат ввода/вывода может быть похожим на
£1.1.1-1/4 или £9.19.11-7/8, где дефисы отделяют дробные части от пенни. Создайте новый класс sterfrac, производный от
класса sterling. В нем должна быть возможность выполнения четырех основных арифметических операций со стерлингами,
включая восьмые части пенни. Поле eighths типа int определяет количество восьмых. Вам нужно будет перегрузить методы
класса sterling, чтобы они могли работать с восьмыми частями. Пользователь должен иметь возможность ввести и вывести
дробные части пенни. Не обязательно использовать класс fraction полностью (см. упражнение 11 главы 6), по вы можете это
сделать для большей точности.)" << endl;

    sterfrac s112, s212, s;
    double n;
    cout << "1. ";
    s112.getSterling();
    cout << "2. ";
    s212.getSterling();
    cout << endl;
    cout << "1. В десятичных фунтах: " << fixed << setprecision(2) << double(s112) << endl;
    cout << "2. В десятичных фунтах: " << fixed << setprecision(2) << double(s212) << endl << endl;
    s = s112 + s212;
    cout << "Результат сложения этих сумм: ";
    s.putSterling();
    cout << endl;
    s = s112 - s212;
    cout << "Разность этих сумм: ";
    s.putSterling();
    cout << endl;
    s = s112 * 1.05;
    cout << "Произведение первой суммы и числа 1,05: ";
    s.putSterling();
    cout << endl;
    n = s112 / s212;
    cout << "Частное от деления первой суммы на вторую: " << n << endl;
    s = s112 / 3.5;
    cout << "Частное от деления первой суммы на число 3,5: ";
    s.putSterling();
    cout << endl;

    return 0;
}

