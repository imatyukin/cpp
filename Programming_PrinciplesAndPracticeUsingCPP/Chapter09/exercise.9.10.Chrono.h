// Файл exercise.9.10.Chrono.h

#include "std_lib_facilities.h"

namespace Chrono {

    enum class Day {
        sunday, monday, tuesday, wednesday, thursday, friday, saturday
    };

    enum class Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    // Операторы класса перечисления Month
    Month operator+(const Month& m, int n);
    Month operator-(const Month& m, int n);
    Month& operator+=(Month& m, int n);

    bool operator<(const Month& m, int n);
    bool operator>(const Month& m, int n);

    class Date {
    public:
        class Invalid { };                          // Для генерации исключений

        Date(int yy, Month mm, int dd);             // Проверка корректности и инициализация
        Date();                                     // Конструктор по умолчанию
        // Копирование по умолчанию нас устраивает

        // Немодифицирующие операции:
        int day() const { return d; }
        Month month() const { return m; }
        int year() const { return y; }

        // Модифицирующие операции
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);
    private:
        int y;                                      // Год
        Month m;
        int d;                                      // День
    };

    bool is_date(int y, Month m, int d);            // true для корректной даты
    bool leapyear(int y);                           // true для високосного года

    // Операторы класса Date
    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, Date& dd);

    Day day_of_week(const Date& d);                 // День недели d
    Date next_Sunday(const Date& d);                // Следующее воскресенье после d
    Date next_weekday(const Date& d);               // Следующий рабочий день после d

}   // Chrono
