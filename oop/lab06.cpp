#include <iostream>
#include <cstring> //для strlen()
#include <windows.h> //для правильного вывода на русском в лабе 1
#include <io.h> // для _setmode (лаба 7+11)
#include <fcntl.h> // для _O_U16TEXT (лаба 7+11)
#include <ctime> //для time()
#include <iomanip>  //для setprecision (лаба 7+11)
#include <sstream> // для wstringstream (лаба 7+11)

using namespace std;

void reversit(wchar_t str[]) { //1 - переворачиватель строк
    int lngth = wcslen(str);
    wchar_t temp;
    for (int i=0, j=lngth-1; i<lngth/2; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

class employee { //2 - сотрудник
    private: wstring name;
    long number;

    public: void getdata() {
        wcout<<"Введите имя сотрудника: ";
        wcin>>name;
        wcout<<"Введите номер сотрудника: ";
        wcin>>number;
    }

    void putdata() {
        wcout<<"Имя: "<<name<<"\n№: "<<number<<endl;
    }
};

class Distance { //3 - расстояние
    private: int feet;
    float inches;
    public: Distance(int ft=0, float in=0) {
        feet=ft;
        inches=in;
    }

    void getdist() {
        wcout<<"Введите футы: ";
        wcin>>feet;
        wcout<<"Введите дюймы: ";
        wcin>>inches;
    }

    void showdist() {
        wcout<<feet<<" ft. "<<inches<<" in."<<endl;
    }

    void add(Distance d1, Distance d2) {
        inches = d1.inches + d2.inches;
        feet = d1.feet + d2.feet;
        while (inches>=12) {
            inches-=12;
            feet+=1;
        }
    }

    void div(Distance d, int divisor) {
        float fulldist = d.feet + d.inches / 12.0;
        fulldist /= divisor;
        feet = int(fulldist);
        inches = (fulldist - feet) * 12.0;
    }
};

int maxint(int mas[], int amount) { //4 - наибольший int
    int maxnum = 0;
    for (int i=0; i<amount; i++) {
        if (mas[maxnum]<mas[i]) maxnum=i;
    }
    return maxnum;
}

class fraction { //5 - дроби
    private:
    public: int chis, znam;
    wchar_t ch;
    fraction(int chs=0, int znm=1) {
        chis = chs;
        znam = znm;
    }

    void inputFraction() {
        wcout<<"Введите дробь в формате 3/5: "<<endl;
        wcin>>chis>>ch>>znam;
    }

    void sumFractions(fraction f1, fraction f2) {
        chis = f1.chis*f2.znam + f1.znam*f2.chis;
        znam = f1.znam*f2.znam;
    }

    void showFraction() {
        wcout<<chis<<"/"<<znam;
    }

    void lowterms(){
        long tnum, tden, temp, gcd;
        tnum = labs(chis);
        tden = labs(znam);

        if(tden == 0) {
            wcout << "Недопустимый знаменатель";
            exit(1);
        }

        else if(tnum == 0) {
            chis = 0;
            znam = 1;
            return;
        }
        // Нахождение наибольшего общего делителя

        while(tnum != 0) {
            if(tnum < tden) { // Если числитель больше знаменателя, меняем их местами.
                temp = tnum;
                tnum = tden;
                tden = temp;
            }

        tnum = tnum - tden;

        }

        gcd = tden;

        chis = chis / gcd;
        znam = znam / gcd;
    }

    void substrFractions(fraction f1, fraction f2) {
        chis = (f1.chis*f2.znam)-(f2.chis*f1.znam);
        znam = f1.znam*f2.znam;
    }

    void multiplyFractions(fraction f1, fraction f2) {
        chis = f1.chis*f2.chis;
        znam = f1.znam*f2.znam;
    }

    void divideFractions(fraction f1, fraction f2) {
        chis = f1.chis*f2.znam;
        znam = f2.chis*f1.znam;
    }

};

// 6 - карты
enum Suit { clubs, diamonds, hearts, spades };

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class card {
    private: int number; // достоинство
	Suit suit;  // масть
    public: card(){}
    set(int n, Suit s) {
	    number = n;
	    suit = s;
    }
	void display() {// вывод карты на экран
        if (number >= 2 && number <= 10) wcout<<number;
        else {
            switch (number){
                case jack:  wcout<<'J'; break;
                case queen: wcout<<'Q'; break;
                case king:  wcout<<'K'; break;
                case ace:   wcout<<'A'; break;
            }
        }
        switch (suit) { //ломается при переводе кодировки в 1251
            case clubs:    wcout <<'\x05'; break;
            case diamonds: wcout <<'\x04'; break;
            case hearts:   wcout <<'\x03'; break;
            case spades:   wcout <<'\x06'; break;
        }
	}
};

class money { //7+11 - деньги в долларах и центах
    private:
        long double sum;
    public:	long double mstold(wchar_t str[]){
        wchar_t temp[80];
        int j = 0;

        for (int i = 0; i < wcslen(str); i++)
        {
            wchar_t ch = str[i];

            if ((ch >= L'0') && (ch <= L'9'))
                temp[j++] = ch;
            else if (ch == L'.')
                temp[j++] = ch;
        }
        temp[j] = L'\0';

        wchar_t *stop;

        sum = wcstold(temp, &stop);

        return sum;
    }

	void ldtoms(wchar_t str[]){
        wchar_t ustring[80];
        wstringstream woss;

        woss << setiosflags(ios::fixed) << setprecision(2) << sum;

        woss >> ustring;

        int i = 0, n = 0, j;
        int len = wcslen(ustring);
        wchar_t delim3 = L',';

        str[i++] = L'$';

        if ((len - 3) % 3 == 2)
        {
            str[i++] = ustring[n++];
            str[i++] = ustring[n++];
            str[i++] = delim3;
        }
        else if ((len - 3) % 3 == 1)
        {
            str[i++] = ustring[n++];
            str[i++] = delim3;
        }

        for (j = n; j < len - 3; j++)
        {
            str[i++] = ustring[j];
            if (((j - n + 1) % 3 == 0) && (j != len - 3 - 1))
                str[i++] = delim3;
        }

        str[i++] = ustring[j++];
        str[i++] = ustring[j++];
        str[i++] = ustring[j];
        str[i]   = L'\0';
    }
};

class safearay { //8 - безопасный массив
    private: static const int LIMIT = 10;
        int sarr[LIMIT];
    public: void putel(int index, int el) {
        if ((index >= 0) && (index < LIMIT)) sarr[index] = el;
        else wcout<<"Запись не выполнена: индекс "<<index<<" выходит за пределы."<< endl;
    }

    int getel(int index) {
        if ((index >= 0) && (index < LIMIT)) return sarr[index];
        else {
            wcout<<"Элемент массива не получен: индекс "<<index<<" выходит за пределы."<<endl;
            exit(1);
        }
    }
};

class queue { //9 - очередь
    private: static const int MAX = 10;
        int q[MAX];
        int head, tail, length;
    public:	queue() {
		head = 0;
		tail = -1;
		length = 0;
	}
	void put(int var) {
        if (length == MAX){
            wcout<<"Очередь переполнена.";
        }
        else if (tail == MAX - 1) tail = -1;
        else {
            q[++tail] = var;
            length++;
        }
	}
	int get() {
        if (length == 0) {
            wcout <<"Очередь пуста.";
        }
        else {
            int var = q[head++];
            length--;

            if (head == MAX) head = 0;

            return var;
        }
	}
};

class matrix { //10 - безопасная матрица
    private:static const int NROWS = 10;
        static const int NCOLS = 10;
        int sar[NROWS][NCOLS];
        int mrows;
        int mcols;
    public: matrix(int mr, int mc){
        if ((mr > 0 && mr <= NROWS) && (mc > 0 && mc <= NCOLS)){
            mrows = mr;
            mcols = mc;
        }
        else wcout <<"Один или оба заданных размера матрицы не входят в размеры массива. ";
    }

    void putel(int irow, int icol, int el) {
        if ((irow >= 0 && irow < mrows) && (icol >= 0 && icol < mcols)) sar[irow][icol] = el;
        else wcout <<"Запись не выполнена: индекс ["<<irow<<"][" << icol <<"] выходит за границы."<< endl;
    }

    int getel(int irow, int icol) {
        if ((irow >= 0 && irow < mrows) && (icol >= 0 && icol < mcols)) return sar[irow][icol];
        else wcout <<"Элемент не найден: индекс ["<<irow<<"][" << icol <<"] выходит за границы."<< endl;
    }
};

class bMoney { //12
    private: long double money;
    public: bMoney() {
        money = 0.0L;
    }
    bMoney(const wchar_t s[]){
        mstold(s);
    }
    void madd(bMoney m1, bMoney m2) {
        money = m1.money + m2.money;
    }
    void getmoney() {
        wchar_t tms[80];
		wcout<<"Введите денежную сумму (например, $1,234,567.99):\n";
		wcin>>tms;
		mstold(tms);
    }
    void putmoney() {
        wchar_t tms[80];
		ldtoms(tms);
		wcout<<tms;
    }

    long double mstold(const wchar_t str[]){
        wchar_t temp[80];
        int j = 0;

        for (int i = 0; i < wcslen(str); i++){
            wchar_t ch = str[i]; //

            if ((ch >= L'0') && (ch <= L'9'))
                temp[j++] = ch;
            else if (ch == L'.')
                temp[j++] = ch;
        }
        temp[j] = L'\0';

        wchar_t *stop;

        money = wcstold(temp, &stop);

        return money;
    }

    void ldtoms(wchar_t str[]) {

        wchar_t ustring[80];
        wstringstream woss;

        woss << setiosflags(ios::fixed) << setprecision(2) << money;

        woss >> ustring;

        int i = 0, n = 0, j;
        int len = wcslen(ustring);
        wchar_t delim3 = L',';

        str[i++] = L'$';

        if ((len - 3) % 3 == 2) {
            str[i++] = ustring[n++];
            str[i++] = ustring[n++];
            str[i++] = delim3;
        }
        else if ((len - 3) % 3 == 1) {
            str[i++] = ustring[n++];
            str[i++] = delim3;
        }

        for (j = n; j < len - 3; j++){
            str[i++] = ustring[j];

            if (((j - n + 1) % 3 == 0) && (j != len - 3 - 1))
                str[i++] = delim3;
        }

        str[i++] = ustring[j++];
        str[i++] = ustring[j++];
        str[i++] = ustring[j];
        str[i]   = L'\0';
    }
};

int main() {

//включить для правильного разворота строк на русском
//когда включены, ломают отображение мастей карт (задание 6)
SetConsoleCP(1251);
SetConsoleOutputCP(1251);

//нужно для работы 7 и 11 лаб (иначе отсекается дробная часть у сумм)
_setmode(_fileno(stdout), _O_U16TEXT);
_setmode(_fileno(stdin), _O_U16TEXT);

wcout<<R"(1. Напишите функцию reversit(), которая переворачивает строку (массив типа char). Используйте цикл
for, который меняет местами первый и последний символы, затем следующие и т. д. до предпоследнего. Строка
должна передаваться в функцию reversit() как аргумент.
Напишите программу для выполнения функции reversit(). Программа должна принимать строку от пользователя,
вызывать функцию reversit(), а затем выводить полученный результат. Используйте метод ввода, который
позволяет использовать внутренние пробелы. Протестируйте программу на примере фразы «Аргентина манит негра».)"<<endl;

wchar_t str[100];
wcout<<"\nВведите строку с пробелами, по окончании нажмите enter: ";
wcin.get(str, 100);
reversit(str);
wcout<<"Перевёрнутая строка: "<<str;

wcout<<"\n"<<R"(2. Создайте класс employee, который содержит имя (объект класса string) и номер (тина long)
служащего. Включите в него метод getdata(), предназначенный для получения данных от пользователя и помещения
их в объект, и метод putdata(), для вывода данных. Предполагаем, что имя может иметь внутренние пробелы.
Напишите функцию main(), использующую этот класс. Вам нужно будет создать массив типа employee, а затем
предложить пользователю ввести данные до 100 служащих. Наконец, вам нужно будет вывести данные всех служащих. )"<<endl;

employee em[100];
wchar_t ch;
int n=0;

do {
    wcout<<"Запись о сотруднике #"<<n<<endl;
    em[n].getdata();
    wcout<<"\nВвести данные следующего сотрудника? y, n: ";
    wcin>>ch;
    n++;
}

while (ch!='n'&&n!=100);

wcout<<"Введённые данные:"<<endl;
for (int i=0; i<n; i++) {
    wcout<<"Запись о сотруднике #"<<i<<endl;
    em[i].putdata();
}

wcout<<"\n"<<R"(3. Напишите программу, вычисляющую среднее значение 100 интервалов, введенных пользователем.
Создайте массив объектов класса Distance, как это было сделано в примере ENGLARAY этой главы. Для вычисления
среднего значения вы можете позаимствовать метод add_dist() из примера EN6LC0N главы 5. Вам также понадобится
метод, который выделяет целую часть из значения Distance. )"<<endl;

Distance d[100];
n=0;

do {
    wcout<<"Запись о расстоянии #"<<n<<endl;
    d[n].getdist();
    wcout<<"Ввести следующее расстояние? y,n: ";
    wcin>>ch;
    n++;
}

while (ch!='n'&&n!=100);

Distance dsum;
for (int i=0; i<n; i++) dsum.add(dsum, d[i]);
dsum.div(dsum, n);
wcout<<"Среднее значение введённых интервалов: ";
dsum.showdist();

wcout<<"\n"<<R"(4. Начните с программы, которая позволяет пользователю вводить целые числа, а затем сохранять
их в массиве типа int. Напишите функцию maxint(), которая, обрабатывая элементы массива один за другим,
находит наибольший. Функция должна принимать в качестве аргумента адрес массива и количество элементов в нем,
а возвращать индекс наибольшего элемента. Программа должна вызвать эту функцию, а затем вывести наибольший
элемент и его индекс. )"<<endl;

int nums[100];
n=0;

do {
    wcout<<"Целое число #"<<n<<endl;
    wcin>>nums[n];
    wcout<<"Ввести следующее число? y,n: ";
    wcin>>ch;
    n++;
}

while (ch!='n'&&n!=100);

wcout<<"Индекс наибольшего элемента: "<<maxint(nums, n)<<endl;


wcout<<"\n"<<R"(5. Начните с класса fraction из упражнений 11 и 12 лабораторной работы 5. Напишите функцию
main(), которая получает случайные дробные числа от пользователя, сохраняет их в массиве типа fraction,
вычисляет среднее значение и выводит результат. )"<<endl;

fraction frs[100];
n=0;

do {
    wcout<<"Дробь #"<<n<<endl;
    frs[n].inputFraction();
    wcout<<"Ввести следующую дробь? y,n: ";
    wcin>>ch;
    n++;
}

while (ch!='n'&&n!=100);

fraction sum, divider(n, 1);

for (int i=0; i<n; i++) sum.sumFractions(sum, frs[i]);
sum.divideFractions(sum, divider);
sum.lowterms();
wcout<<"Среднее арифметическое введённых дробей: ";
sum.showFraction();
wcout<<endl;

wcout<<"\n"<<R"(6. В игре бридж каждому из игроков раздают 13 карт, таким образом колода расходуется полностью.
Модифицируйте программу CARDARAY этой главы так, чтобы после перемешивания колоды она делилась на четыре части
по 13 карт каждая. Каждая из четырех групп карт затем должна быть выведена. )"<<endl;

card deck[52];

for (int i=0; i<52; i++) {
    int num = (i%13)+2;
    Suit su = Suit(i/13);
    deck[i].set(num, su);
}

wcout << "Исходная колода:\n";
for (int j=0; j<52; j++) {
    deck[j].display();
    if (!((j + 1) % 13)) wcout<<endl;
    else wcout<<" ";
}

srand(time(NULL));

for (int j=0; j<52; j++) {
    int k = rand()%52;
    card temp = deck[j];
    deck[j] = deck[k];
    deck[k] = temp;
}

wcout <<"\nПеремешанная колода:\n";
for (int j=0; j<52; j++){
    deck[j].display();
    if (!((j + 1) % 13)) wcout << endl;
    else wcout<<" ";
}

card hands[4][13];
int i;
n=0;

for (int j=0; j<13; j++) {
    for (int i=0; i<4; i++) {
        hands[i][j] = deck[n++];
    }
}

for (int i=0; i<4; i++) {
    wcout<<"\nКарты "<<i + 1<<"-го игрока:\n";
    for (int j=0; j<13; j++){
        hands[i][j].display();
        if (j+1<13) wcout <<" ";
        else wcout<<endl;
    }
}

wcout<<"\n"<<R"(7. Одним из недостатков C++ является отсутствие для бизнес-программ встроенного типа для
денежных значений, которые должны иметь возможность для хранения числа с фиксированной десятичной точкой
точностью около 17 знаков. Встроенный тип C++ long double имеет точность 19 цифр, поэтому мы можем
использовать его как базисный для класса money, даже используя плавающую точку. Нужно добавить возможность
ввода и вывода денежных значений с предшествующим им знаком доллара и разделенными запятыми группы по три
числа: так проще читать большие числа. Напишем метод mstold(), который принимает денежную строку - некоторое
количество денег типа “$123.456.789.00” в качестве аргумента и возвращает эквивалентное ее значению число типа
long double. Вам нужно будет обработать денежную строку как массив символов и, просматривая ее символ за
символом, скопировать из нее только цифры (0-9) и десятичную точку в другую строку. Вы можете использовать
библиотечную функцию _atold() для преобразования новой строки к числу типа long double. Напишите функцию
main() для проверки метода mstold(), которая несколько раз получает денежную строку от пользователя и выводит
соответствующее число типа long double. )"<<endl;

money mn;
wchar_t money[80];
long double result;
wchar_t ch1;

do {
    wcout<<"Введите денежную строку (например, $12,345,678.99): ";
    wcin>>money;
    result = mn.mstold(money);
    wcout<<"Число типа long double: "<<setiosflags(ios::fixed)<<setprecision(5)<<result<<endl;
    wcout<<"Ввести следующую сумму? y,n: ";
    wcin>>ch1;
}

while (ch1!='n');

wcout<<"\n"<<R"(8. Другим недостатком C++ является отсутствие автоматической проверки индексов массива на
соответствие их границам массива (это делает действия с массивами быстрыми, но менее надежными). Мы можем
использовать класс для создания надежного массива, который проверяет индексы при любой попытке доступа к
массиву. Напишите класс safearay, который использует массив типа int фиксированного размера (назовем его
LIMIT) в качестве своей единственной переменной. В классе будет два метода. Первый, putel(), принимает индекс
и значение типа int как аргументы и вставляет это значение в массив по заданному индексу. Второй, getel(),
принимает индекс как аргумент и возвращает значение типа int, содержащееся в элементе с этим индексом.

Оба метода должны проверять индекс аргумента, чтобы быть уверенными, что он не меньше 0 и не больше, чем
LIMIT—1. Вы можете использовать этот массив без опаски, что запись будет произведена в другие части памяти. )"<<endl;

safearay sa;
int k = 45678;

sa.putel(2, k);
wcout<<"Число на позиции 2: "<<sa.getel(2)<<endl;

sa.putel(-2, k); //ошибка

wcout<<"\n"<<R"(9. Очередь — это устройство для хранения данных, похожее на стек. Отличие в том, что в стеке
последний сохраненный элемент будет первым извлеченным, тогда как в очереди первый сохраненный элемент будет
первым извлеченным.
Перепишите программу STAKARAY из этой главы, включив в нее класс queue вместо класса stack. Кроме того, класс
должен иметь два метода: один, называемый put(), для помещения элемента в очередь; и другой, называемый get(),
для извлечения элемента из очереди. Эти методы эквивалентны методам push() и рор() класса stack.
Оба класса, stack и queue, используют массив для хранения данных. Однако вместо одного поля top типа int, как
в классе stack, вам понадобятся два поля для очереди: одна, называемая head, указывающая на начало очереди; и
вторая, tail, указывающая на конец очереди.)"<<endl;

queue q1;
q1.put(101);
q1.put(202);
wcout<<"Элемент очереди 1: "<<q1.get()<<endl;
wcout<<"Элемент очереди 2: "<<q1.get()<<endl;
q1.put(303);
q1.put(404);
wcout<<"Элемент очереди 3: "<<q1.get()<<endl;
wcout<<"Элемент очереди 4: "<<q1.get()<<endl;

wcout<<"\n"<<R"(10. Матрица — это двумерный массив. Создайте класс matrix, который предоставляет те же меры
безопасности, как и класс из задания 7, то есть осуществляет проверку индексов массива на вхождение их в
границы массива. Полем класса matrix будет массив 10 на 10. Конструктор должен позволять программисту
определить реальный размер массива (допустим, сделать его меньше, чем 10 на 10). Методам, предназначенным для
доступа к членам матрицы, теперь нужны два индекса: по одному для каждой размерности массива)"<<endl;

matrix m(6, 2);
m.putel(2, 1, k);

wcout<<"Число на позиции 2, 1: "<<m.getel(2, 1)<<endl;
m.putel(7, 1, k); //ошибка
m.getel(7, 1); //ошибка

wcout<<"\n"<<R"(11. Вернемся к обсуждению денежных строк из упражнения 6. Напишите метод ldtoms() для
преобразования числа типа long double в денежную строку, представляющую это число. Мы предполагаем, что вы не
будете пытаться преобразовать число, больше чем 9 999 999 999 999 990.00. Затем преобразуем long double в
строку (без знака доллара и запятых), хранящуюся в памяти, используя объект ostrstream, как рассматривалось
ранее в этой главе. Получившаяся отформатированная строка может быть помещена в буфер, называющийся ustring.
Затем вам нужно будет создать другую строку, начинающуюся со знака доллара, далее копируем цифру за цифрой из
строки ustring, начиная слева и вставляя запятые через каждые три цифры.
Напишите функцию main() для тестирования этой функции путем многократного ввода пользователем чисел типа long
double и вывода результата в виде денежной строки. )"<<endl;

wchar_t tms[80];

do {
    wcout<<"Введите денежную сумму (например: $12,345,678.99): ";
    wcin>>tms;
    result = mn.mstold(tms);
    wcout << "Число типа long double: "<<setiosflags(ios::fixed)<<setprecision(5)<<result<<endl;
    mn.ldtoms(tms);
    wcout<<"Денежная строка: "<<tms<<endl;
    wcout<<"Ввести следующую сумму? y,n: ";
    wcin>>ch1;
}
while (ch1!='n');

wcout<<"\n"<<R"(12. Создайте класс bMoney. Он должен хранить денежные значения как long double. Используйте
метод mstold() для преобразования денежной строки, введенной пользователем, в long double, и метод ldtoms()
для преобразования числа типа long double в денежную строку для вывода (см. задания 6 и 10). Вы можете
вызывать для ввода и вывода методы getmoney()и putmoney(). Напишите другой метод класса для сложения двух
объектов типа ЬМопеу и назовите его madd(). Сложение этих объектов легко произвести: просто сложите переменную
типа long double одного объекта с такой же переменной другого объекта. Напишите функцию main(), которая просит
пользователя несколько раз ввести денежную строку, а затем выводит сумму значений этих строк.)"<<endl;

const int MAX = 100;
bMoney ms[MAX];
n=0;

do {
    if (n == MAX) {
        wcout <<"Введено максимальное количество денежных сумм." << endl;
        break;
    }

    ms[n++].getmoney();

    wcout <<"Ввести следующую сумму? y,n: ";
    wcin >> ch1;
} while (ch1 != L'n');

wcout << endl;

bMoney msum;
for (int j = 0; j < n; j++) msum.madd(msum, ms[j]);

wcout <<"Сумма введенных денежных сумм: ";
msum.putmoney();
wcout << endl;

}
