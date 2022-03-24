#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout<<"Метод прогонки: "<<endl;
    const int n=100;
    int a=1, b=2, c=1, d=10*30; //номер в списке - 30
    double u[n+1], v[n+1], x[n+1];
    
    u[1] = -(double)c/b; //-1/2, но считало как 0, так как c и b - int
    v[1] = d/b;
    
    for (int i=2; i<=n; i++) {
        if (i==n) c=0;
        u[i] = -c/(a*u[i-1]+b);
        v[i] = (d-a*v[i-1])/(a*u[i-1]+b);
    }
    
    c=1;
    
    x[n] = (d-a*v[n-1])/(a*u[n-1]+b);
    cout<<"x[100] = "<<x[n]<<endl;
    
    for (int i = n-1; i>0; i--) {
        x[i] = u[i]*x[i+1]+v[i];
        if (i>9) cout<<setw(3)<<"x["<<i<<"] = "<<x[i]<<endl;
        else cout<<setw(4)<<"x["<<i<<"] = "<<x[i]<<endl;
        if (i==1) cout<<b*x[i]+c*x[i+1]-d;
    }

    return 0;
}
