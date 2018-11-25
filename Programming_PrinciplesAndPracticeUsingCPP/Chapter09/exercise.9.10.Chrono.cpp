// 10. Implement leapyear() from §9.8.

#include "std_lib_facilities.h"
#include "exercise.9.10.Chrono.h"

namespace Chrono {

    // Операторы класса перечисления Month
    Month operator+(const Month& m, int n)
    {
        int r = int(m) + n;
        r %= int(Month::dec);

        if (r == 0) return Month::dec;  // Обратный эффект по модулю ...
        return Month(r);
    }

    // Определение других операторов, основанных на +
    Month operator-(const Month& m, int n) { return (m+(-n)); }
    Month& operator+=(Month& m, int n) { m = m + n; return m; }

    bool operator<(const Month& m, int n) { return int(m) < n; }
    bool operator>(const Month& m, int n) { return int(m) > n; }

    // Определение функций-членов Date:
    Date::Date(int yy, Month mm, int dd)
            : y{yy}, m{mm}, d{dd}
    {
        if (!is_date(yy,mm,dd)) throw Invalid{};
    }

    const Date& default_date()
    {
        static Date dd {2001,Month::jan,1}; // Начало XXI века
        return dd;
    }

    Date::Date():
            y{default_date().year()},
            m{default_date().month()},
            d{default_date().day()}
    {
    }

    void Date:: add_day(int n)
    {
        // Принимаем (31 * 12) дней в году, предполагая, что каждый месяц имеет 31 день
        int n_d = n % 31;          // Дней вне месяца, увеличить
        int n_m = (n / 31) % 12;   // Месяцев вне года, увеличить
        int n_y = n / (31*12);     // Лет увеличить

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
        int n_m = n % 12;   // Месяцев вне года, увеличить
        int n_y = n / 12;   // Лет увеличить

        if (Month::dec < (int(m)+n_m)) ++n_y;
        if (Month::jan > (int(m)+n_m)) --n_y;
        m += n_m;   // m имеет тип Month
        y += n_y;
    }

    void Date::add_year(int n)
    {
        if (m==Month::feb && d==29 && !leapyear(y+n)) {     // В невисокосный год
            m = Month::mar;                                 // 29 февраля превращается в 1 марта
            d = 1;
        }
        y+=n;
    }

    // Вспомогательные функции:
    bool is_date(int y, Month m, int d)
    {
        // Полагаем y корректным
        if (d<=0) return false;                     // d должно быть положительным
        if (m<Month::jan || Month::dec<m) return false;

        int days_in_month = 31;                     // В месяце не более 31 дня

        switch (m) {
        case Month::feb:                            // Длина февраля бывает разной
            days_in_month = (leapyear(y))?29:28;
            break;
        case Month::apr: case Month::jun: case Month::sep: case Month::nov:
            days_in_month = 30;                     // В этих месяцах 30 дней
            break;
        default:
            break;
        }

        if (days_in_month<d) return false;

        return true;
    }

    /*
	    Определение високосного года: любой год, делящийся на 4, за исключением столетних лет, не делящийся на 400
    */

    bool leapyear(int y)
    // Любой год делящийся на 4, за исключением столетних лет, которые не делятся на 400
    // % операция модуль (остаток от деления целых чисел)
    {
        if (y%4) return false;
        if (y%100==0 && y%400) return false;
        return true;
    }

    bool operator==(const Date& a, const Date& b)
    {
        return a.year()  == b.year()
            && a.month() == b.month()
            && a.day()   == b.day();
    }

    bool operator!=(const Date& a, const Date& b)
    {
        return !(a==b);
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
        if (ch1!= '(' || ch2!=',' || ch3!=',' || ch4!=')') {    // Ошибка формата
            is.clear(ios_base::failbit);                        // Устанавливаем бит ошибки
            return is;
        }

        dd = Date(y, Month(m),d);                               // Обновляем dd

        return is;
    }

    Day day_of_week(const Date& d)
    {
        // ...
        return Day::sunday;
    }

    Date next_Sunday(const Date& d)
    {
        // ...
        return Date{default_date().year(),
                    default_date().month(),
                    default_date().day()};
    }

    Date next_weekday(const Date& d)
    {
        // ...
        return Date{default_date().year(),
                    default_date().month(),
                    default_date().day()};
    }

}   // Chrono

int main()
try
{
    vector<int> year;           // для небольшого автоматического тестирования
    year.push_back(0);
    year.push_back(2000);
    year.push_back(1900);
    year.push_back(2009);
    year.push_back(2400);
    year.push_back(1968);
    year.push_back(1950);
    year.push_back(2010);
    year.push_back(2012);
    year.push_back(2020);
    year.push_back(1968);

    for (int i = 0; i<year.size(); ++i) {
        cout << year[i] << " is ";
        if (Chrono::leapyear(year[i])==false) cout << "not ";
        cout << "a leapyear\n";
    }

    // Ввод пользователя:
    cout<< "please enter a year: ";

    int n;
    while (cin>>n) {            // Читаем год
        cout << n << " is ";
        if (Chrono::leapyear(n)==false) cout << "not ";
        cout << "a leapyear\n";
        cout << "Try again: ";
    }
}
catch (runtime_error e) {	    // этот код предназначен для создания сообщений об ошибках
    cout << e.what() << '\n';
}
catch (...) {	                // этот код предназначен для создания сообщений об ошибках
    cout << "exiting\n";
}