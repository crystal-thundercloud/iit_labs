#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{

/*
Даны целые положительные числа A и B (A < B). Вывести все целые числа от A до B включительно;
при этом каждое число должно выводиться столько раз, каково его значение (например, число 3 выводится 3 раза).
*/

int a, b;

cout<<R"(Даны целые положительные числа A и B (A < B). Вывести все целые числа от A до B включительно;
при этом каждое число должно выводиться столько раз, каково его значение (например, число 3 выводится 3 раза).)"<<"\n"<<endl;

cout<<"Введите целое число A (>0): ";

cin>>a;

cout<<"Введите целое число B (>A): ";

cin>>b;

for (float i = a; i<b+1; i++) {
    for (float j = i; j>0; j--) {
        cout<<i;
    }
    cout<<"\n";
}

/*
Даны положительные числа A и B (A > B). На отрезке длины A размещено максимально возможное количество
отрезков длины B (без наложений). Не используя операции умножения и деления, найти длину незанятой части отрезка A.
*/

cout<<"\n"<<R"(Даны положительные числа A и B (A > B). На отрезке длины A размещено максимально возможное количество
отрезков длины B (без наложений). Не используя операции умножения и деления, найти длину незанятой части отрезка A.)"<<"\n"<<endl;

cout<<"Введите целое число A (>0): ";

cin>>a;

cout<<"Введите целое число B (<A): ";

cin>>b;

while (a>=b) {
    a-=b;
}
cout<<"Незанятая часть A: "<<a<<endl;

/*
Дано целое число N (> 1). Вывести наименьшее из целых чисел K, для которых
сумма 1 + 2 + . . . + K будет больше или равна N, и саму эту сумму.
*/

cout<<"\n"<<R"(Дано целое число N (> 1). Вывести наименьшее из целых чисел K, для которых
сумма 1 + 2 + . . . + K будет больше или равна N, и саму эту сумму.)"<<"\n"<<endl;

cout<<"Введите целое число (>1): ";

cin>>a;
b = 0;

for (int i = 1; i<a+1; i++) {
    if (b<a) {
        b +=i;
        cout<<i;
        if (b<a) cout<<" + ";
    }
}

cout<<" = "<<b<<" >= "<<a<<endl;

/*
Начальный вклад в банке равен 1000 руб. Через каждый месяц размер вклада увеличивается
на P процентов от имеющейся суммы (P — вещественное число, 0 < P < 25). По данному P определить,
через сколько месяцев размер вклада превысит 1100 руб., и вывести найденное
количество месяцев K (целое число) и итоговый размер вклада S (вещественное число).
*/

cout<<"\n"<<R"(Начальный вклад в банке равен 1000 руб. Через каждый месяц размер вклада увеличивается
на P процентов от имеющейся суммы (P — вещественное число, 0 < P < 25). По данному P определить,
через сколько месяцев размер вклада превысит 1100 руб., и вывести найденное
количество месяцев K (целое число) и итоговый размер вклада S (вещественное число).)"<<"\n"<<endl;

float p, sum;

cout<<"Введите процентную ставку P (0<P<25): ";

cin>>p;

sum = 1000.0;
b=0;

while (sum<=1100) {
    sum += (sum*p)/100;
    b += 1;
}

cout<<"Через "<<b<<" мес. вклад составит "<<sum<<" руб."<<endl;

/*
Даны целые положительные числа A и B. Найти их наибольший общий делитель (НОД), используя алгоритм Евклида
*/

cout<<"\n"<<R"(Даны целые положительные числа A и B. Найти их наибольший общий делитель (НОД), используя алгоритм Евклида)"<<"\n"<<endl;

cout<<"Введите целое положительное число A: ";
cin>>a;

cout<<"Введите целое положительное число B: ";
cin>>b;

cout<<"НОД для чисел "<<a<<" и "<<b<<" = ";

while ((a!=0)&&(b!=0)) {
    if (a>b) a = a%b;
    else b = b%a;
}
cout<<a+b<<endl;

/*
Дано целое число N (> 1), являющееся числом Фибоначчи: N = FK.
Найти целое число K — порядковый номер числа Фибоначчи N.
*/

cout<<"\n"<<R"(Дано целое число N (> 1), являющееся числом Фибоначчи: N = FK.
Найти целое число K — порядковый номер числа Фибоначчи N.)"<<"\n"<<endl;

int n;

cout<<"Введите число Фибоначчи: ";
cin>>n;

p = 0;
a = 0;
b = 1;
sum = a+b;

while (sum<n) {
    a = b;
    b = sum;
    sum = a+b;
    p++;
}

cout<<"Порядковый номер числа "<<n<<" = "<<p;

}
