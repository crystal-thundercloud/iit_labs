#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
cout<<R"(Вариант 15:
120
  ∫(x^4dx)/(4x^5+2)
 0)"<<endl;

int n;

cout<<"Введите целое число n>=1000: "; //13000
cin>>n;

double a = 0, b = 120, h = (b-a)/n, f[n+1], x[n+1], sum;

for (int i=0; i<=n+1; i++) {
    x[i-1] = a+(i-1)*h;
    f[i-1] = (pow(x[i-1],4))/((4*pow(x[i-1],5))+2);
    sum += f[i-1];
}

cout<<setprecision(20)<<h*sum<<"\n"<<"Вычисленное значение: 1.23153"<<endl;

return 0;
}
