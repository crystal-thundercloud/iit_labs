#include <iostream>
#include <math.h> //для trunc()
using namespace std;

struct phone { //задание 1 структура - номер телефона
    int citycode, station, numb;
};

struct point { //задание 2 структура - координаты точки на плоскости
    float x, y;
};

struct Distance { //задание 3 структура - длины в американской системе
    int feet;
    float inches;
};

struct Volume { //задание 3 структура - измерения комнаты
    Distance dlina;
    Distance shir;
    Distance vys;
};

struct employee { //задание 4 структура - информация о сотруднике
    int sotnumb;
    float posob;
};

struct date { //задание 5 структура - дата
    int day, month, year;
};

enum etype { laborer, secretary, manager, accountant, executive, researcher }; //задание 6 структура - должности сотрудников

struct employee2 { //задание 7 структура - инфо о сотруднике с должностью и датой
    int sotnumb;
    float salary;
    etype dolj;
    date dt;
};

struct fraction { //задание 8 структура - числитель и знаменатель дроби
    int chis, znam;
};

struct Time { //задание 9 структура - время
    int hours, minutes, seconds;
};

struct sterling { //заданиеь 10 структура - стерлинги
    int pounds, shillings, pence;
};

int main()
{
cout<<R"(1. Номер телефона, например (212) 767—8900, можно условно разделить на три части: 
код города (212), номер телефонной станции (767) и номер абонента (8900). 
Напишите программу с использованием структуры, позволяющую раздельно хранить эти три части телефонного номера.
Назовите структуру phone. Создайте две структурные переменные типа phone. Инициализацию одной из них произведите сами, 
а значения для другой запросите с клавиатуры. Затем выведите содержимое обеих переменных на экран.)"<<endl;

phone myphone = {916, 555, 3141};
phone yourphone;

cout<<"Введите свой номер телефона (например, 271 828 1812): ";
cin>>yourphone.citycode>>yourphone.station>>yourphone.numb;

cout<<"Мой номер: ("<<myphone.citycode<<") "<<myphone.station<<" "<<myphone.numb<<endl;
cout<<"Ваш номер: ("<<yourphone.citycode<<") "<<yourphone.station<<" "<<yourphone.numb<<endl;

cout<<"\n"<<R"(2. Расположение точки на плоскости можно задать с помощью двух координат: х и у. 
Например, если точка имеет координаты (4, 5), то это значит, что она отстоит на 4 единицы справа от вертикальной оси
и на 5 единиц вверх от горизонтальной оси. Сумма двух точек определяется как точка, имеющая координаты,
равные сумме соответствующих координат слагаемых.  
Напишите программу, использующую для интерпретации точки на плоскости структуру с названием point. 
Определите три переменные типа point, и две из них инициализируйте с помощью значений, вводимых с клавиатуры. 
Затем присвойте третьей переменной значение суммы первых двух переменных и выведите результат на экран.)"<<endl;

char trash;
point p1, p2, p3;
cout<<"Введите координаты точки p1 (например, 1,4): ";
cin>>p1.x>>trash>>p1.y;
cout<<"Введите координаты точки p2: ";
cin>>p2.x>>trash>>p2.y;

p3.x = p1.x+p2.x;
p3.y = p1.y+p2.y;

cout<<"Координаты p1+p2="<<p3.x<<","<<p3.y<<endl;

cout<<"\n"<<R"(3. Создайте структуру с именем Volume, содержащую три поля тина Distance из примера englstrc, 
для хранения трех измерений помещения. Определите переменную типа Volume, инициализируйте ее, вычислите объем, 
занимаемый помещением, и выведите результат на экран. Для подсчета объема переведите каждое из значений типа Distance
в значение типа float, равное соответствующей длине в футах и хранимое в отдельной переменной. 
Затем для вычисления объема следует перемножить три полученные вещественные переменные.)"<<endl;

Volume room {{23, 14.4}, {16, 5.7}, {10, 1}};

float dl, sh, vs;
dl = (room.dlina.inches/12)+room.dlina.feet; //перевод всего в футы
sh = (room.shir.inches/12)+room.shir.feet;
vs = (room.vys.inches/12)+room.vys.feet;

cout<<"Объём помещения: "<<dl*sh*vs<<" feet^3"<<endl;

cout<<"\n"<<R"(4. Создайте структуру с именем employee, содержащую два поля:
номер сотрудника типа int и величину его пособия в долларах типа float. 
Запросите с клавиатуры данные о трех сотрудниках, сохраните их в трех структурных переменных типа employee 
и выведите информацию о каждом из сотрудников на экран.)"<<endl;

employee e1, e2, e3;

cout<<"Введите информацию о сотруднике 1: ";
cin>>e1.sotnumb>>e1.posob;
cout<<"Введите информацию о сотруднике 2: ";
cin>>e2.sotnumb>>e2.posob;
cout<<"Введите информацию о сотруднике 3: ";
cin>>e3.sotnumb>>e3.posob;

cout<<"Введённая информация о сотрудниках: "<<endl;
cout<<e1.sotnumb<<" "<<e1.posob<<endl;
cout<<e2.sotnumb<<" "<<e2.posob<<endl;
cout<<e3.sotnumb<<" "<<e3.posob<<endl;

cout<<"\n"<<R"(5. Создайте структуру типа date, содержащую три поля типа int: месяц, день и год. 
Попросите пользователя ввести день, месяц и год в формате 31/12/2002, сохраните введенное значение в структурной переменной, 
а затем извлеките данные из этой переменной и выведите их на экран в том же формате, в каком они вводились.)"<<endl;

date dt;
cout<<"Введите дату (например, 31/12/2002): ";
cin>>dt.day>>trash>>dt.month>>trash>>dt.year;

cout<<"Вы ввели ";
if (dt.day<10) cout<<0;
cout<<dt.day<<trash;
if (dt.month<10) cout<<0;
cout<<dt.month<<trash<<dt.year<<endl;

cout<<"\n"<<R"(6. Как мы говорили, стандартные средства ввода/вывода C++ вместо значений перечисляемых типов данных
выводят их внутреннее представление в виде целых чисел. Для того чтобы преодолеть это ограничение, вы можете использовать 
конструкцию switch, с помощью которой устанавливается соответствие между значением переменной перечисляемого типа и 
се внутренним представлением. Пусть, например, в программе определен перечисляемый тип данных etype, 
отражающий должность сотрудника: enum etype { laborer, secretary, manager, accountant, executive, researcher }; 
Напишите программу, которая сначала по первой букве должности, введенной пользователем, определяет соответствующее значение переменной, 
помещает это значение в переменную типа etype, а затем выводит полностью название должности, первую букву которой ввел пользователь.)"<<endl;

char bykva;
cout<<"Введите первую букву должности  (laborer, secretary, manager, accountant, executive, researcher): ";
cin>>bykva;

etype dolj;
string dlj;

dolj = (bykva=='l')? laborer: ((bykva=='s')? secretary: ((bykva=='m')? manager : ((bykva=='a')? accountant : ((bykva=='e')? executive: researcher))));
dlj = (dolj==laborer)? "laborer": ((dolj==secretary)? "secretary": ((dolj==manager)? "manager": ((dolj==accountant)? "accountant": ((dolj==executive)? "executive" : "researcher"))));
cout<<"Полное название должности: "<<dlj<<endl;

cout<<"\n"<<R"(7.  Добавьте поля типа enum etype (см. упражнение 6) и struct date (см. упражнение 5) в структуру employee из упражнения 4. 
Организуйте программу таким образом, чтобы пользователь вводил 4 пункта данных о каждом из трех сотрудников:
его номер, величину зарплаты, его должность и дату принятия на работу. 
Программа должна хранить введенные значения в трех переменных типа employee и выводить их содержимое на экран.)"<<endl;

employee2 ep21, ep22, ep23;
string dl1, dl2, dl3;

cout<<"Введите информацию о сотрудниках (номер, зарплату, должность, дату принятия на работу, например: 132 44.550 manager 22/11/2016."<<endl;
cout<<"Сотрудник 1: ";
cin>>ep21.sotnumb>>ep21.salary>>dl1>>ep21.dt.day>>trash>>ep21.dt.month>>trash>>ep21.dt.year;
cout<<"Сотрудник 2: ";
cin>>ep22.sotnumb>>ep22.salary>>dl2>>ep22.dt.day>>trash>>ep22.dt.month>>trash>>ep22.dt.year;
cout<<"Сотрудник 3: ";
cin>>ep23.sotnumb>>ep23.salary>>dl3>>ep23.dt.day>>trash>>ep23.dt.month>>trash>>ep23.dt.year;

ep21.dolj = (dl1=="laborer")? laborer: ((dl1=="secretary")? secretary: ((dl1=="manager")? manager: ((dl1=="accountant")? accountant: ((dl1=="executive")? executive : researcher))));
ep22.dolj = (dl2=="laborer")? laborer: ((dl2=="secretary")? secretary: ((dl2=="manager")? manager: ((dl2=="accountant")? accountant: ((dl2=="executive")? executive : researcher))));
ep23.dolj = (dl3=="laborer")? laborer: ((dl3=="secretary")? secretary: ((dl3=="manager")? manager: ((dl3=="accountant")? accountant: ((dl3=="executive")? executive : researcher))));

cout<<"Введённая информация о сотрудниках:"<<endl;
cout<<"Сотрудник 1: №"<<ep21.sotnumb<<", зарплата: "<<ep21.salary<<"$, должность: "<<dl1<<", дата принятия на работу: "<<ep21.dt.day<<trash<<ep21.dt.month<<trash<<ep21.dt.year<<endl;
cout<<"Сотрудник 1: №"<<ep22.sotnumb<<", зарплата: "<<ep22.salary<<"$, должность: "<<dl2<<", дата принятия на работу: "<<ep22.dt.day<<trash<<ep22.dt.month<<trash<<ep22.dt.year<<endl;
cout<<"Сотрудник 1: №"<<ep23.sotnumb<<", зарплата: "<<ep23.salary<<"$, должность: "<<dl3<<", дата принятия на работу: "<<ep23.dt.day<<trash<<ep23.dt.month<<trash<<ep23.dt.year<<endl;

cout<<"\n"<<R"(8. Вернитесь к упражнению 9 комплекта заданий 2. В этом упражнении требуется написать программу,
которая хранит значения двух дробей в виде числителя и знаменателя, а затем складывает эти дроби согласно арифметическому правилу.
Измените эту программу так, чтобы значения дробей хранились в структуре fraction, состоящей из двух полей типа int.
предназначенных для хранения числителя и знаменателя. Все значения дробей должны храниться в переменных типа fraction.)"<<endl;

fraction fr1, fr2;

cout<<"Введите первую дробь: ";
cin>>fr1.chis>>trash>>fr1.znam;
cout<<"Введите вторую дробь: ";
cin>>fr2.chis>>trash>>fr2.znam;

cout<<fr1.chis<<trash<<fr1.znam<<" + "<<fr2.chis<<trash<<fr2.znam<<" = "<<fr1.chis*fr2.znam+fr2.chis*fr1.znam<<trash<<fr1.znam*fr2.znam;

cout<<"\n"<<R"(9. Создайте структуру с именем time. Три ее поля, имеющие тип int. будут называться hours, minutes и seconds.
Напишите программу, которая просит пользователя ввести время в формате часы, минуты, секунды.
Можно запрашивать на ввод как три значения сразу, так и выводить для каждой величины отдельное приглашение.
Программа должна хранить время в структурной переменной типа time и выводить количество секунд в введенном времени,
определяемое следующим образом: long totalsecs = t1.hours*3600 + t1 minutes*60 + t1.seconds )"<<endl;

Time tm;

cout<<"Введите время (например, 17:25:38): ";
cin>>tm.hours>>trash>>tm.minutes>>trash>>tm.seconds;

cout<<"Введённое время в секундах: "<<(tm.hours*3600)+(tm.minutes*60)+tm.seconds<<endl;

cout<<"\n"<<R"(10. Создайте структуру с именем sterling, хранящую денежные суммы в старой английской системе, 
описанной в упражнениях 8 и 11 комплекса заданий 3. Поля структуры могут быть названы pounds, shillings и pence и иметь тип int. 
Программа должна запрашивать у пользователя значение денежной суммы в новых десятичных фунтах 
(значение должно храниться в переменной типа double), затем переводить эту сумму в старую систему, 
сохранять переведенное значение в переменной типа sterling и выводить на экран полученную сумму в фунтах, шиллингах и пенсах. )"<<endl;

sterling st;
double decpound;
float pence;

cout<<"Введите число десятичных фунтов: £";//3.51
cin>>decpound;

st.pounds = trunc(decpound);
st.shillings = trunc((decpound-st.pounds)*20);
st.pence = (((decpound-st.pounds)*20)-st.shillings)*12;

cout<<"Сумма в старой записи: £"<<st.pounds<<"."<<st.shillings<<"."<<st.pence<<endl;

cout<<"\n"<<R"(11. Используя структуру time из упражнения 9, напишите программу, которая получает от пользователя два значения времени
в формате 12:59:59, сохраняет их в переменных типа struct time, затем переводит оба значения в секунды, складывает их, переводит сумму в исходный формат,
сохраняет его в переменной типа time и выводит полученный результат на экран в формате 12:59:59.)"<<endl;

Time tm1, tm2, tmsum;
int sumsec;

cout<<"Введите первое значение времени: ";
cin>>tm1.hours>>trash>>tm1.minutes>>trash>>tm1.seconds;
cout<<"Введите второе значение времени: ";
cin>>tm2.hours>>trash>>tm2.minutes>>trash>>tm2.seconds;

sumsec = ((tm1.hours*3600)+(tm1.minutes*60)+tm1.seconds)+((tm2.hours*3600)+(tm2.minutes*60)+tm2.seconds);

tmsum.hours = sumsec/3600;
tmsum.minutes = (sumsec-(tmsum.hours*3600))/60;
tmsum.seconds = (sumsec-(tmsum.hours*3600))-(tmsum.minutes*60);

cout<<"Сумма введённых значений: "<<tmsum.hours<<trash<<tmsum.minutes<<trash<<tmsum.seconds;

cout<<"\n"<<R"(12. Переработайте программу-калькулятор для дробей, описанную в упражнении 12 комплекта упражнений 3 так,
чтобы каждая из дробей хранилась как значение переменной типа struct fraction, по аналогии с упражнением 8 этого комплекса упражнений.)"<<endl;

char oper, povtor;
fraction plus, minus, mnoj, del;

do {
    cout<<"Введите выражение из двух операндов-дробей (например, 1/2-3/4): ";
    cin>>fr1.chis>>trash>>fr1.znam>>oper>>fr2.chis>>trash>>fr2.znam;
    switch (oper) {
        case '+':
            plus.chis = (fr1.chis*fr2.znam)+(fr2.chis*fr1.znam);
            plus.znam = fr1.znam*fr2.znam;
            cout<<fr1.chis<<trash<<fr1.znam<<" + "<<fr2.chis<<trash<<fr2.znam<<" = "<<plus.chis<<trash<<plus.znam<<endl;
            break;
        case '-':
            minus.chis = (fr1.chis*fr2.znam)-(fr2.chis*fr1.znam);
            minus.znam = fr1.znam*fr2.znam;
            cout<<fr1.chis<<trash<<fr1.znam<<" - "<<fr2.chis<<trash<<fr2.znam<<" = "<<minus.chis<<trash<<minus.znam<<endl;
            break;
        case '*':
            mnoj.chis = fr1.chis*fr2.chis;
            mnoj.znam = fr1.znam*fr2.znam;
            cout<<fr1.chis<<trash<<fr1.znam<<" * "<<fr2.chis<<trash<<fr2.znam<<" = "<<mnoj.chis<<trash<<mnoj.znam<<endl;
            break;
        case '/':
            del.chis = fr1.chis*fr2.znam;
            del.znam = fr2.chis*fr1.znam;
            cout<<fr1.chis<<trash<<fr1.znam<<" / "<<fr2.chis<<trash<<fr2.znam<<" = "<<del.chis<<trash<<del.znam<<endl;
            break;
    }
    cout<<"Ввести новое выражение?y,n: ";
    cin>>povtor;
}

while (povtor=='y');

}
