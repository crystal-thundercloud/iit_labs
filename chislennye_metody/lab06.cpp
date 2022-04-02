#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
cout<<R"(Метод прямоугольников. Вариант 15:
120
  ∫(x^4dx)/(4x^5+2)
 0)"<<endl;

int n=1;
cout<<"Введите целое число n: "; //13000
cin>>n;

while (n!=0) {
    double a = 0, b = 120, h = (b-a)/n, f[n], x[n], sum=0;
    
    for (int i=1; i<=n; i++) {
        x[i-1] = a+(i-1)*h;
        f[i-1] = (pow(x[i-1],4))/((4*pow(x[i-1],5))+2);
        sum += f[i-1];
    }
    
    cout<<"Ответ, полученный программой: "<<setprecision(14)<<h*sum<<"\n"<<"Вычисленное вручную значение: 1.23153029472451"<<endl;
    cout<<"Ввести другое n: ";
    cin>>n;
}
return 0;
}
