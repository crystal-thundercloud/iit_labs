#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <math.h>
using namespace std;
#ifndef _INC_WCONSOLE
#define _INC_WCONSOLE
HANDLE hConsole;
char fill_char;

const int CPF = 5;
const int maxHorses = 7;
enum color {
    cBLACK = 0, cDARK_BLUE = 1, cDARK_GREEN = 2, DARK_CYAN = 3,
    cDARK_RED = 4, cDARK_MAGENTA = 5, cBROWN = 6, cLIGHT_GRAY = 7,
    cDARK_GRAY = 8, cBLUE = 9, cGREEN = 10, cCYAN = 11,
    cRED = 12, cMAGENTA = 13, cYELLOW = 14, cWHITE = 15
};
void init_graphics();
void set_color(color);
void set_cursor_pos(int, int);
void wait(int);
void clear_line();
class Track;
class comtrack;
class Horse {
protected:
    const Track* ptrTrack;
    const int horse_number;
    float finish_time;
    float distance_run;
public:
    Horse(const int n, const Track* ptrT) : horse_number(n), ptrTrack(ptrT), distance_run(0.0) { }
    ~Horse() { }
    void display_horse(const float elapsed_time);
};
class Track {
protected:
    Horse* hArray[maxHorses];
    int total_horses;
    int horse_count;
    const float track_length;
    float elapsed_time;
public:
    Track(float lenT, int nH);
    ~Track();
    void display_track();
    void run();
    float get_track_len() const;
};
class comhorse : public Horse {
private:
    const comtrack* ptrTrack;
public:
    comhorse(const int n, const comtrack* ptrT) : Horse(n, NULL), ptrTrack(ptrT) { }
    void display_horse(const float elapsed_time);
};
class comtrack : public Track {
private:
    comhorse* hArray[maxHorses];
    int horse_count;
public:
    comtrack(float lenT, int nH);
    ~comtrack();
    void run();
    friend void comhorse::display_horse(float);
};
void Horse::display_horse(float elapsed_time) {
    set_cursor_pos(1 + int(distance_run * CPF), 5 + 2 + horse_number * 2);
    set_color(static_cast<color>(cBLUE + horse_number));
    char horse_char = '0' + static_cast<char>(horse_number);
    _putch(' '); _putch('H'); _putch(horse_char); _putch('H');
    if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF) {
        if (rand() % 3)
            distance_run += 0.2F;
        finish_time = elapsed_time;
    }
    else {
        int mins = int(finish_time) / 60;
        int secs = int(finish_time) - mins * 60;
        cout << " Время =" << mins << ":" << secs;
    }
}
void comhorse::display_horse(float elapsed_time) {
    set_cursor_pos(1 + int(distance_run * CPF), 5 + 2 + horse_number * 2);
    char horse_char = '0' + static_cast<char>(horse_number);
    _putch(' ');
    _putch('H');
    _putch(horse_char);
    _putch('H');
    if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF) {
        float speed = 0.2F;
        if (distance_run >= ptrTrack->get_track_len() / 3)
        {
            if (ptrTrack->total_horses > 1) {
                int Ld, Sc;
                if (ptrTrack->hArray[0]->distance_run < ptrTrack->hArray[1]->distance_run) {
                    Ld = 1; Sc = 0;
                }
                else {
                    Ld = 0; Sc = 1;
                }
                for (int j = 2; j < ptrTrack->total_horses; j++) {
                    if (ptrTrack->hArray[Ld]->distance_run < ptrTrack->hArray[j]->distance_run) {
                        Sc = Ld; Ld = j;
                    }
                    else if (ptrTrack->hArray[Sc]->distance_run < ptrTrack->hArray[j]->distance_run) {
                        Sc = j;
                    }
                }
                if (distance_run == ptrTrack->hArray[Ld]->distance_run || distance_run == ptrTrack->hArray[Sc]->distance_run) {
                    if (ptrTrack->hArray[Ld]->distance_run - ptrTrack->hArray[Sc]->distance_run <= 0.1F)
                        speed = 0.3F;
                }
            }
        }
        if (rand() % 3)
            distance_run += speed;
        finish_time = elapsed_time;
    }
    else {
        int mins = int(finish_time) / 60;
        int secs = int(finish_time) - mins * 60;
        cout << " Время = " << mins << ":" << secs;
    }
}
Track::Track(float lenT, int nH) : track_length(lenT), total_horses(nH), horse_count(0), elapsed_time(0.0) {
    init_graphics();
    total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;
    for (int j = 0; j < total_horses; j++)
        hArray[j] = new Horse(horse_count++, this);
    time_t aTime;
    srand(static_cast<unsigned>(time(&aTime)));
    display_track();
}
comtrack::comtrack(float lenT, int nH) : Track(lenT, nH), horse_count(0) {
    for (int j = 0; j < total_horses; j++)
        hArray[j] = new comhorse(horse_count++, this);
}
Track::~Track() {
    for (int j = 0; j < total_horses; j++)
        delete hArray[j];
}
comtrack::~comtrack() {
    for (int j = 0; j < total_horses; j++)
        delete hArray[j];
}
void Track::display_track() {
    system("cls");
    for (int f = 0; f <= track_length; f++)
        for (int r = 1; r <= total_horses * 2 + 1; r++) {
            set_cursor_pos(f * CPF + 5, 5 + r);
            if (f == 0 || f == track_length)
                cout << '|';
            else
                cout << '!';
        }
}
void Track::run() {
    while (!_kbhit()) {
        elapsed_time += 1.75;
        for (int j = 0; j < total_horses; j++)
            hArray[j]->display_horse(elapsed_time);
        wait(300);
    }
    _getch();
    cout << endl;
}
void comtrack::run() {
    while (!_kbhit()) {
        elapsed_time += 1.75;
        for (int j = 0; j < total_horses; j++)
            hArray[j]->display_horse(elapsed_time);
        wait(300);
    }
    _getch();
    wcout << endl;
}
float Track::get_track_len() const {
    return track_length;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << R"(9. Пусть есть классы, данные ниже. Предположим, что любая лошадь, которая на скачках к середине дистанции находится
впереди всех, становится практически непобедимой. Относительно класса лошадей создадим порожденный класс comhorse
(для конкурентоспособной лошади). Перегрузим функцию horse_tick() в этом классе таким образом, чтобы каждая лошадь
могла проверять, является ли она ведущей и нет ли поблизости соперников (скажем, ближе, чем на 0,1 форлонг (1/80
часть мили или 20,1 м.)). Если есть, то ей следует немного ускориться. Может быть, не настолько, чтобы побеждать
на всех скачках, но в достаточной мере для того, чтобы оставаться конкурентоспособной. Как каждая лошадь узнает,
где находятся остальные? Моделирующий ее объект должен иметь доступ к области памяти, в которой хранятся данные о
соперниках. В программе это hArray. Будьте внимательны: вы создаете класс для передовой лошади, он должен быть
наследником класса всех лошадей. Поэтому классу comhorse потребуется перегрузить hArray. Вам может потребоваться
создать еще один производный класс, comtrack, для отслеживания позиции лошади. Можно непрерывно проверять, лидирует
ли ваша лошадь, и если она впереди всех, но лишь ненамного, следует ее немного ускорить. )" << endl;

    float length;
    int total;
    cout << "Введите длину дистанции (от 1 до 12): ";
    cin >> length;
    cout << "Введите количество лошадей (от 1 до 7): ";
    cin >> total;
    Track theTrack(length, total);
    theTrack.run();

    return 0;
}

void init_graphics() {
    COORD console_size = { 80, 25 };
    hConsole = CreateFile("CONOUT$", GENERIC_WRITE | GENERIC_READ,FILE_SHARE_READ | FILE_SHARE_WRITE, 0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L);
    SetConsoleScreenBufferSize(hConsole, console_size);
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
    fill_char = '\xDB';
    system("cls");
};
void set_color(color fg) {
    color bg = cBLACK;
    SetConsoleTextAttribute(hConsole,
        (WORD)((bg << 4) | fg));
};
void set_cursor_pos(int x, int y) {
    COORD cursor_pos;
    cursor_pos.X = x - 1;
    cursor_pos.Y = y - 1;
    SetConsoleCursorPosition(hConsole, cursor_pos);
};
void wait(int milliseconds) {
    Sleep(milliseconds);
};
void clear_line() {
    _cputs("                                        ");
    _cputs("                                        ");
};
#endif
