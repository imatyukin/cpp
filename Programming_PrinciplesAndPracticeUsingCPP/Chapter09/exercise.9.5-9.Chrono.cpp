#include "std_lib_facilities.h"
#include "exercise.9.5-9.Chrono.h"

namespace Chrono {

    // Операторы класса перечисления Month
    Month operator+(const Month& m, int n)
    {
        int r = int(m) + n;
        r %= int(Month::dec);

        if (r == 0) return Month::dec;
        return Month(r);
    }

    // Определение других операторов на основе +
    Month operator-(const Month& m, int n) { return (m+(-n)); }
    Month& operator+=(Month& m, int n) { m = m + n; return m; }

    bool operator<(const Month& m, int n) { return int(m) < n; }
    bool operator>(const Month& m, int n) { return int(m) > n; }

    // Определения функций членов Date
    Date::Date(int yy, Month mm, int dd)
            :y{yy}, m{mm}, d{dd}
    {
        if (!is_date(yy, mm, dd)) throw Invalid{};
    }

    const Date& default_date()
    {
        static Date dd{2001, Month::jan, 1};    // Начало XXI века
        return dd;
    }

    Date::Date():
            y{default_date().year()},
            m{default_date().month()},
            d{default_date().day()}
    {
    }

    void Date::add_day(int n)
    {
        // Принимаем (31 * 12) за дней в году, предполагая, что каждый месяц имеет 31 день
        int n_d = n % 31;          // дней вне месяцев, увеличить
        int n_m = (n / 31) % 12;   // месяцев вне лет, увеличить
        int n_y = n / (31*12);     // годы для увеличения

        d += n_d;
        // Проверка overflows
        if (d > 31) { ++n_m; d -= 31; }     // Day overflow
        if (d < 1)  { --n_m; d += 31; }     // Day underflow

        if (Month::dec < (int(m)+n_m)) ++n_y;
        if (Month::jan > (int(m)+n_m)) --n_y;
        m += n_m;   // m имеет тип Month
        y += n_y;
    }

    void Date::add_month(int n)
    {
        int n_m = n % 12;   // месяцев вне лет, увеличить
        int n_y = n / 12;   // годы для увеличения

        if (Month::dec < (int(m)+n_m)) ++n_y;
        if (Month::jan > (int(m)+n_m)) --n_y;
        m += n_m;   // m имеет тип Month
        y += n_y;
    }

    void Date::add_year(int n)
    {
        if (m == Month::feb && d == 29 && !leapyear(y+n)) {
            m = Month::mar;     // использование 1 марта вместо 29 февраля
            d = 1;
        }
        y += n;
    }

    // Вспомогательные функции
    bool is_date(int y, Month m, int d)
    {
        if (d <= 0) return false;   // d должно быть положительным
        if (m < Month::jan || m > Month::dec) return false;

        int days_in_month = 31;     // большинство месяцев имеют 31 день

        switch (m) {
            case Month::feb:            // длина февраля варьируется
                days_in_month = (leapyear(y)) ? 29 : 28;
                break;
            case Month::apr:
            case Month::jun:
            case Month::sep:
            case Month::nov:
                days_in_month = 30;
                break;
            default:
                break;
        }

        return days_in_month >= d;
    }

    bool leapyear(int y)
    {
        // ...
        return false;   // until properly implemented
    }

    bool operator==(const Date& a, const Date& b)
    {
        return a.year()  == b.year()
               && a.month() == b.month()
               && a.day()   == b.day();
    }

    bool operator!=(const Date& a, const Date& b)
    {
        return !(a == b);
    }

    ostream& operator<<(ostream& os, const Date& d)
    {
        return os << '(' << d.year()
                  << ',' << int(d.month())
                  << ',' << d.day() << ')';
    }

    istream& operator>>(istream& is, Date& dd)
    {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if (!is) return is;
        if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { // ошибка формата
            is.clear(ios_base::failbit);    // установить бит сбоя
            return is;
        }

        dd = Date{y, Month(m), d};

        return is;
    }

    Day day_of_week(const Date& d)
    {
        // ...
        return Day::sunday;     // until properly implemented
    }

    Date next_Sunday(const Date& d)
    {
        // ...
        return Date{default_date().year(),
                    default_date().month(),
                    default_date().day()};  // until properly implemented
    }

    Date next_weekday(const Date& d)
    {
        // ...
        return Date{default_date().year(),
                    default_date().month(),
                    default_date().day()};  // until properly implemented
    }

} // namespace Chrono