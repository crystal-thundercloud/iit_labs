#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, ac, bc; //объявление переменных
    printf("Введите координату (x) точки A: ");
    scanf("%g", &a); //ввод координат первой точки
    printf("Введите коодинату (x) точки B: ");
    scanf("%g", &b); //ввод координат второй точки   
    printf("Введите коодинату (x) точки C: ");
    scanf("%g", &c); //ввод координат третьей точки

    ac = sqrt(pow(a-c, 2)); //длина AC
    bc = sqrt(pow(b-c, 2)); //длина BC
    
    printf("Длина отрезка AC: %g", ac);
    printf("\nДлина отрезка BC: %g", bc);
    printf("\nСумма длин отрезков AC+BC: %g", ac+bc);
    
    return 0;
}