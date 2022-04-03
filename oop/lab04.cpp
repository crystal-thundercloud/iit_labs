#define USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

float circarea(float r) { //1 - площадь круга
    return M_PI*pow(r,2);
}

double power(double n, int p=2) { //2 - степень числа
    return pow(n,p);
}

void zeroSmaller(int a, int b) { //3 - меньшее число приравнивается к нулю
    if (a<b) a=0;
    else if (a==b) a=a;
    else b=0;
    cout<<"a = "<<a<<", b = "<<b<<endl;
}

struct Distance { //4 - длины в американской системе
    int feet;
    float inches;
};

Distance smallerDistance(Distance a, Distance b) { //4 - возвращение наибольшей дистанции
    if (a.feet>b.feet) return a;
    else if (a.feet==b.feet) {
        if (a.inches>b.inches) return a;
        else if (a.inches==b.inches) return a;
        else return b;
    }
    else return b;
}

long hms_to_secs(int hh, int mm, int ss) { //5 - время в секундах
    return hh*3600+mm*60+ss;
}

struct Time { //6 - время
    int hours, minutes, seconds;
};

long time_to_secs(Time tm) { //6 - перевод времени из структуры в секунды
    return ((tm.hours*3600)+(tm.minutes*60)+tm.seconds);
}

Time secs_to_time(long secs) {//6 - перевод времени из секунд в структуру
    Time tm1;
    tm1.hours = secs/3600;
    tm1.minutes = (secs-(tm1.hours*3600))/60;
    tm1.seconds = (secs-(tm1.hours*3600))-(tm1.minutes*60);
    return tm1;
}

double power(char n, int p=2) { //7 - перегруженные power с разными значениями
    return pow(n,p);
}

double power(int n, int p=2) { //7 - перегруженные power с разными значениями
    return pow(n,p);
}

double power(long n, int p=2) { //7 - перегруженные power с разными значениями
    return pow(n,p);
}

double power(float n, int p=2) { //7 - перегруженные power с разными значениями
    return pow(n,p);
}

void swap(int a, int b) { //8 - обмен значениями
    a+=b;
    b=a-b;
    a-=b;
    cout<<"a = "<<a<<", b = "<<b<<endl;
}

void swapTime(Time a, Time b) { //9 - обмен значениями времени
    char trash = ':';
    a.hours+=b.hours;
    b.hours=a.hours-b.hours;
    a.hours-=b.hours;
    a.minutes+=b.minutes;
    b.minutes=a.minutes-b.minutes;
    a.minutes-=b.minutes;
    a.seconds+=b.seconds;
    b.seconds=a.seconds-b.seconds;
    a.seconds-=b.seconds;
    cout<<"tm1 = "<<a.hours<<trash<<a.minutes<<trash<<a.seconds<<", tm2 = "<<b.hours<<trash<<b.minutes<<trash<<b.seconds<<endl;
}

int callTimes(int& times) { //10 - сколько раз вызвали функцию
    //меняет значение при указателе в аргументе
    return times++;
}

int callTimes2(int times) { //10 - сколько раз вызвали функцию
    //меняет значение если присвоить её значение переменной, которая станет аргументом следующего вызова
    return ++times;
}

struct sterling { //11 - стерлинги
    int pounds, shillings, pence;
};

sterling getster(sterling st) { //11 - функция, записывающая сумму, введённую пользователем, в структуру sterling
    char trash;
    cin>>st.pounds>>trash>>st.shillings>>trash>>st.pence;
    return st;
}

sterling sumster(sterling st1, sterling st2) { //11 - функция, суммирующая две суммы типа sterling
    sterling sum;
    sum.pence = st1.pence + st2.pence;
    
    while (sum.pence>=12&&sum.pence!=0) {
        sum.pence-=12;
        sum.shillings++;
    }
    sum.shillings += st1.shillings + st2.shillings;
    
    while (sum.shillings>=20&&sum.shillings!=0) {
        sum.shillings-=20;
        sum.pounds++;
    }
    
    sum.pounds += st1.pounds+st2.pounds;
    
    return sum;
}

void returnster(sterling st) { //11 - функция, выводящая значение типа sterling
    cout<<st.pounds<<"."<<st.shillings<<"."<<st.pence;
}

struct fraction { //12 структура - числитель и знаменатель дроби
    int chis, znam;
};

fraction fadd(fraction fr1, fraction fr2) { //12 - сложение дробей
    fraction plus;
    plus.chis = (fr1.chis*fr2.znam)+(fr2.chis*fr1.znam);
    plus.znam = fr1.znam*fr2.znam;
    return plus;
}

fraction fsub(fraction fr1, fraction fr2) { //12 - вычитание дробей
    fraction minus;
    minus.chis = (fr1.chis*fr2.znam)-(fr2.chis*fr1.znam);
    minus.znam = fr1.znam*fr2.znam;
    return minus;
}

fraction fmul(fraction fr1, fraction fr2) { //12 - умножение дробей
    fraction mnoj;
    mnoj.chis = fr1.chis*fr2.chis;
    mnoj.znam = fr1.znam*fr2.znam;
    return mnoj;
}

fraction fdiv(fraction fr1, fraction fr2) { //12 - деление дробей
    fraction del;
    del.chis = fr1.chis*fr2.znam;
    del.znam = fr2.chis*fr1.znam;
    return del;
}

int main()
{
cout<<R"(1. Напишите функцию с именем circarea(), которая вычисляет площадь круга.
Функция   должна принимать один аргумент типа float и возвращать значение типа float.
Напишите функцию main(), которая просит пользователя ввести значение радиуса,
вызывает функцию circarea(), а затем отображает результат вычисления на экране.)"<<endl;

float r;
cout<<"Введите радиус круга: ";
cin>>r;
cout<<"Площадь круга с радиусом "<<r<<" = "<<circarea(r)<<endl;

cout<<"\n"<<R"(2. Возведение числа n в степень р — это умножение числа n на себя р раз. 
Напишите функцию с именем power(), которая в качестве аргументов принимает значение типа 
double для n и значение типа int для р и возвращает значение типа double.
Для аргумента, соответствующего степени числа, задайте значение по умолчанию, равное 2,
чтобы при отсутствии показателя степени при вызове функции число n возводилось в квадрат. 
Напишите функцию main(), которая запрашивает у пользователя ввод аргументов для функции power(),
и отобразите на экране результаты ее работы.)"<<endl;

double n;
int p;

cout<<"Введите число n и степень p: ";
cin>>n>>p;

cout<<n<<"^"<<p<<" = "<<power(n, p)<<endl;

cout<<"\n"<<R"(3. Напишите функцию с именем zeroSmaller(), в которую передаются с помощью ссылок
два аргумента типа int, присваивающую меньшему из аргументов нулевое значение.
Напишите программу для проверки работы функции.)"<<endl;

int a, b;
cout<<"Введите два числа:\na = ";
cin>>a;
cout<<"b = ";
cin>>b;

zeroSmaller(a, b);

cout<<"\n"<<R"(4. Напишите функцию, принимающую в качестве аргументов два значения типа Distance
и возвращающую значение наибольшего из аргументов. Ответы в приложении №1.)"<<endl;

Distance a1, b1;
cout<<"Введите первую дистанцию: ";
cin>>a1.feet>>a1.inches;
cout<<"Введите вторую дистанцию: ";
cin>>b1.feet>>b1.inches;

cout<<"Наибольшая дистанция = "<<smallerDistance(a1, b1).feet<<" "<<smallerDistance(a1, b1).inches<<endl;

cout<<"\n"<<R"(5. Напишите функцию с именем hms_to_secs(), имеющую три аргумента типа int: часы, минуты и секунды.
Функция должна возвращать эквивалент переданного ей временного значения в секундах (типа long).
Создайте программу, которая будет циклически запрашивать у пользователя ввод значения часов, минут и секунд
и выводить результат работы функции на экран. )"<<endl;

int hh, mm, ss;
char trash, repeat;

do {
    cout<<"Введите значение времени (например, 12:57:19): ";
    cin>>hh>>trash>>mm>>trash>>ss;
    cout<<"Введённое время в секундах: "<<hms_to_secs(hh,mm,ss)<<endl;
    cout<<"Ввести другое значение времени? y, n: ";
    cin>>repeat;
}

while  (repeat=='y');

cout<<"\n"<<R"(6. Модифицируйте программу, описанную в упражнении 11 предыдущей лабораторной работы «Структуры»,
складывающую два структурных значения типа time. Теперь программа должна включать в себя две функции.
Первая, time_to_secs(), принимает в качестве аргумента значение типа time и возвращает эквивалентное значение
в секундах типа long. Вторая, secs_to_time(), в качестве аргумента принимает число секунд, имеющее тип long,
а возвращает эквивалентное значение типа time.)"<<endl;

Time tm1, tm2, tmsum;
int sumsecs;

cout<<"Введите первое значение времени (например, 12:57:19): ";
cin>>tm1.hours>>trash>>tm1.minutes>>trash>>tm1.seconds;
cout<<"Введите второе значение времени: ";
cin>>tm2.hours>>trash>>tm2.minutes>>trash>>tm2.seconds;

sumsecs = time_to_secs(tm1)+time_to_secs(tm2);

cout<<"Сумма введённых значений: "<<secs_to_time(sumsecs).hours<<trash<<secs_to_time(sumsecs).minutes<<trash<<secs_to_time(sumsecs).seconds<<endl;

cout<<"\n"<<R"(7. Взяв в качестве основы функцию power() из упражнения 2, работающую только со значением типа double,
создайте перегруженные функции с этим же именем, принимающими в качестве аргумента значения типа char, int, long и float.
Напишите программу, вызывающую функцию power() со всеми возможными типами аргументов.)"<<endl;

cout<<"char: "<<power('ы', 5)<<endl;
cout<<"int: "<<power(7, 5)<<endl;
cout<<"long: "<<power(2L, 5)<<endl;
cout<<"float: "<<power(10.1F, 5)<<endl;

cout<<"\n"<<R"(8. Напишите функцию с именем swap(), обменивающую значениями два своих аргумента типа int
(обратите внимание, что изменяться должны значения переменных из вызывающей программы, а не локальных переменных функции).
Выберите способ передачи аргументов. Напишите вызывающую программу main(), использующую данную функцию.)"<<endl;

cout<<"Введите два числа:\na = ";
cin>>a;
cout<<"b = ";
cin>>b;

swap(a, b);

cout<<"\n"<<R"(9. Переработайте программу из упражнения 8 так, чтобы функция swap() 
принимала в качестве аргументов значения типа time (см. упражнение 6).)"<<endl;

cout<<"Введите первое значение времени (например, 12:57:19): tm1 = ";
cin>>tm1.hours>>trash>>tm1.minutes>>trash>>tm1.seconds;
cout<<"Введите второе значение времени: tm2 = ";
cin>>tm2.hours>>trash>>tm2.minutes>>trash>>tm2.seconds;

swapTime(tm1, tm2);

cout<<"\n"<<R"(10. Напишите функцию, которая при каждом вызове будет выводить на экран количество раз,
которое она вызывалась ранее. Напишите программу, которая будет вызывать данную функцию не менее 10 раз.
Попробуйте реализовать данную функцию двумя различными способами: с использованием глобальной переменной
и статической локальной переменной для хранения числа вызовов функции. Какой из способов предпочтительней?
Почему для решения задачи нельзя использовать обычную локальную переменную?)"<<endl;

cout<<"Вызов функции с указателем в аргументе: "<<endl;
int times = 0;
for (int i=0; i<10; i++) {
    cout<<"Функция была вызвана "<<callTimes(times)<<" раз(а)"<<endl;
}

cout<<"Вызов функции с присваиванием её значения переменной и вызовом этой переменной в качестве аргумента: "<<endl;
times = -1;
for (int i=0; i<10; i++) {
    cout<<"Функция была вызвана "<<callTimes2(times)<<" раз(а)"<<endl;
    times = callTimes2(times);
}

cout<<"\n"<<R"(11. Напишите программу, использующую структуру sterling, которая описана в упражнении 10 лабораторной работы 2 «Структуры».
Программа должна получать от пользователя значения двух денежных сумм, выраженных в фунтах, шиллингах и пенсах,
складывать эти значения и выводить результат на экран в том же формате. Необходимо разработать три функции.
Первая из них должна получать от пользователя число фунтов, шиллингов и пенсов и возвращать соответствующее значение типа sterling.
Вторая функция должна принимать в качестве аргументов два значения типа sterling, складывать их и возвращать значение, также имеющее тип sterling.
Третья функция должна принимать аргумент типа sterling и выводить его значение на экран.)"<<endl;

sterling st1, st2, stsum;

cout<<"Введите первую сумму (например, 10.5.11): £";
st1 = getster(st1);
cout<<"Введите вторую сумму: £";
st2 = getster(st2);

stsum = sumster(st1, st2);
cout<<"Сумма = £";
returnster(stsum);


cout<<"\n"<<R"(12. Модифицируйте калькулятор, созданный в упражнении 12 лабораторной работы 2 «Структуры», так,
чтобы каждая арифметическая операция выполнялась с помощью функции. Функции могут называться fadd(), fsub(), fmul() и fdiv().
Каждая из функций должна принимать два структурных аргумента типа fraction и возвращать значение того же типа.)"<<endl;

char oper, povtor;
fraction fr1, fr2, plus, minus, mnoj, del;

do {
    cout<<"Введите выражение из двух операндов-дробей (например, 1/2-3/4): ";
    cin>>fr1.chis>>trash>>fr1.znam>>oper>>fr2.chis>>trash>>fr2.znam;
    switch (oper) {
        case '+':
            plus = fadd(fr1, fr2);
            cout<<fr1.chis<<trash<<fr1.znam<<" + "<<fr2.chis<<trash<<fr2.znam<<" = "<<plus.chis<<trash<<plus.znam<<endl;
            break;
        case '-':
            minus = fsub(fr1, fr2);
            cout<<fr1.chis<<trash<<fr1.znam<<" - "<<fr2.chis<<trash<<fr2.znam<<" = "<<minus.chis<<trash<<minus.znam<<endl;
            break;
        case '*':
            mnoj = fmul(fr1, fr2);
            cout<<fr1.chis<<trash<<fr1.znam<<" * "<<fr2.chis<<trash<<fr2.znam<<" = "<<mnoj.chis<<trash<<mnoj.znam<<endl;
            break;
        case '/':
            del = fdiv(fr1, fr2);
            cout<<fr1.chis<<trash<<fr1.znam<<" / "<<fr2.chis<<trash<<fr2.znam<<" = "<<del.chis<<trash<<del.znam<<endl;
            break;
    }
    cout<<"Ввести новое выражение? y,n: ";
    cin>>povtor;
}

while (povtor=='y');

return 0;
}
