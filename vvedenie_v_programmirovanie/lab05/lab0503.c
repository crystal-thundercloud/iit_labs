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

    if (c<a&&c>b||c>a&&c<b) {

        ac = sqrt(pow(a-c, 2)); //длина AC
        bc = sqrt(pow(b-c, 2)); //длина BC
        
        printf("\nПроизведение длин отрезков AC*BC: %g", ac*bc);
    }
    
    else printf("Координаты C не между A и B");
    
    return 0;
}
