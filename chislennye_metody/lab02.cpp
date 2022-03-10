#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

double mainfunc(double x) { //функция в виде (2x-3)^2-e^x
    return(pow(2*x-3, 2)-pow(M_E, x));
}

void iter(double x, double e) { //простые итерации
    int i=0;
    double temp;
    do {
        temp=x;
        x=(pow(M_E,x/2)-3)/-2;
        i++;
    }
    while (abs(x-temp)>=e);
    cout<<"\nМетод простых итераций:"<<endl;
    cout<<"Корень x="<<x<<"\nНайден на итерации "<<i<<"\nПри точности "<<e<<endl;
}

void dych(double a, double b, double x, double e) { //дихотомия
    int i=0;
    double temp;
    do {
        temp = x;
        x = (a+b)/2;
        a = mainfunc(x)>0? x: a;
        b = mainfunc(x)<0? x: b;
        i++;
    }
    while (abs(x-temp)>=e);
    cout<<"\nМетод дихотомии:"<<endl;
    cout<<"Корень x="<<x<<"\nНайден на итерации "<<i<<"\nПри точности "<<e<<endl;
}

int main()
{
cout<<R"(Вариант 15. Исходное выражение:
(2x-3)^2=e^x
Введите границы отрезка (а, b при a<b) и точность e (пример: 0 1 0.00000001): )";
double a, b, e;
cin>>a>>b>>e;
while (a>=b) {
    cout<<"Неверные границы отрезка. Задайте a и b ещё раз.\n";
    cin>>a>>b;
}

double x=a;
iter(x, e);
dych(a, b, x, e);

return 0;
}
