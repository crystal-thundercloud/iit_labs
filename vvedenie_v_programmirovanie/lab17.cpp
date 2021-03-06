#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{

/*
Дан массив размера N и целые числа K и L (1 ≤ K ≤ L ≤ N).
Найти среднее арифметическое элементов массива с номерами от K до L включительно.
*/

cout<<R"(Дан массив размера N и целые числа K и L (1 ≤ K ≤ L ≤ N).
Найти среднее арифметическое элементов массива с номерами от K до L включительно.)"<<"\n"<<endl;

int n, k, l;


cout<<"Введите размер массива: ";
cin>>n;

int arr1[n];

cout<<"Введите элементы массива: ";
for (int i=0; i<n; i++) {
    cin>>arr1[i];
}

cout<<"Введите число K (0<=K<=N): ";
cin>>k;
cout<<"Введите число L (K<=L<=N): ";
cin>>l;

n = 0;
float o = 0;

for (int i=k; i<=l; i++) {
    n+=arr1[i];
    o++;
}

cout<<"Среднее арифметическое элементов массива с номерами от "<<k<<" до "<<l<<" = "<<n/o<<endl;

/*
Дан целочисленный массив размера N, не содержащий одинаковых чисел.
Проверить, образуют ли его элементы арифметическую прогрессию.
Если образуют, то вывести разность прогрессии, если нет — вывести 0.
*/

/*
Дан целочисленный массив размера N, не содержащий одинаковых чисел.
Проверить, образуют ли его элементы арифметическую прогрессию.
Если образуют, то вывести разность прогрессии, если нет — вывести 0.
*/

cout<<"\n"<<R"(Дан целочисленный массив размера N, не содержащий одинаковых чисел.
Проверить, образуют ли его элементы арифметическую прогрессию.
Если образуют, то вывести разность прогрессии, если нет — вывести 0.)"<<"\n"<<endl;

cout<<"Введите размер массива: ";
cin>>n;

int arr2[n];

cout<<"Введите элементы массива: ";
for (int i=0; i<n; i++) {
    cin>>arr2[i];
}

o = arr2[0]-arr2[1];

for (int i=0; i<n-1; i++) {
    if ((arr2[i]-arr2[i+1])!=o) o=0;
}

o = -o;

cout<<"Ответ: "<<o<<endl;

/*
Дан массив A размера N. Найти минимальный элемент из его элементов с четными номерами: A2, A4, A6...
*/

cout<<"\n"<<R"(Дан массив A размера N. Найти минимальный элемент из его элементов с четными номерами: A2, A4, A6...)"<<"\n"<<endl;

cout<<"Введите размер массива: ";
cin>>n;

int arr3[n];

cout<<"Введите элементы массива: ";
for (int i=0; i<n; i++) {
    cin>>arr3[i];
}

o = (n%2==0)? arr3[n-2] : arr3[n-1];

for (int i = (n%2==0)? n-2 : n-1; i>=0; i-=2) {
    cout<<"a["<<i<<"] = "<<arr3[i]<<" ";
    if (arr3[i]<o) o = arr3[i];
}

cout<<"\nНаименьший элемент с чётным номером = "<<o<<endl;

/*
Дан массив размера N. Найти номер его последнего локального максимума
(локальный максимум — это элемент, который больше любого из своих соседей).
*/

cout<<"\n"<<R"(Дан массив размера N. Найти номер его последнего локального максимума
(локальный максимум — это элемент, который больше любого из своих соседей).)"<<"\n"<<endl;

cout<<"Введите размер массива: ";
cin>>n;

int arr4[n];

cout<<"Введите элементы массива: ";
for (int i=0; i<n; i++) {
    cin>>arr4[i];
}

o=-9999;

for (int i=1; i<n-1; i++) {
    if ((arr4[i]>arr4[i-1])&&(arr4[i]>arr4[i+1])) o = (arr4[i]>o)? i : o;
}

cout<<"\nПоследний локальный максимум ";
(o==-9999)? cout<<"отсутствует."<<endl : cout<<"имеет номер "<<o<<"."<<endl;

/*
Дан целочисленный массив размера N, содержащий ровно два одинаковых элемента.
Найти номера одинаковых элементов и вывести эти номера в порядке возрастания
*/

cout<<"\n"<<R"(Дан целочисленный массив размера N, содержащий ровно два одинаковых элемента.
Найти номера одинаковых элементов и вывести эти номера в порядке возрастания.)"<<"\n"<<endl;

cout<<"Введите размер массива: ";
cin>>n;

int arr5[n];

cout<<"Введите элементы массива (два из них должны совпадать): ";
for (int i=0; i<n; i++) {
    cin>>arr5[i];
}

for (int i=1; i<n; i++) {
    if (arr5[i]==arr5[i-1]) {
        cout<<"Совпадающие элементы имеют номера "<<i-1<<" и "<<i<<endl;
    }
}

}
