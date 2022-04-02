#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
cout<<R"(Метод трапеций. Вариант 15:
120
  ∫(x^4dx)/(4x^5+2)
 0)"<<endl;

int n;

cout<<"Введите целое число n: "; //450
cin>>n;

for (int i=0; i<5; i++) {    
    double a = 0, b = 120, h = (b-a)/n, f[n], x[n], fa, fb, sum=0;
    fa = (pow(a,4))/((4*pow(a,5))+2);
    fb = (pow(b,4))/((4*pow(b,5))+2);
        
    for (int i=1; i<n; i++) {
        x[i] = a+i*h;
        f[i] = (pow(x[i],4))/((4*pow(x[i],5))+2);
        sum += f[i];
    }
        
    cout<<"n = "<<n<<"\nОтвет, полученный программой: "<<setprecision(15)<<h*(0.5*(fa+fb)+sum)
    <<"\nВычисленное вручную значение: 1.23153029472451"<<endl;
    n*=2;
}
return 0;
}
