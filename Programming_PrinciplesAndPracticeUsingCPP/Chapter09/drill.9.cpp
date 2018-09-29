// This drill simply involves getting the sequence of versions of Date to work. For each version define a Date called
// today initialized to June 25, 1978. Then, define a Date called tomorrow and give it a value by copying today into it
// and increasing its day by one using add_day(). Finally, output today and tomorrow using a << defined as in §9.8.
// Your check for a valid date may be very simple. Feel free to ignore leap years. However, don’t accept a month that is
// not in the [1,12] range or day of the month that is not in the [1,31] range. Test each version with at least one
// invalid date (e.g., 2004, 13, –5).
// 1. The version from §9.4.1
// 2. The version from §9.4.2
// 3. The version from §9.4.3
// 4. The version from §9.7.1
// 5. The version from §9.7.4

#include <iostream>
#include "drill.9.Chrono.h"

using namespace std;

void Chrono941::init_day(Date& dd, int y, int m, int d)
{
    // Проверяет, является ли (y,m,d) правильной датой,
    // и, если является, то инициализирует объект dd
    if (m < 1 || m > 12) cout << ("init_day: Invalid month") << endl;
    if (d < 1 || d > 31) cout << ("init_day: Invalid day") << endl;

    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void Chrono941::add_day(Date& dd, int n)
{
    // Увеличивает объект dd на n дней
    dd.d += n;

    if (dd.d > 31) { ++dd.m; dd.d -= 31; }      // Day overflow
    if (dd.d < 1)  { --dd.m; dd.d += 31; }      // Day underflow
    if (dd.m > 12) { ++dd.y; dd.m -= 12; }      // Month overflow
    if (dd.m < 1)  { --dd.y; dd.m += 12; }      // Month underfow
}

ostream& Chrono941::operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d << ')';
}

Chrono942::Date::Date(int yy, int mm, int dd)
{
    // Простой (и некорректный) конструктор даты с помощью простых (и некорректных) проверок
    if (mm < 1 || mm > 12) cout << ("init_day: Invalid month") << endl;
    if (dd < 1 || dd > 31) cout << ("init_day: Invalid day") << endl;

    y = yy;
    m = mm;
    d = dd;
}

void Chrono942::Date::add_day(int n)
{
    // Увеличивает или уменьшает объект d на n дней
    d += n;

    if (d > 31) { ++m; d -= 31; }               // Day overflow
    if (d < 1)  { --m; d += 31; }               // Day underflow
    if (m > 12) { ++y; m -= 12; }               // Month overflow
    if (m < 1)  { --y; m += 12; }               // Month underfow
}

ostream& Chrono942::operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d << ')';
}

Chrono943::Date::Date(int yy, int mm, int dd)
{
    // Простой (и некорректный) конструктор даты с помощью простых (и некорректных) проверок
    if (mm < 1 || mm > 12) cout << ("init_day: Invalid month") << endl;
    if (dd < 1 || dd > 31) cout << ("init_day: Invalid day") << endl;

    y = yy;
    m = mm;
    d = dd;
}

void Chrono943::Date::add_day(int n)
{
    // Увеличивает или уменьшает объект d на n дней

    // Принимает (31*12) дней в году, предполагая, что каждый месяц имеет 31 день
    int n_d = n % 31;          // дней вне месяцев, увеличить
    int n_m = (n / 31) % 12;   // месяцев вне лет, уменьшить
    int n_y = n / (31*12);     // годы увеличить

    y += n_y;
    m += n_m;
    d += n_d;

    if (d > 31) { ++m; d -= 31; }               // Day overflow
    if (d < 1)  { --m; d += 31; }               // Day underflow
    if (m > 12) { ++y; m -= 12; }               // Month overflow
    if (m < 1)  { --y; m += 12; }               // Month underfow
}

ostream& Chrono943::operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
}

Chrono971::Month Chrono971::operator+(const Month& m, int n)
{
    int r = int(m) + n;
    r %= int(Month::dec);

    if (r == 0) return Month::dec;              // Обратный эффект по модулю ...
    return Month(r);
}

Chrono971::Month Chrono971::operator-(const Month& m, int n) { return (m+(-n)); }
Chrono971::Month& Chrono971::operator+=(Month& m, int n) { m = m + n; return m; }

bool Chrono971::operator<(const Month& m, int n) { return int(m) < n; }
bool Chrono971::operator>(const Month& m, int n) { return int(m) > n; }

Chrono971::Date::Date(int yy, Month mm, int dd)
        :y{yy}, m{mm}, d{dd}
{
    if (!is_valid()) throw Invalid{};
}

bool Chrono971::Date::is_valid()
// Проверяет, является ли текущее состояние объекта Date действительным
{
    if (d < 1 || d > 31) return false;
    if (m < Month::jan || m > Month::dec) return false;
    return true;
}

void Chrono971::Date::add_day(int n)
// Функция добавления или вычитания дней из даты.
{
    // Принимает (31*12) дней в году, предполагая, что каждый месяц имеет 31 день
    int n_d = n % 31;                           // дней вне месяцев, увеличить
    int n_m = (n / 31) % 12;                    // месяцев вне лет, уменьшить
    int n_y = n / (31*12);                      // годы увеличить

    d += n_d;
    // Check for overflows
    if (d > 31) { ++n_m; d -= 31; }             // Day overflow
    if (d < 1)  { --n_m; d += 31; }             // Day underflow

    // Проверка потери изменения года
    if (Month::dec < (int(m)+n_m)) ++n_y;
    if (Month::jan > (int(m)+n_m)) --n_y;
    m += n_m;                                   // m имеет тип месяца
    y += n_y;
}

ostream& Chrono971::operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << int(d.month())
              << ',' << d.day() << ')';
}

Chrono974::Month Chrono974::operator+(const Month& m, int n)
{
    int r = int(m) + n;
    r %= int(Month::dec);

    if (r == 0) return Month::dec;              // Обратный эффект по модулю ...
    return Month(r);
}

Chrono974::Month Chrono974::operator-(const Month& m, int n) { return (m+(-n)); }
Chrono974::Month& Chrono974::operator+=(Month& m, int n) { m = m + n; return m; }

bool Chrono974::operator<(const Month& m, int n) { return int(m) < n; }
bool Chrono974::operator>(const Month& m, int n) { return int(m) > n; }

Chrono974::Date::Date(int yy, Month mm, int dd)
        :y{yy}, m{mm}, d{dd}
{
    if (!is_valid()) throw Invalid{};
}

bool Chrono974::Date::is_valid()
// Проверяет, является ли текущее состояние объекта Date действительным
{
    if (d < 1 || d > 31) return false;
    if (m < Month::jan || m > Month::dec) return false;
    return true;
}

void Chrono974::Date::add_day(int n)
// Функция добавления или вычитания дней из даты.
{
    // Принимает (31*12) дней в году, предполагая, что каждый месяц имеет 31 день
    int n_d = n % 31;                           // дней вне месяцев, увеличить
    int n_m = (n / 31) % 12;                    // месяцев вне лет, уменьшить
    int n_y = n / (31*12);                      // годы увеличить

    d += n_d;
    // Check for overflows
    if (d > 31) { ++n_m; d -= 31; }             // Day overflow
    if (d < 1)  { --n_m; d += 31; }             // Day underflow

    // Проверка потери изменения года
    if (Month::dec < (int(m)+n_m)) ++n_y;
    if (Month::jan > (int(m)+n_m)) --n_y;
    m += n_m;                                   // m имеет тип месяца
    y += n_y;
}

void Chrono974::Date::add_month(int n)
// Функция добавления или вычитания месяца из даты.
{
    int n_m = n % 12;                           // месяцев вне лет, уменьшить
    int n_y = n / 12;                           // годы увеличить

    // Проверка потери изменения года
    if (Month::dec < (int(m)+n_m)) ++n_y;
    if (Month::jan > (int(m)+n_m)) --n_y;
    m += n_m;                                   // m имеет тип месяца
    y += n_y;
}

void Chrono974::Date::add_year(int n)
// Функция добавления или вычитания лет из даты.
{
    y += n;
}

ostream& Chrono974::operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << int(d.month())
              << ',' << d.day() << ')';
}

void the_version_from_9_4_1()
{
    using namespace Chrono941;

    cout << "The version from §9.4.1:\n";
    Date today;                                 // Переменная типа Date (именованный объект)
    init_day(today, 1978, 6, 25);

    Date tomorrow{today};
    add_day(tomorrow, 1);

    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;

    Date invalid_date;
    init_day(invalid_date, 2004, 13, -5);
}

void the_version_from_9_4_2()
{
    using namespace Chrono942;

    cout << "\nThe version from §9.4.2:\n";
    Date today{1978, 6, 25};                    // OK (краткий стиль)

    Date tomorrow{today};
    tomorrow.add_day(1);

    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;

    Date invalid_date{2004, 13, -5};
}

void the_version_from_9_4_3()
{
    using namespace Chrono943;

    cout << "\nThe version from §9.4.3:\n";
    Date today{1978, 6, 25};

    Date tomorrow{today};
    tomorrow.add_day(1);

    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;

    Date invalid_date{2004, 13, -5};
}

void the_version_from_9_7_1()
{
    using namespace Chrono971;

    cout << "\nThe version from §9.7.1:\n";
    Date today{1978, Month::jun, 25};

    Date tomorrow{today};
    tomorrow.add_day(1);

    cout << "Today: " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;

    // Date invalid_date{2004, Month::dec, -5};
}

void the_version_from_9_7_4()
{
    using namespace Chrono974;

    cout << "\nThe version from §9.7.4:\n";
    Date today{1978, Month::jun, 25};

    Date tomorrow{today};
    tomorrow.add_day(1);

    cout << "Today: " << today << '\n';
    cout << "Tomorrow: " << tomorrow << '\n';

    Date invalid_date{2004, Month::dec, -5};
}

int main()
try
{
    the_version_from_9_4_1();
    the_version_from_9_4_2();
    the_version_from_9_4_3();
    the_version_from_9_7_1();
    the_version_from_9_7_4();

    return 0;
}
catch (runtime_error e) {                       // этот код предназначен для создания сообщений об ошибках
    cout << e.what() << '\n';
}
catch (...) {                                   // этот код предназначен для создания сообщений об ошибках
    cout << "exiting\n";
}