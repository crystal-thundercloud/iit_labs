#include <stdio.h>
#include <math.h>

int main()
{
    float a1, b1;
    
    printf("Поменять местами содержимое переменных A и B и вывести новые значения A и B.");

    //вариант без дополнительных переменных");
    
    printf("\nВведите число A: ");
    scanf("%g", &a1); //ввод числа А
    printf("Введите число B: ");
    scanf("%g", &b1); //ввод числа В
    
    a1 = a1+b1; //А - сумма А и В
    b1 = a1-b1; //В - разность нового А и В, получает значение старого А
    a1 = a1-b1; //А - разность нового А и нового В, получает значение старого В
    
    printf("Число A = %g", a1); //вывод нового значения А
    printf("\nЧисло B = %g", b1); //вывод нового значения В
    
/*
Даны переменные A, B, C. Изменить их значения, 
переместив содержимое A в B, B — в C, C — в A, 
и вывести новые значения переменных A, B, C.
*/
    
    float a2, b2, c2;
    
    printf("\n\nДаны переменные A, B, C.\nИзменить их значения, переместив содержимое A в B, B — в C, C — в A,\nи вывести новые значения переменных A, B, C.");
    
    printf("\nВведите число A: ");
    scanf("%g", &a2); //ввод числа А
    printf("Введите число B: ");
    scanf("%g", &b2); //ввод числа В
    printf("Введите число C: ");
    scanf("%g", &c2); //ввод числа C
    
    a2 = a2+b2+c2; //A - сумма всех значений
    b2 = a2-b2-c2; //В - разность нового А, В и С = старое А
    c2 = a2-b2-c2; //С - разность нового А, нового В и С = старое В
    a2 = a2-b2-c2; //А - разность нового А, нового В и нового С = старое С
    
    printf("Число A = %g", a2); //вывод нового значения А
    printf("\nЧисло B = %g", b2); //вывод нового значения В
    printf("\nЧисло C = %g", c2); //вывод нового значения c
    
/*
Даны переменные A, B, C. Изменить их значения, 
переместив содержимое A в C, C — в B, B — в A, 
и вывести новые значения переменных A, B, C.
*/

    float a3, b3, c3;
    
    printf("\n\nДаны переменные A, B, C. Изменить их значения,\nпереместив содержимое A в C, C — в B, B — в A,\nи вывести новые значения переменных A, B, C.");
    
    printf("\nВведите число A: ");
    scanf("%g", &a3); //ввод числа А
    printf("Введите число B: ");
    scanf("%g", &b3); //ввод числа В
    printf("Введите число C: ");
    scanf("%g", &c3); //ввод числа C
    
    c3 = a3+b3+c3; //C - сумма всех значений
    b3 = c3-a3-b3; //В - разность нового C, В и A = старое C
    a3 = c3-a3-b3; //A - разность нового C, нового В и A = старое В
    c3 = c3-a3-b3; //C - разность нового C, нового В и нового A = старое A
    
    printf("Число A = %g", a3); //вывод нового значения А
    printf("\nЧисло B = %g", b3); //вывод нового значения В
    printf("\nЧисло C = %g", c3); //вывод нового значения c
    
/*
Найти значение функции y = 3x6 − 6x2 − 7 при данном значении x
*/
    
    float x4;
    
    printf("\n\nНайти значение функции y = 3x6 − 6x2 − 7 при данном значении x.");
    
    printf("\nВведите число: ");
    scanf("%g", &x4); //ввод x
    
    printf("Значение функции = %g", (3*(pow(x4, 6))-6*(pow(x4, 2))-7)); //вывод значения функции
    
/*
Найти значение функции y = 4(x−3)6 − 7(x−3)3 + 2 при данном значении x
*/
    
    float x5;
    
    printf("\n\nНайти значение функции y = 4(x−3)6 − 7(x−3)3 + 2 при данном значении x.");
    
    printf("\nВведите число: ");
    scanf("%g", &x5); //ввод x
    
    printf("Значение функции = %g", 4*pow(x5-3, 6)-7*pow(x5-3, 3)+2); //вывод значения функции
    
/*
Дано число A. Вычислить A8 , используя 
вспомогательную переменную и три операции умножения.
*/
    
    float a6, b6;
    
    printf("\n\nДано число A. Вычислить A8 , используя\nвспомогательную переменную и три операции умножения.");
    
    printf("\nВведите число: ");
    scanf("%g", &a6); //ввод a
    
    b6 = a6*a6; //2
    a6 = b6*b6; //4
    b6 = a6*a6; //8
    
    printf("A^8 = %g", b6); //вывод значения A^8
    
/*
Дано число A. Вычислить A15, используя 
две вспомогательные переменные и пять операций умножения.
*/
    
    float a7, b7, c7;
    
    printf("\n\nДано число A. Вычислить A15, используя\nдве вспомогательные переменные и пять операций умножения.");
    
    printf("\nВведите число: ");
    scanf("%g", &a7); //ввод a
    
    b7 = a7*a7; //2
    c7 = b7*a7; //3
    b7 = b7*c7; //5
    c7 = b7*b7; //10
    b7 = b7*c7; //15
    
    printf("A^8 = %g", b7); //вывод значения A^15
}