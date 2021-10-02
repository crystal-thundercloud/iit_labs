/*
Решить линейное уравнение A·x + B = 0, 
заданное своими коэффициентами A и B 
(коэффициент A не равен 0). 
*/

#include <stdio.h>
#include <math.h>

int main()
{
    float a, x, b;
    
    printf("Введите A (не равный нулю): ");
    scanf("%g", &a);
    printf("Введите B: ");
    scanf("%g", &b);
    
    if (a!=0) printf("Для уравнения %g*x+%g=0 x=%g", a, b, -b/a);
    else printf("Нельзя посчитать для a=0");
}
