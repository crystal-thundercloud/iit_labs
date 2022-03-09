#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

double mainfunc(double x) { //функция в виде (2x-3)^2-e^x
    return(pow(2*x-3, 2)-pow(M_E, x));
}

double iter(double x) {
    return((pow(M_E,x/2)-3)/-2);
}

/*double dych(double a, double b) {
    return((a+b)/2);
}*/

int main()
{
cout<<R"(Вариант 15. Исходное выражение:
(2x-3)^2=e^x
Введите границы отрезка (а, b при a<b) и точность e: )";
double a, b, e;
cin>>a>>b>>e;
while (a>=b) {
    cout<<"Неверные границы отрезка. Задайте a и b ещё раз.\n";
    cin>>a>>b;
}

double x=0;

cout<<"\n"<<iter(x)<<"\n"<<mainfunc(x);




}
