// Файл exercise.9.12.Chrono.cpp

#include "std_lib_facilities.h"
#include "exercise.9.12.Chrono.h"

namespace Chrono {


    // Операторы класса Day

    Day operator+(const Day& d, int n)
    {
        int r{int(d)+n};
        r %= 7;    // Количество дней в неделе
        return Day(r);
    }

    Day& operator+=(Day& d, int n)
    {
        d = d + n;
        return d;
    }

    ostream& operator<<(ostream& os, const Day& d)
    {
        switch (d) {
            case Day::sunday:
                os << "Sunday";
                break;
            case Day::monday:
                os << "Monday";
                break;
            case Day::tuesday:
                os << "Tuesday";
                break;
            case Day::wednesday:
                os << "Wednesday";
                break;
            case Day::thursday:
                os << "Thursday";
                break;
            case Day::friday:
                os << "Friday";
                break;
            case Day::saturday:
                os << "Saturday";
                break;
            default:
                error("Day output: invalid day");
        }
        return os;
    }


    // Операторы класса Month

    Month operator+(const Month& m, int n)
    {
        int r{int(m)+n};
        r %= int(Month::dec);

        if (r == 0) return Month::dec;            // Отменяет эффект по модулю
        return Month(r);
    }

    Month& operator++(Month& m)
    {
        m = m + 1;
        return m;
    }


    // Операторы класса Date

    bool operator==(const Date& a, const Date& b)
    {
        return a.days_since_epoch() == b.days_since_epoch();
    }

    bool operator!=(const Date& a, const Date& b)
    {
        return !(a == b);
    }

    bool operator<=(const Date& a, const Date& b)
    {
        return a.days_since_epoch() <= b.days_since_epoch();
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
        if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {     // Ошибка формата
            is.clear(ios_base::failbit);                                // установить бит сбоя
            return is;
        }

        dd = Date{y, Month(m), d};

        return is;
    }


    // Вспомогательные функции класса Month

    int month_days(Month m, int y)
    {
        switch (m) {
            case Month::apr:
            case Month::jun:
            case Month::sep:
            case Month::nov:
                return 30;
            case Month::feb:
                if (leapyear(y))
                    return 29;
                return 28;
            default:
                return 31;
        }
    }


    // Вспомогательные функции Date

    bool leapyear(int y)
    {
        return ((y%4 == 0) && !(y%100 == 0)) || (y%400 == 0);
    }

    int n_leaps(int y)
    // Возвращает количество високосных лет от epoch_year до года, предшествующего y
    {
        if (y < epoch_year) throw Date::Invalid{};

        int n{0};
        for (int i = epoch_year; i < y; ++i)
            if (leapyear(i)) ++n;
        return n;
    }

    bool is_date(int y, Month m, int d)
    {
        if (y < epoch_year) return false;               // Ограничение представления
        if (d <= 0) return false;                       // d должен быть положительным
        if (m < Month::jan || m > Month::dec) return false;

        int month_days{31};                             // В большинстве месяцев 31 день

        switch (m) {
            case Month::feb:                            // Длина февраля варьируется
                month_days = (leapyear(y)) ? 29 : 28;
                break;
            case Month::apr:
            case Month::jun:
            case Month::sep:
            case Month::nov:
                month_days = 30;
                break;
            default:                                    // Избегание предупреждений компилятора
                break;
        }

        return month_days >= d;
    }

    long int days_since_epoch(int y, Month m, int d)
    {
        if (!is_date(y, m, d)) throw Date::Invalid{};

        int dse{0};

        dse += (y-epoch_year)*365 + n_leaps(y);
        for (Month i = Month::jan; i < m; ++i)
            dse += month_days(i, y);

        return (dse + d - 1);                           // 1 января 1970 - нулевой день
    }

    Day day_of_week(const Date& d)
    {
        return epoch_dow + (d.days_since_epoch() % 7);
    }

    Date next_Sunday(const Date& d)
    // Возвращает следующее воскресенье даты d. Если d воскресенье, то за неделю до
    {
        Day dow{day_of_week(d)};                        // День недели для даты d
        Date r{d};
        r.add_day(7 - int(dow));
        return r;
    }

    Date next_workday(const Date& d)
    {
        Day dow{day_of_week(d)};                        // Неделя для даты d
        Date r{d};

        r.add_day(1);
        if (dow == Day::saturday) r.add_day(1);
        if (dow == Day::friday ) r.add_day(2);

        return r;
    }

    int week_of_year(const Date& d)
    {
        Date wd{Date(d.year(), Month::jan, 1)};         // Дата первой недели
        int week{1};

        wd = next_Sunday(wd);
        while (wd <= d) {                               // Если дата воскресенье, необходимо достичь её
            wd = next_Sunday(wd);
            ++week;
        }

        return week;
    }

    // Определение членов функций Date

    Date::Date(int yy, Month mm, int dd)
    {
        if (!is_date(yy, mm, dd)) throw Invalid{};
        dse = Chrono::days_since_epoch(yy, mm, dd);
    }

    Date::Date(long int days) : dse{days}
    {
        if (dse < 0) throw Invalid{};
    }

    Date::Date(): dse{0} { };

    int Date::day() const
    {
        // dse = 0 -> 1 января
        return dse - Chrono::days_since_epoch(year(), month(), 1) + 1;
    }

    Month Date::month() const
    {
        // Оставшиеся дни с 1 января
        int y{year()};
        long int rd{dse - Chrono::days_since_epoch(year(), Month::jan, 1)};

        Month m{Month::jan};
        while (rd >= Chrono::month_days(m, y)) {
            rd -= Chrono::month_days(m, y);
            ++m;
        }

        return m;
    }

    int Date::year() const
    {
        long int y{dse/365};
        long int rd{dse-(y*365)};
        if ((rd - n_leaps(epoch_year+y)) < 0 ) --y;     // Регулирование дней високосных лет

        return (epoch_year + y);
    }

    long int Date::days_since_epoch() const
    {
        return dse;
    }

    void Date::add_day(int n)
    {
        if (n < 0) error("Date::add_day(): only positives increments allowed.");

        dse += n;
    }

    void Date::add_month(int n)
    {
        if (n < 0) error("Date::add_month(): only positives increments allowed.");

        int y{year()};
        Month m{month()};
        bool last{month_days(m, y) == day()};           // Последний день месяца

        for (int i = 0; i < n; ++i) {
            dse += month_days(m, y);
            ++m;
            if (m == Month::jan) ++y;
        }

        if (last && (day()<4)) dse -= day();
    }

    void Date::add_year(int n)
    {
        add_month(n*12);
    }

} // namespace Chrono