/*
Даны два числа a и b. Найти их среднее арифметическое: (a + b)/2.
*/

#include <stdio.h>

int main()
{
    float a, b; //объявление переменных
    printf("Введите два числа: "); //вспомогательный текст для пользователя
    scanf("%g%g", &a, &b); //ввод чисел

    printf("Среднее арифметическое: %g", (a+b)/2); //среднее арифметическое
}
