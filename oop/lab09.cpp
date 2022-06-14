#include <iostream>
#include <math.h>

using namespace std;

class String { // 2 - строки
private:
    char* str;
public:
    String(const char* s) {
        int length = strlen(s);
        str = new char[length + 1];
        strcpy_s(str, static_cast<rsize_t>(length) + 1, s);
    }
    ~String() {
        delete[] str;
    }
    void display() {
        cout << str << endl;
    }
    void upit() {
        setlocale(LC_CTYPE, "ru-RU");
        char* ptrch = str;
        while (*ptrch) {
            *ptrch = toupper(*ptrch);
            ptrch++;
        }
    }
};

const int DAYS = 7; // 3 - сортировка

void Order(const char** pp1, const char** pp2) { // 3 - порядок
    if (strcmp(*pp1, *pp2) > 0) {
        const char* tempptr = *pp1;
        *pp1 = *pp2;
        *pp2 = tempptr;
    }
}

void Bsort(const char** pp, int n) { // 3 - сортировка
    for (int j = 0; j < n - 1; j++)
        for (int k = j + 1; k < n; k++)
            Order(pp + j, pp + k);
}

struct link { // 4 - деструктор
    int data;
    link* next;
};

class linklist { // 4 - деструктор
private:
    link* first;
public:
    linklist() {
        first = NULL;
    }
    ~linklist();
    void additem(int d) {
        link* newlink = new link;
        newlink->data = d;
        newlink->next = first;
        first = newlink;
    };
    void display() {
        link* current = first;
        while (current != NULL) {
            cout << current->data << endl;
            current = current->next;
        }
    };
};

linklist::~linklist() { // 4 - деструктор
    link* current = first;
    while (current != NULL) {
        first = current->next;
        delete current;
        cout << "Элемент списка удалён." << endl;
        current = first;
    }
}

const int MAX = 10; // 5 - сумма элементов массивов, 10 - массивы

void addarrays(float* a1, float* a2, float* a3) {
    for (int j = 0; j < MAX; j++)
        *(a3 + j) = *(a1 + j) + *(a2 + j);
}

int STrcmp(const char* s1, const char* s2) { // 6 - строки
    while (*s1 && *s2) {
        if (*s1 > *s2) return 1;
        else if (*s1 < *s2) return -1;
        s1++; s2++;
    }
    if (!*s1 && !*s2) return 0;
    else if (!*s1) return -1;
    else return 1;
}

class person { // 7 - персона
protected:
    string name;
    float salary = 0.0;
public:
    void setData() {
        cout << "Введите имя: ";
        cin >> name;
        cout << "Введите зарплату: ";
        cin >> salary;
    }
    void printData() {
        cout <<"Имя: " << name << endl;
        cout <<"Зарплата : " << salary << endl;
    }
    float getSalary() {
        return salary;
    }
};

void salsort(person** pp, int n) {
    for (int j = 0; j < n - 1; j++)
        for (int k = j + 1; k < n; k++)
            if ((*(pp + j))->getSalary() > (*(pp + k))->getSalary()) {
                person* tempptr = *(pp + j);
                *(pp + j) = *(pp + k);
                *(pp + k) = tempptr;
            }
}

class Linklist1 { //8 - additem() наоборот
private:
    link* first;
public:
    Linklist1() {
        first = NULL;
    }
    void additem(int d) {
        link* newlink = new link;
        newlink->data = d;
        newlink->next = NULL;
        if (first) {
            link* current = first;
            while (current->next) current = current->next;
            current->next = newlink;
        }
        else
            first = newlink;
    };
    void display() {
        link* current = first;
        while (current != NULL) {
            cout << current->data << endl;
            current = current->next;
        }
    };
};

class nArrays { //11 - класс массивов
private:
    const int num;
    const int max;
    int** ap;
public:
    nArrays(int na, int ms) : num(na), max(ms) {
        ap = new int* [num];
        for (int j = 0; j < num; j++)
            *(ap + j) = new int[max];
    }
    ~nArrays() {
        for (int j = 0; j < num; j++)
            delete[] * (ap + j);
        delete[] ap;
    }
    int& operator[] (int n) {
        int j = n / max;
        int k = n % max;
        return *(*(ap + j) + k);
    }
};

// 12 - класс указателей
const int fm_SIZE = 100;
float fmemory[fm_SIZE];
int fmem_top = 0;
const int pm_SIZE = 100;
int pmemory[pm_SIZE];
int pmem_top = 0;

class Float { // 12 - класс указателей
private:
    int addr;
public:
    Float(float val) {
        fmemory[fmem_top] = val;
        addr = fmem_top;
        fmem_top++;
    }
    int operator& () const {
        return addr;
    }
};

class ptrFloat { // 12 - класс указателей
private:
    int addr;
public:
    ptrFloat(int val) {
        pmemory[pmem_top] = val;
        addr = pmem_top;
        pmem_top++;
    }
    float& operator* () const {
        return fmemory[pmemory[addr]];
    }
};



int main()
{
    setlocale(LC_ALL, "Russian");
    
    cout << R"(1. Напишите программу, которая принимает группу чисел от пользователя и помещает их в массив типа float.
После того как числа будут помещены в массив, программа должна подсчитать их среднее арифметическое и вывести результат
на дисплей. Используйте указатели везде, где только возможно)" << endl;
    
    float flarr[100]{}, total = 0.0;
    int num = 0;
    do {
        cout << "Введите число: ";
        cin >> *(flarr + num++);
        cout << "Ввести ещё число? y,n:  ";
        cin.get();
    } while (cin.get() != 'n');

    for (int k = 0; k < num; k++) total += *(flarr + k);
    float average = total / num;
    cout << "Среднее арифметическое введённых чисел: " << average << endl;
    
    cout << "\n" << R"(2. Используйте класс String из примера NEWSTR этой главы. Добавьте к нему метод upit(), который будет переводить символы
строки в верхний регистр. Вы можете использовать библиотечную функцию toupper(), которая принимает отдельный символ
в качестве аргумента и возвращает символ, переведенный в верхний регистр (если это необходимо). Эта функция использует
заголовочный файл Cctype. Добавьте в функцию main() необходимые строки для тестирования метода upit().)" << endl;

    String st = "Что дозволено Юпитеру, не дозволено быку";
    cout << "Исходная строка: ";
    st.display();
    st.upit();
    cout << "Верхний регистр: ";
    st.display();
    cout << endl;

    cout << "\n" << R"(3. Используйте массив указателей на строки, представляющие собой названия дней недели, из примера PTROSTR этой главы.
Напишите функции для сортировки этих строк в алфавитном порядке, используя в качестве основы функции bsort() и order()
из программы PTRSORT этой главы. Сортировать необходимо указатели на строки, а не сами строки. )" << endl;

    const char* arrptrs[DAYS] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    cout << "Несортированный:" << endl;
    for (int j = 0; j < DAYS; j++) cout << *(arrptrs + j) << endl;
    
    Bsort(arrptrs, DAYS);
    
    cout << "Сортированный:" << endl;
    for (int j = 0; j < DAYS; j++) cout << *(arrptrs + j) << endl;
    
    cout << "\n" << R"(4. Добавьте деструктор в программу LINKLIST. Он должен удалять все элементы списка при удалении объекта класса linklist.
Элементы должны удаляться по очереди, в соответствии с их расположением в списке. Протестируйте деструктор путем вывода
сообщения об удалении каждого из элементов списка; удалено должно быть также количество элементов, какое было положено
в список (деструктор вызывается автоматически для каждого существующего объекта).)" << endl;

    linklist li;
    li.additem(11);
    li.additem(26);
    li.additem(47);
    li.additem(85);
    li.display();

    cout << "\n" << R"(5. Предположим, что в функции main() определены три локальных массива одинакового размера и типа (скажем, float).
Первые два уже инициализированы значениями. Напишите функцию addarrays(), которая принимает в качестве аргументов
адреса трех массивов, складывает соответствующие элементы двух массивов и помещает результат в третий массив.
Четвертым аргументом этой функции может быть размерность массивов. На всем протяжении программы используйте указатели)" << endl;

    float arr1[MAX], arr2[MAX], arr3[MAX];
    for (int i = 0; i < MAX; i++) {
        arr1[i] = float(i+3.2);
        arr2[i] = float(pow(i, 2));
    }
    addarrays(arr1, arr2, arr3);
    for (int i = 0; i < MAX; i++) {
        cout << arr1[i] << " + " << arr2[i] << " = " << arr3[i] << endl;
    }
    
    cout << "\n" << R"(6. Создайте свою версию библиотечной функции strcmp(s1, s2), которая сравнивает две строки и возвращает -1, если
s1 идет первой по алфавиту, 0, если в s1 и s2 одинаковые значения, и 1, если s2 идет первой по алфавиту. Назовите
вашу функцию compstr(). Она должна принимать в качестве аргументов два указателя на строки char*, сравнивать эти
строки посимвольно и возвращать число int. Напишите функцию main() для проверки работы вашей функции с разными
строками. Используйте указатели во всех возможных ситуациях. )" << endl;

    const char* s1, * s2;
    s1 = "As";
    s2 = "Is";
    cout << s1 << ", " << s2 << " => " << STrcmp(s1, s2) << endl;
    s1 = "At";
    s2 = "At";
    cout << s1 << ", " << s2 << " => " << STrcmp(s1, s2) << endl;
    s1 = "Is";
    s2 = "As";
    cout << s1 << ", " << s2 << " => " << STrcmp(s1, s2) << endl;
    
    cout << "\n" << R"(7. Модифицируйте класс person из программы PERSORT этой главы так, чтобы он включал в себя не только имя человека,
но и сведения о его зарплате в виде поля salary типа float. Вам будет необходимо изменить методы setName() и
printName() на setData() и printData(), включив в них возможность ввода и вывода значения salary, как это можно
сделать с именем. Вам также понадобится метод getSalary(). Используя указатели, напишите функцию salsort(),
которая сортирует указатели массива persPtr по значениям зарплаты. Попробуйте вместить всю сортировку в функцию
salsort(), не вызывая других функций, как это сделано в программе PERSORT. )" << endl;

    person* persPtr[100];
    int n = 0;
    do {
        cout << "Введите данные человека: " << endl;
        persPtr[n] = new person;
        persPtr[n]->setData();
        n++;
        cout << "Ввести данные ещё одного человека? y,n: ";
        cin.get();
    } while (cin.get() != 'n');

    cout << "Несортированный список:" << endl;
    for (int j = 0; j < n; j++) {
        persPtr[j]->printData();
    }
    salsort(persPtr, n);

    cout << "Сортированный список (зарплата от меньшего к большему):" << endl;
    for (int j = 0; j < n; j++) {
        persPtr[j]->printData();
    }
    
    cout << "\n" << R"(8. Исправьте функцию additem() из программы LINKLIST так, чтобы она добавляла новый элемент в конец списка, а не
в начало. Это будет означать, что первый вставленный элемент будет выведен первым и результат работы программы
будет следующим (25 36 49 64) Для того чтобы добавить элемент, вам необходимо будет пройти по цепи до конца списка,
а затем изменить указатель последнего элемента так, чтобы он указывал на новый элемент.)" << endl;
    
    Linklist1 li1;
    li1.additem(25);
    li1.additem(36);
    li1.additem(49);
    li1.additem(64);
    li1.display();
    
    cout << "\n" << R"(9. Допустим, что нам нужно сохранить 100 целых чисел так, чтобы иметь к ним легкий доступ. Допустим, что при этом
у нас есть проблема: память нашего компьютера так фрагментирована, что может хранить массив, наибольшее количество
элементов в котором равно десяти (такие проблемы действительно появляются, хотя обычно это происходит с объектами,
занимающими большое количество памяти). Вы можете решить эту проблему, определив 10 разных массивов по 10 элементов
в каждом и массив из 10 указателей на эти массивы. Массивы будут иметь имена a0, a1, a2 и т. д. Адрес каждого массива
будет сохранен в массиве указателей типа int*, который называется ар. Вы сможете получить доступ к отдельному целому
используя выражение ap[j][к], где j является номером элемента массива указателей, а к — номером элемента в массиве,
на который этот указатель указывает. Это похоже на двумерный массив, но в действительности является группой одномерных
массивов. Заполните группу массивов тестовыми данными (скажем, номерами 0, 10, 20 и т. д.), а затем выведите их, 
чтобы убедиться, что все работает правильно.)" << endl;

    int a0[MAX], a1[MAX], a2[MAX], a3[MAX], a4[MAX], a5[MAX], a6[MAX], a7[MAX], a8[MAX], a9[MAX];
    int* ap[] = { a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 };
    int j, k;
    for (j = 0; j < MAX; j++)
        for (k = 0; k < MAX; k++)
            ap[j][k] = (j * 10 + k) * 10;
    for (j = 0; j < MAX; j++) {
        for (k = 0; k < MAX; k++) {
            if (j == 0) {
                cout << "   " << ap[j][k] << " ";
                if (k == 0)
                    cout << " ";
            }
            else
                cout << "   " << ap[j][k];
        }
        cout << endl;
    }
    
    cout << "\n" << R"(10. Описанный в упражнении 9 подход нерационален, так как каждый из 10 массивов объявляется отдельно, с использованием
отдельного имени, и каждый адрес получают отдельно. Вы можете упростить программу, используя операцию new, которая
позволит вам выделить память для массивов в цикле и одновременно связать с ними указатели: 
for(j = 0; j < NUMARRAYS; j++) 	 // создаем NUMARRAYS массивов 
*(ар + j) = new int[MAXSIZE];	 // no MAXSIZE целых чисел в каждом 
Перепишите программу упражнения 9, используя этот подход. Доступ к отдельному элементу массивов вы сможете получить,
используя то же выражение, что и в упражнении 9, или аналогичное выражение с указателями: *(*(ap + j)+k).)" << endl;

    int* Ap[MAX]{};
    for (int j = 0; j < MAX; j++)
        *(Ap + j) = new int[MAX];
    for (j = 0; j < MAX; j++)
        for (k = 0; k < MAX; k++)
            Ap[j][k] = (j * 10 + k) * 10;
    for (j = 0; j < MAX; j++) {
        for (k = 0; k < MAX; k++) {
            if (j == 0) {
                cout << "   " << Ap[j][k] << " ";
                if (k == 0)
                    cout << " ";
            }
            else
                cout << "   " << Ap[j][k];
        }
        cout << endl;
    }
    
    cout << "\n" << R"(11. Создайте класс, который позволит вам использовать 10 отдельных массивов из упражнения 10 как один одномерный
массив, допуская применение операций массива. То есть мы можем получить доступ к элементам массива, записав в функции
main() выражение типа a[j], а методы класса могут получить доступ к полям класса, используя двухшаговый подход.
Перегрузим операцию [] (см. главу 9 «Наследование»), чтобы получить нужный нам результат. Заполним массив данными
и выведем их. Хотя для интерфейса класса использованы операции индексации массива, вам следует использовать
указатели внутри методов класса.)" << endl;

    int numarr;
    int sizearr;
    cout << "Введите количество массивов: ";
    cin >> numarr;
    cout << "Введите количество элементов в каждом массиве: ";
    cin >> sizearr;
    nArrays arr(numarr, sizearr);
    int i;
    for (i = 0; i < numarr * sizearr; i++)
        arr[i] = (i + 1) * 10;
    for (i = 0; i < numarr * sizearr; i++) {
        cout << arr[i];
        if (i % sizearr == sizearr - 1)
            cout << endl;
        else
            cout << " ";
    }
    
    cout << "\n" << R"(12. Симуляция указателей в классе.)" << endl;

    Float var1 = 1.234;
    Float var2 = 5.678;
    ptrFloat ptr1 = &var1;
    ptrFloat ptr2 = &var2;
    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;
    *ptr1 = 7.123;
    *ptr2 = 8.456;
    cout << "Новые:\n*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;


    return 0;
}
