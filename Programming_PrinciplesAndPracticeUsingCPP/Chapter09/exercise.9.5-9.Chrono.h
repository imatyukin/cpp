#include "std_lib_facilities.h"

#ifndef CHRONO_H
#define CHRONO_H

namespace Chrono {

    enum class Day {
        sunday, monday, tuesday, wednesday, thursday, friday, saturday
    };

    enum class Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    // Операторы класса перечисления Month
    Month operator+(const Month& m, int n);
    Month operator-(const Month& m, int n);
    Month& operator+=(Month& m, int n);

    bool operator<(const Month& m, int n);
    bool operator>(const Month& m, int n);

    class Date {
    public:
        class Invalid {};               // Отбросить как исключение

        Date(int yy, Month mm, int dd); // Проверка действительной даты и инициализация
        Date();                         // Конструктор по умолчанию

        // Константные члены: модифицировать объект не могут
        int day() const { return d; }
        Month month() const { return m; }
        int year() const { return y; }

        // Неконстантные члены: могут модифицировать объект
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);
    private:
        int y;          // год
        Month m;
        int d;          // день
    };

    bool is_date(int y, Month m, int d);    // true для действительной даты
    bool leapyear(int y);                   // true, если y - високосный год

    // Операторы класса Date
    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, Date& dd);

    Day day_of_week(const Date& d);     // день недели d
    Date next_Sunday(const Date& d);    // следующее воскресенье после d
    Date next_weekday(const Date& d);   // следующий рабочий день после d

} // namespace Chrono

#endif