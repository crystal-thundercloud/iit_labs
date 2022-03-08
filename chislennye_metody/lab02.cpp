#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

double func(double x) { //функция в виде (2x-3)^2-e^x
   return(pow(2*x-3, 2)-pow(M_E, x));
}

double iter(double a, double e) {
    return 0;
}

int main()
{
cout<<R"(Вариант 15. Исходное выражение:
(2x-3)^2=e^x)";

double x=0;
double result = (pow(M_E,x/2)-3)/-2;
cout<<"\n"<<result<<"\n"<<func(x);




}
