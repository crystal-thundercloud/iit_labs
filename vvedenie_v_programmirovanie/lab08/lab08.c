#include <stdio.h>
#include <math.h>

int main()
{
  
/*
Дан размер файла в байтах.
Найти количество полных килобайтов,
которые занимает данный файл
*/
    float x;
  
    printf("Дан размер файла в байтах.\nНайти количество полных килобайтов,\nКоторые занимает данный файл");
  
    printf("\nВведите размер файла в байтах: ");
    scanf("%f", &x);
    
    printf("Размер файла в килобайтах: %f", x*1024);
  
/*
Даны целые положительные числа A и B (A > B). 
На отрезке длины A размещено максимально возможное 
количество отрезков длины B (без наложений). 
Найти количество отрезков B, размещенных на отрезке A.
*/
    float a, b;
  
    printf("\n\nДаны целые положительные числа A и B (A > B).\nНа отрезке длины A размещено максимально возможное\nколичество отрезков длины B (без наложений).\nНайти количество отрезков B, размещенных на отрезке A.");
  
    printf("\nВведите размер отрезка А: ");
    scanf("%f", &a);
    printf("Введите размер отрезка B: ");
    scanf("%f", &b);
    
    printf("Количество отрезков B, размещённых на А: %f", floor(a/b));
    
/*
Даны целые положительные числа A и B (A > B).
На отрезке длины A размещено максимально возможное
количество отрезков длины B (без наложений).
Найти длину незанятой части отрезка A.
*/

    printf("\n\nДаны целые положительные числа A и B (A > B).\nНа отрезке длины A размещено максимально возможное\nколичество отрезков длины B (без наложений).\nНайти длину незанятой части отрезка A.");
  
    printf("\nВведите размер отрезка А: ");
    scanf("%f", &a);
    printf("Введите размер отрезка B: ");
    scanf("%f", &b);
    
    printf("Длина незанятой части А: %f", a-(b*floor(a/b)));
    
/*
Дано двузначное число.
Вывести число, полученное при
перестановке цифр исходного числа.*/
    
    int c;
    printf("\n\nДано двузначное число.\nВывести число, полученное при\nперестановке цифр исходного числа.");
  
    printf("\nВведите число: ");
    scanf("%d", &c);
    
    c = c/10+(10*(c%10));
    
    printf("Полученное число: %d", c);
    
/*Дано трехзначное число.
В нем зачеркнули первую слева цифру
и приписали ее справа.
Вывести полученное число*/

    printf("\n\nДано трехзначное число.\nВ нем зачеркнули первую слева цифру\nи приписали ее справа.\nВывести полученное число");
  
    printf("\nВведите число: ");
    scanf("%d", &c);
    
    c = (c/100)+10*(c%100);
    
    printf("Полученное число: %d", c);
}