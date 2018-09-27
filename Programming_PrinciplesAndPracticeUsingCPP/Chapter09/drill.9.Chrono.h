#include <iostream>

using namespace std;

namespace Chrono941 {
    // Простая структура Date (слишком просто?)
    struct Date {
        int y;                          // Год
        int m;                          // Месяц года
        int d;                          // День месяца
    };

    // Вспомогательные функции:
    void init_day(Date& dd, int y, int m, int d);
    void add_day(Date& dd, int n);

    // Операторы
    ostream& operator<<(ostream& os, const Date& d);
}   // Chrono941

namespace Chrono942 {
    // Простая структура Date,
    // гарантирующая инициализацию с помощью конструктора
    // и обеспечивающая удобство обозначений
    struct Date {
        int y, m, d;                    // Год, месяц, день
        Date(int yy, int mm, int dd);   // Проверяем корректность даты и выполняем инициализацию
        void add_day(int n);            // Увеличиваем объект на n дней
    };

    // Операторы
    ostream& operator<<(ostream& os, const Date& d);
}   // Chrono942

namespace Chrono943 {
    // Простой тип Date (управляемый доступ)
    class Date {
        int y, m, d;                    // Год, месяц, день
    public:
        Date(int yy, int mm, int dd);   // Проверка и инициализация даты
        void add_day(int n);            // Увеличение Date на n дней
        int month() const { return m; }
        int day() const { return d; }
        int year() const { return y; }
    };

    // Операторы
    ostream& operator<<(ostream& os, const Date& d);
}   // Chrono943