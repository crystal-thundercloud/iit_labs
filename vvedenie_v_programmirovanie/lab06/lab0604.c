/*
Найти значение функции y = 3x6 − 6x2 − 7 при данном значении x
*/
#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    printf("Введите число: ");
    scanf("%g", &x); //ввод x
    
    printf("Значение функции = %g", ((3*pow(x, 6))-6*(pow(x, 2))-7)); //вывод значения функции
}
