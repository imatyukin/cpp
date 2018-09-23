#include <iostream>

using namespace std;

namespace Chrono941 {
    // Простая структура Date (слишком просто?)
    struct Date {
        int y;      // Год
        int m;      // Месяц года
        int d;      // День месяца
    };

    // Вспомогательные функции:
    void init_day(Date& dd, int y, int m, int d);
    void add_day(Date& dd, int n);

    // Операторы
    ostream& operator<<(ostream& os, const Date& d);
}   // Chrono941