/*
Найти решение системы линейных уравнений вида 
A1·x + B1·y = C1, 
A2·x + B2·y = C2
*/

#include <stdio.h>

int main()
{
    float a1, b1, c1, a2, b2, c2, x, y;
    
    printf("Введите значения первого уравнения: ");
    scanf("%g%g%g", &a1, &b1, &c1);
    printf("Введите значения второго уравнения: ");
    scanf("%g%g%g", &a2, &b2, &c2);
    
    x = (c1*b2-c2*b1)/((a1*b2)-(a2*b1));
    y = (a1*c2-a2*c1)/((a1*b2)-(a2*b1));
    
    printf("Решение для системы уравнений");
    printf("\n%g*x + %g*y = %g", a1, b1, c1);
    printf("\n%g*x + %g*y = %g:", a2, b2, c2);
    printf("\nx = %g\ny = %g", x, y);
}
