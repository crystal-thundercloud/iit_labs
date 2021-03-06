/*
Дано значение угла α в радианах (0 < α < 2·π). 
Определить значение этого же угла в градусах, 
учитывая, что 180◦ = π радианов
*/

#include <stdio.h>
#include <math.h>

int main()
{
    float a;
    printf("Введите значение угла a в радианах (0 < α < 2*π): ");
    scanf("%g", &a);
    
    if (a>0&&a<2*M_PI) {
        a = (a*180)/M_PI; //использование константы Пи из библиотеки math.h
        printf("Значение угла a в градусах: %g", a);
    }
 
    else printf("Значение за границами");
}
