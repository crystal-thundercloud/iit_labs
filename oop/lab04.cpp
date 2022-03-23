#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void iter(double e) {
    cout<<"\nМетод простых итераций:\n"<<R"(Выражаем x и y из имеющихся уравнений:
x = (sin(y)-1)/2
y = cos(x+0.5)-2)"<<endl;
    
    double x1, y1, x=0, y=0;
    int i=0;
    
    do {
        x1 = x;
        y1 = y;
        x = (sin(y1-1))/2;
        y = cos(x1+0.5)-2;
        i++;
    }
    
    while ((abs(x-x1)>e)||(abs(y-y1)>e));
    
    cout<<"Корни уравнений:\nx = "<<setprecision(13)<<x<<"\ny = "<<y<<"\nНайдены на итерации "<<i<<endl;
}

void newton(double e) {
    cout<<"\nМетод Ньютона:"<<endl;

    double x=0, y=0, f1, f2, f1x, f2x, f1y, f2y, dx, dy;
    
    int i=0;
    
    do {
        f1 = cos(x+0.5)-y-2;
        f2 = sin(y)-2*x-1;
    
        f1x = -sin(x+0.5); //нашли производные по x и y от первого уравнения
        f1y = -1;
        f2x = -2; //нашли производные по x и y от второго уравнения
        f2y = cos(y);
        
        //f1x*dx+f1y*dy = -f1
        //f2x*dx+f2y*dy = -f2
        
        //выражаем dy из второго уравнения, подставляя выраженный dx:
        dy = (f2x*f1-f2*f1x)/(f2y*f1x-f2x*f1y);
        //выражаем dx из первого уравнения:
        dx = (-f1-f1y*dy)/f1x;
    
        x += dx;
        y += dy;
        i++;
    }
    
    while ((abs(dx)>e)||(abs(dy)>e));
    
    cout<<"Корни уравнений:\nx = "<<setprecision(13)<<x<<"\ny = "<<y<<"\nНайдены на итерации "<<i;
}

int main()
{
double e;

cout<<R"(Вариант 15. Исходная система:
{cos(x+0.5)-y=2
{sin(y)-2*x=1)

Введите необходимую точность (e): )";
cin>>e;

iter(e);
newton(e);

return 0;
}
