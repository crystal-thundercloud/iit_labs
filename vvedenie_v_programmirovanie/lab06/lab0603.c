/*
Даны переменные A, B, C. Изменить их значения, 
переместив содержимое A в C, C — в B, B — в A, 
и вывести новые значения переменных A, B, C.
*/
#include <stdio.h>

int main()
{
    float a, b, c;
    printf("Введите число A: ");
    scanf("%g", &a); //ввод числа А
    printf("Введите число B: ");
    scanf("%g", &b); //ввод числа В
    printf("Введите число C: ");
    scanf("%g", &c); //ввод числа C
    
    c = a+b+c; //C - сумма всех значений
    b = c-a-b; //В - разность нового C, В и A = старое C
    a = c-a-b; //A - разность нового C, нового В и A = старое В
    c = c-a-b; //C - разность нового C, нового В и нового A = старое A
    
    printf("Число A = %g", a); //вывод нового значения А
    printf("\nЧисло B = %g", b); //вывод нового значения В
    printf("\nЧисло C = %g", c); //вывод нового значения c
}
