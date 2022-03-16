#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double mainfunc(double x) { //функция в виде (2x-3)^2-e^x
    return(pow(2*x-3, 2)-pow(M_E, x));
}

double proizv(double x) { //производная функции в виде 8x-12-e^x
    return(8*x-12-pow(M_E, x));
}

void newton(double x, double e) { //Ньютон
    int i=0;
    double temp;
    do {
        temp=x;
        x=x-(mainfunc(x)/proizv(x));
        i++;
    }
    while (abs(x-temp)>=e);
    cout<<"\nМетод Ньютона:"<<endl;
    cout<<"Корень x="<<setprecision(13)<<x<<"\nНайден на итерации "<<i<<"\nПри точности "<<e<<endl;
}

void hord(double a, double b, double x, double e) { //хорды
    int i=0;
    double temp;
    do {
        temp = x;
        x = a-(((b-a)*mainfunc(a))/(mainfunc(b)-mainfunc(a)));
        a = mainfunc(x)>0? x: a;
        b = mainfunc(x)<0? x: b;
        i++;
    }
    while (abs(x-temp)>=e);
    cout<<"\nМетод хорд:"<<endl;
    cout<<"Корень x="<<setprecision(13)<<x<<"\nНайден на итерации "<<i<<"\nПри точности "<<e<<endl;
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
newton(x, e);
hord(a, b, x, e);

return 0;
}
