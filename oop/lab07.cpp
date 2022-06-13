#include <iostream>
#include <cstring>
#include <windows.h>
#include <io.h> // для _setmode
#include <fcntl.h> // для _O_U16TEXT
#include <iomanip>  //для setprecision
#include <sstream> // для wstringstream
#include <conio.h>

using namespace std;

class Distance { //1 - дистанция
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }
    Distance(int ft, float in) : feet(ft), inches(in) { }
    void getdist() {
        wcout<< L"Введите футы: ";
        wcin>>feet;
        wcout<< L"Введите дюймы: ";
        wcin>>inches;
    }
    void showdist() {
        wcout<<feet<<"'"<<inches<<'"'<<endl;
    }
    Distance operator+(Distance d2) const {
        int f = feet + d2.feet;
        float i = inches + d2.inches;
        if (i >= 12.0)
        {
            i -= 12.0;
            f++;
        }
        return Distance(f, i);
    }
    Distance operator-(Distance d2) const {
        int f = feet - d2.feet;
        float i = inches - d2.inches;
        while (i < 0)
        {
            i += 12.0;
            f--;
        }
        return Distance(f, i);
    }
};

class String { //2 - строки
private:
    wchar_t str[150];
public:
    String() {}
    String(wchar_t s[]) {
        wcscpy_s(str, s);
    }
    void display() const {
        wcout << str;
    }
    void put(int t) {
        wstring st;
        int i = 0, n = 0, j = 0;
        switch (t) {
        case 1:
            st = L"\nВ лесу родилась ёлочка, ";
            wcscpy_s(str, st.c_str());
            break;
        case 2:
            st = L"в лесу она росла, ";
            wcscpy_s(str, st.c_str());
            break;
        case 3:
            st = L"зимой и летом стройная зелёная была.";
            wcscpy_s(str, st.c_str());
            break;
        default:
            break;
        }
    }
    String operator+=(String ss) {
        if (wcslen(str) + wcslen(ss.str) < 150)
            wcscat_s(str, ss.str);
        else {
            wcout<< L"Слишком длинная строка, сложение невозможно."<<endl;
        }
        return (str);
    }
};

class Time { //3 - время
private:
    int hour;
    int mins;
    int sec;
public:
    Time(int h=0, int m=0, int s=0) : hour(h), mins(m), sec(s) {};
    Time operator+ (Time t2) const {
        int a, b, c;
        a = sec + t2.sec;
        b = mins + t2.mins;
        c = hour + t2.hour;
        if (a > 59) {
            b++;
            a -= 60;
        }
        if (b > 59) {
            c++;
            b -= 60;
        }
        return Time(c, b, a);
    }
    void display() {
        wcout << hour << ":" << mins << ":" << sec << endl;
    }

    //5
    Time operator++ (int) {
        return Time(hour++, mins++, sec++);
    }
    Time operator++ () {
        return Time(++hour, ++mins, ++sec);
    }
    Time operator-- (int) {
        return Time(hour--, mins--, sec--);
    }
    Time operator-- () {
        return Time(--hour, --mins, --sec);
    }

    //6
    Time operator- (Time t2) const {
        int a, b, c;
        a = sec - t2.sec;
        b = mins - t2.mins;
        c = hour - t2.hour;
        if (a > 59) {
            b++;
            a -= 60;
        }
        if (b > 59) {
            c++;
            b -= 60;
        }
        return Time(c, b, a);
    }

    Time operator* (Time t2) {
        long totalsec = (hour * 3600 + mins * 60 + sec) * (t2.hour * 3600 + t2.mins * 60 + t2.sec);
        int a, b = 0, c = 0;
        a = totalsec/3600; //h
        totalsec -= a * 3600;
        b = totalsec / 60; //m
        totalsec -= b * 60;
        c = totalsec / 60; //s
        while (c >= 60) {
            b++;
            c -= 60;
        }
        while (b >= 60) {
            a++;
            b -= 60;
        }
        return Time(a, b, c);
    }
};

class Int { //4 - Int
private:
    long double i;
public:
    Int() {
        i = 0;
    }
    Int(long double i1) {
        i = i1;
    }
    Int operator+ (Int a) {
        long double j;
        j = i + a.i;
        if (abs(j) > 2147483648) {
            wcout << L"Слишком большое значение."<<endl;
            exit(1);
        }
        return Int(j);
    }
    Int operator- (Int a) {
        long double j;
        j = i - a.i;
        if (abs(j) > 2147483648) {
            wcout << L"Слишком большое значение." << endl;
            exit(1);
        }
        return Int(j);
    }
    Int operator* (Int a) {
        long double j;
        j = i * a.i;
        if (abs(j) > 2147483648) {
            wcout << L"Слишком большое значение." << endl;
            exit(1);
        }
        return Int(j);
    }
    Int operator/ (Int a) {
        long double j;
        j = int(i * a.i);
        if (abs(j) > 2147483648) {
            wcout << L"Слишком большое значение." << endl;
            exit(1);
        }
        return Int(j);
    }
    void display() {
        wcout << i;
    }
};

class Fraction { //7 - дробь
private:
    int chis;
    int znam;
    wchar_t ch;
public:
    void add() {
        wcout << L"Введите дробь (например, 5/3): ";
        wcin >> chis >> ch >> znam;
        if ((chis == 0 && znam == 0) || (chis == 0 && znam == 1) || (chis == 1 && znam == 1)) {
            wcout << L"Знаменатель не должен быть равен нулю."<<endl;
            exit(1);
        }
    }
    void display() {
        wcout << chis << "/" << znam << endl;
    }
    Fraction operator+(Fraction d2) {
        Fraction s;
        s.chis = chis * d2.znam + znam * d2.chis;
        s.znam = znam * d2.znam;
        return(s);
    }
    Fraction operator-(Fraction d2) {
        Fraction s;
        s.chis = chis * d2.znam - znam * d2.chis;
        s.znam = znam * d2.znam;
        return(s);
    }
    Fraction operator*(Fraction d2) {
        Fraction s;
        s.chis = chis * d2.chis;
        s.znam = znam * d2.znam;
        return(s);
    }
    Fraction operator/(Fraction d2) {
        Fraction s;
        s.chis = chis * d2.znam;
        s.znam = znam * d2.chis;
        return(s);
    }
    void lowterms() {
        long Znam, Chis, temp, gcd;
        Chis = labs(chis);
        Znam = labs(znam);
        if (Znam == 0) {
            wcout << L"Знаменатель не должен быть равен нулю." << endl;
            exit(1);
        }
        else if (Chis == 0) {
            chis = 0;
            znam = 1;
            return;
        }
        while (Znam != 0) {
            if (Chis > Znam) {
                temp = Znam;
                Znam = Chis;
                Chis = temp;
            }
            Znam -= Chis;
        }
        gcd = Chis;
        chis /= gcd;
        znam /= gcd;
    }
};

class safearay { //9 - безопасный массив
private: static const int LIMIT = 1000;
    int sarr[LIMIT];
public: 
    void putel(int index, int el) {
        if ((index >= 0) && (index < LIMIT)) sarr[index] = el;
        else wcout << L"Запись не выполнена: индекс " << index << " выходит за пределы." << endl;
    }

    int getel(int index) {
        if ((index >= 0) && (index < LIMIT)) return sarr[index];
        else {
            wcout << L"Элемент массива не получен: индекс " << index << " выходит за пределы." << endl;
            exit(1);
        }
    }

    int& operator[](int index) {
        if ((index >= 0) && (index < LIMIT)) return sarr[index];
        else {
            wcout << L"Элемент массива не получен: индекс " << index << " выходит за пределы." << endl;
            exit(1);
        }
    }
};

class Polar { //10 - полярные координаты
private:
    double rad;
    double ang;
public:
    Polar(double ug=0, double ra=0) : ang(ug), rad(ra) {}
    Polar operator+(Polar xy) {
        double x1, x2, x, y1, y2, y;
        Polar sum;
        x1 = rad * cos(ang);
        x2 = xy.rad * cos(xy.ang);
        y1 = rad * sin(ang);
        y2 = xy.rad * sin(xy.ang);
        x = x1 + x2;
        y = y1 + y2;
        sum.ang = tan(y / x);
        sum.rad = hypot(x, y);
        return(sum);
    }
    void read() {
        wcout << L"Введите угол: ";
        wcin >> ang;
        if (ang < 0 || ang > 360) {
            cout << L"Неверное значение угла."<<endl;
            exit(1);
        }
        wcout << L"Введите радиус: ";
        wcin >> rad;
    }
    void display() {
        wcout << L"Угол: " << ang << L"\nРадиус : " << rad << endl;
    }
};

class sterling { //11 - фунты стерлингов
private:
    long pounds;
    int shilling;
    int pence;
public:
    sterling() : pounds(0), shilling(0), pence(0) {}
    sterling(double decster) {
        pounds = trunc(decster);
        shilling = trunc((decster - pounds) * 20);
        pence = (((decster - pounds) * 20) - shilling) * 12;
    }
    sterling(long po, int sh, int pe) : pounds(po), shilling(sh), pence(pe) {}
    void getSter() {
        wcout << L"Введите денежную сумму в формате 9.15.10: £";
        wchar_t trash;
        wcin >> pounds >> trash >> shilling >> trash >> pence;
        wcout << endl;
    }
    void putSter() {
        wcout << L"£" << pounds << "." << shilling << "." << pence << endl;
    }
    double db() {
        float sum = pence + shilling * 12 + (pounds * 20) * 12;
        double des_funt = (sum / 2.4) / 100;
        return des_funt;
    }
    sterling operator + (sterling str2) {
        int sumpens = (pounds * 20 * 12 + shilling * 12 + pence) + (str2.pounds * 20 * 12 + str2.shilling * 12 + str2.pence);
        long po = sumpens / (20 * 12);
        int s = sumpens % (20 * 12) / 12;
        int pe = sumpens % (20 * 12) % 12;
        return sterling(po, s, pe);
    }
    sterling operator - (sterling str2) {
        int sumpens = (pounds * 20 * 12 + shilling * 12 + pence) - (str2.pounds * 20 * 12 + str2.shilling * 12 + str2.pence);
        long po = sumpens / (20 * 12);
        int s = sumpens % (20 * 12) / 12;
        int pe = sumpens % (20 * 12) % 12;
        return sterling(po, s, pe);
    }
    sterling operator * (double str2) {
        int sumpens = (pounds * 20 * 12 + shilling * 12 + pence) * (str2);
        long po = sumpens / (20 * 12);
        int s = sumpens % (20 * 12) / 12;
        int pe = sumpens % (20 * 12) % 12;
        return sterling(po, s, pe);
    }
    sterling operator / (sterling str2) {
        int sumpens = (pounds * 20 * 12 + shilling * 12 + pence) / (str2.pounds * 20 * 12 + str2.shilling * 12 + str2.pence);
        long po = sumpens / (20 * 12);
        int s = sumpens % (20 * 12) / 12;
        int pe = sumpens % (20 * 12) % 12;
        return sterling(po, s, pe);
    }
    sterling operator / (double str2) {
        int sumpens = (pounds * 20 * 12 + shilling * 12 + pence) / (str2);
        long po = sumpens / (20 * 12);
        int s = sumpens % (20 * 12) / 12;
        int pe = sumpens % (20 * 12) % 12;
        return sterling(po, s, pe);
    }
};

class bMoney { //8 - деньги
private: long double money;
public: bMoney() {
    money = 0.0L;
}
      bMoney(const wchar_t s[]) {
          mstold(s);
      }
      void madd(bMoney m1, bMoney m2) {
          money = m1.money + m2.money;
      }
      void getmoney() {
          wchar_t tms[80];
          wcout << L"Введите денежную сумму (например, $1,234,567.99):\n";
          wcin >> tms;
          mstold(tms);
      }
      void putmoney() {
          wchar_t tms[80];
          ldtoms(tms);
          wcout << tms << endl;
      }

      long double mstold(const wchar_t str[]) {
          wchar_t temp[80];
          int j = 0;

          for (int i = 0; i < wcslen(str); i++) {
              wchar_t ch = str[i];

              if ((ch >= L'0') && (ch <= L'9'))
                  temp[j++] = ch;
              else if (ch == L'.')
                  temp[j++] = ch;
          }
          temp[j] = L'\0';

          wchar_t* stop;

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

          for (j = n; j < len - 3; j++) {
              str[i++] = ustring[j];

              if (((j - n + 1) % 3 == 0) && (j != len - 3 - 1))
                  str[i++] = delim3;
          }

          str[i++] = ustring[j++];
          str[i++] = ustring[j++];
          str[i++] = ustring[j];
          str[i] = L'\0';
      }

      bMoney operator+ (bMoney x) {
          bMoney y;
          y.money = money + x.money;
          return(y);
      }
      bMoney operator- (bMoney x) {
          bMoney y;
          y.money = money - x.money;
          return(y);
      }
      bMoney operator* (long double x) {
          bMoney y;
          y.money = money * x;
          return(y);
      }
      bMoney operator* (bMoney x) {
          bMoney y;
          y.money = money * x.money;
          return(y);
      }
      bMoney operator/ (bMoney x) {
          bMoney y;
          y.money = money / x.money;
          return (y);
      }
      bMoney operator/ (long double x) {
          bMoney y;
          y.money = money / x;
          return(y);
      }
      //12 - перевод стерлингов в доллары
      bMoney(sterling s) {
          money = s.db() * 50;
      }
      operator sterling() {
          return sterling(money / 50);
      }

};

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    wcout << LR"(1. Добавьте в класс Distance из программы ENGLPLUS перегруженную  операцию -, которая вычисляет
разность двух интервалов.Она должна позволять выполнение выражений типа dist3=distl-dist2;.
Предполагаем, что эта операция никогда не будет использоваться для вычитания большего интервала из меньшего
(так как отрицательного интервала быть не может).)"<<endl;

    Distance dist1(12, 0.1), dist2(13, 10.4), dist3, dist4;
    dist3.getdist();
    dist4 = dist1 + dist2 - dist3;
    dist4.showdist();

    wcout<<"\n"<<LR"(2. Напишите программу, которая заменяет перегруженную операцию + на перегруженную операцию +=
в программе STRPLUS. Эта операция должна позволять записывать выражения типа: si += s2 где s2 прибавляется
(объединяется) к строке si, результат при этом остается в si. Операция должна также позволять использовать
результат для других вычислений, например в выражениях типа: s3 = si += s2 )"<<endl;

    String s1;
    s1.put(1);
    String s2;
    s2.put(2);
    String s3;
    s3.put(3);
    s1 += s2 += s3;
    s1.display();
    wcout<<endl;

    wcout << "\n" << LR"(3. Модифицируйте класс time из упражнения 3 лабораторной работы №4 так, чтобы вместо
метода add_time() можно было использовать операцию + для складывания двух значений времени.
Напишите программу для проверки класса.)" << endl;

    Time t1(10, 28, 12), t2(9, 39, 58), t3;
    t3 = t3 + t1 + t2;
    t3.display();
    wcout << endl;

    wcout << "\n" << LR"(4. Создайте класс Int, основанный на упражнении 1 из лабораторной работы № 4.
Перегрузите четыре целочисленных арифметических операции (+, -, * и /) так, чтобы их можно было использовать
для операций с объектами класса Int. Если результат какойлибо из операций выходит за границы типа int
(в 32- битной системе), имеющие значение от 2 14 7 483 648 до -2 147 483 648, то операция должна послать
сообщение об ошибке и завершить программу. Такие тины данных полезны там, где ошибки могут быть вызваны
арифметическим переполнением, которое недопустимо. Подсказка: для облегчения проверки переполнения выполняйте
вычисления с использованием типа long double. Напишите программу для проверки этого класса.)" << endl;

    Int Int1(14), Int2(16), Int3(15), Int4(3), Int5;
    Int3 = Int3 / Int4;
    Int5 = Int1 + Int2 * Int3;
    wcout << "Int = ";
    Int5.display();
    wcout << endl;

    wcout << "\n" << LR"(5. Пополните класс time, рассмотренный в упражнении 3, перегруженными операциями
увеличения (++) и уменьшения (--), которые работают в обеих, префиксной и постфиксной, формах записи и
возвращают значение. Дополните функцию main(), чтобы протестировать эти операции.)" << endl;

    Time time_1(4, 1, 6), time_2(6, 9, 4), time_sum, temp;
    time_sum = time_1 + time_2;
    wcout << L"Время1: ";
    time_1.display();
    wcout << L"Время2: ";
    time_2.display();
    wcout << L"Сумма: ";
    time_sum.display();
    ++time_sum;
    wcout << L"++Сумма: ";
    time_sum.display();
    --time_sum;
    wcout << L"--Сумма: ";
    time_sum.display();
    wcout << L"Сумма++: ";
    temp = time_sum++;
    temp.display();
    wcout << L"Сумма--: ";
    temp = time_sum--;
    temp.display();
    wcout << endl;

    wcout << "\n" << LR"(6. Добавьте в класс time из упражнения 5 возможность вычитать значения времени,
используя перегруженную операцию -, и умножать эти значения, используя тип float и перегруженную операцию *. )" << endl;

    Time time_11(3, 5, 2), time_21(2, 5, 1), time_sum1, temp1;
    time_sum1 = time_11 + time_21;
    wcout << L"Время1: ";
    time_11.display();
    wcout << L"Время2: ";
    time_21.display();
    wcout << L"Разность: ";
    time_sum1 = time_11 - time_21;
    time_sum1.display();
    wcout << L"Произведение: ";
    time_sum1 = time_11 * time_21;
    time_sum1.display();
    wcout << endl;

    wcout << "\n" << LR"(7. Модифицируйте класс fraction в четырехфункциональном дробном калькуляторе 
из упражнения 11 лабораторной работы %4 так, чтобы он использовал перегруженные операции сложения,
вычитания, умножения и деления. (Вспомните правила арифметики с дробями в упражнении 12 лабораторной
работы №2 «Циклы и ветвления».) Также перегрузите операции сравнения == и != и используйте их для
выхода из цикла, когда пользователь вводит 0/1, 0 и 1 значения двух частей дроби. Вы можете
модифицировать и функцию lowterms() так, чтобы она возвращала значение ее аргумента,
уменьшенное до несократимой дроби.)" << endl;

    Fraction FF1{}, FF2{}, FF6;
    FF1.add();
    FF2.add();
    wcout << L"Сумма: ";
    FF6 = FF1 + FF2;
    FF6.lowterms();
    FF6.display();
    wcout << L"Разность: ";
    FF6 = FF1 - FF2;
    FF6.lowterms();
    FF6.display();
    wcout << L"Произведение: ";
    FF6 = FF1 * FF2;
    FF6.lowterms();
    FF6.display();
    wcout << L"Частное: ";
    FF6 = FF1 / FF2;
    FF6.lowterms();
    FF6.display();

    wcout << "\n" << LR"(8. Модифицируйте класс bМоnеу из упражнения 12 лабораторной
работы №5 «Массивы и строки», включив арифметические операции, выполненные с помощью
перегруженных операций: bМоnеу = bМоnеу + bМоnеу bМоnеу = bМоnеу – bМоnеу;
bМоnеу = bМоnеу * long double (цена за единицу времени, затраченного на изделие);
long double = bМоnеу / bМоnеу (общая цена, деленная на цену за изделие);
bМоnеу = bМоnеу / long double (общая цена, деленная на количество изделий).
Заметим, что операция / перегружена дважды. Компилятор может различить оба варианта,
так как их аргументы разные. Помним, что легче выполнять арифметические операции с объектами
класса bМоnеу, выполняя те же операции с его long double данными.)" << endl;

    bMoney money1, money2, moneysum;
    long double result = 0, num = 0;

    do {
        money1.getmoney();
        money2.getmoney();
        moneysum = money1 + money2;
        wcout << L"Сумма: ";
        moneysum.putmoney();
        moneysum = money1 - money2;
        wcout << L"Разность: ";
        moneysum.putmoney();
        moneysum = money1 * money2;
        wcout << L"Произведение: ";
        moneysum.putmoney();
        moneysum = money1 / money2;
        wcout << L"Частное: ";
        moneysum.putmoney();
        wcout << L"Введите число: ";
        wcin >> num;
        moneysum = money1 * num;
        wcout << L"Произведение суммы1 на число: ";
        moneysum.putmoney();
        moneysum = money1 / num;
        wcout << L"Частное суммы1 и числа: ";
        moneysum.putmoney();
        wcout << L"Ввести следующую сумму? y,n: ";
        wcin.get();
    } while (wcin.get() != 'n');

    wcout << "\n" << LR"(9.	Дополните класс safearray из программы ARR0VER3 так, чтобы
пользователь мог определять и верхнюю, и нижнюю границы массива (например, индексы, 
начинающиеся с 100 и заканчивающиеся 200). Имеем перегруженную операцию доступа к членам массива,
проверяющую индексы каждый раз, когда к массиву нужен доступ, для проверки того,
что мы не вышли за пределы массива. Вам понадобится конструктор с двумя аргументами,
который определяет верхнюю и нижнюю границы. Так как мы еще не изучили, как выделять память динамически,
то данные класса все еще будут размещаться в массиве, состоящем из 100 элементов, но вообще
вы можете преобразовывать индексы массива safearray в индексы реального массива целых чисел
произвольным образом. Например, если пользователь определил диапазон от 100 до 175, то вы можете
преобразовать его в диапазон от агг[0] до агг[75].)" << endl;

    int low, top;
    safearay ar;
    
    do {
        wcout << L"Введите нижнюю границу массива (>=0): ";
        wcin >> low;
        wcout << L"Введите верхнюю границу массива (<=1000 и больше нижней границы): ";
        wcin >> top;
        if (low > top || low<0 || top>1000) wcout<<"Неверно заданы границы. Повторите ввод."<< endl;
    } while (low > top);

    for (int i = low; i < top; i++) ar[i] = rand();
    for (int i = low; i < top; i++) wcout << L"Элемент [" << i << "] = " << ar.getel(i) << endl;

    wcout << "\n" << LR"(10. Создайте класс Polar, который предназначен для хранения полярных
координат (радиуса и угла). Перегрузите операцию + для выполнения сложения для объектов класса Polar.
Сложение двух объектов выполняется путем сложения координат X объектов, а затем координат Y.
Результат будет координатами новой точки. Таким образом, вам нужно будет преобразовать полярные координаты
к прямоугольным, сложить их, а затем обратно преобразовать прямоугольные координаты результата к полярным. )" << endl;

    Polar p1, p2, psum;
    p1.read();
    p2.read();
    psum = p1 + p2;
    wcout << L"Сумма введённых координат: " << endl;
    psum.display();

    wcout << "\n" << LR"(11. Помните структуру sterling? Мы встречались с ней в упражнении 10 главы 2
«Основы программирования на C++», в упражнении 11 главы 5 и в других местах. Преобразуйте ее в класс,
имеющий переменные для фунтов (типа long), шиллингов (типа int) и пенсов (типа int). Создайте в классе
следующие функции: конструктор без аргументов; конструктор с одним аргументом типа double (для преобразования
от десятичных фунтов); конструктор с тремя аргументами: фунтами, шиллингами и пенсами; метод getSterling()
для получения от пользователя значений количества фунтов, шиллингов и пенсов в формате 9.19.11;
метод putSterling() для вывода значений количества фунтов, шиллингов и пенсов в формате 9.19.11;
метод для сложения (sterling + sterling), используя перегруженную операцию +; метод вычитания (sterling - sterling),
используя перегруженную операцию -; метод умножения (sterling * double), используя перегруженную операцию *;
метод деления (sterling / sterling), используя перегруженную операцию /; метод деления (sterling / double),
используя перегруженную операцию /; операцию double (для преобразования к типу double))" << endl;

    sterling s11, s21, sum1;
    double decimal;
    wcout << L"Введите любое число: ";
    wcin >> decimal;
    s11.getSter();
    s21.getSter();
    sum1 = s11 + s21;
    wcout << L"Сумма: ";
    sum1.putSter();
    sum1 = s11 - s21;
    wcout << L"Разность: ";
    sum1.putSter();
    sum1 = s11 * decimal;
    wcout << L"Первая сумма, помноженная на число: ";
    sum1.putSter();
    sum1 = s11 / s21;
    wcout << L"Частное: ";
    sum1.putSter();
    sum1 = s11 / decimal;
    wcout << L"Первая сумма, делённая на число: ";
    sum1.putSter();
    decimal = sum1.db();
    wcout << L"Первая сумма, делённая на число (double): ";
    wcout << decimal << endl;

    wcout << "\n" << LR"(12. Напишите программу, объединяющую в себе классы bMoney из упражнения 8 и sterling
из упражнения 11. Напишите операцию преобразования для преобразования между классами bMoney и sterling, предполагая,
что один фунт (£1.0.0) равен пятидесяти долларам ($50.00). Это приблизительный курс обмена для XIX века,
когда Британская империя еще использовала меру фунты-шиллинги-пенсы. Напишите программу main(), которая позволит
пользователю вводить суммы в каждой из валют и преобразовывать их в другую валюту с выводом результата.
Минимизируйте количество изменений в существующих классах bMoney и sterling.)" << endl;

    int currency;
    bMoney bm;
    sterling st;
    do {

        wcout << L"Введите 1, чтобы перевести доллары в фунты, или 2, чтобы перевести фунты в доллары: ";
        wcin >> currency;

        if (currency == 1) {
            bm.getmoney();
            st = bm;
            wcout << L"В старой английской системе: ";
            st.putSter();
        }
        else if (currency == 2) {
            st.getSter();
            bm = st;
            wcout << L"В долларах: ";
            bm.putmoney();
        }
        else wcout << L"Введено не 1 и не 2."<< endl;

        wcout << L"Перевести другую сумму? y,n: ";
        wcin.get();
    } while (wcin.get() != 'n');

    return 0;
}
