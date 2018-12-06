// Файл exercise.9.11.Chrono.h
//
// This is example code from Chapter 9.8 "The Date class" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

namespace Chrono {

//------------------------------------------------------------------------------

    class Date {
    public:
        enum Month {
            jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
        };

        class Invalid { };                      // Для генерации исключений

        Date(int y, Month m, int d);            // Проверка корректности и инициализация
        Date();                                 // Конструктор по умолчанию
        // Копирование по умолчанию нас устраивает

        // Немодифицирующие операции:
        int   day()   const { return d; }
        Month month() const { return m; }
        int   year()  const { return y; }

        // Модифицирующие операции:
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);
    private:
        int   y;
        Month m;
        int   d;
    };


    bool is_date(int y, Date::Month m, int d);  // true для корректной даты

    bool leapyear(int y);                       // true для високосного года

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, Date& dd);

    const Date& default_date();

} // Chrono


//------------------------------------------------------------------------------