#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
cout<<R"(Метод Симпсона. Вариант 15:
120
  ∫(x^4dx)/(4x^5+2)
 0)"<<endl;

int n;
cout<<"Введите целое число n: ";
cin>>n;

for (int i=0; i<5; i++) {
    double a = 0, b = 120, h = (b-a)/(2*n), f[2*n+1], x[2*n+1], sum=0;
    
    for (int i=0; i<=2*n; i++) {
        x[i] = a+i*h;
        f[i] = (pow(x[i],4))/((4*pow(x[i],5))+2);
        if (i!=0&&i!=2*n&&i%2==0) f[i]*=2;
        else if (i!=0&&i!=2*n&&i%2!=0) f[i]*=4;
        sum += f[i];
    }
    
    cout<<"n = "<<n<<"\nОтвет, полученный программой: "<<setprecision(15)<<(h/3)*sum
    <<"\nВычисленное вручную значение: 1.23153029472451"<<endl;
    n*=2;
}
return 0;
}
