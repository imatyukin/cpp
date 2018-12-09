// Файл exercise.9.12.cpp
//
// 12. Change the representation of a Date to be the number of days since January 1, 1970 (known as day 0), represented
// as a long int, and re-implement the functions from §9.8. Be sure to reject dates outside the range we can represent
// that way (feel free to reject days before day 0, i.e., no negative days).

#include "std_lib_facilities.h"
#include "exercise.9.12.Chrono.h"

void test_days_since_epoch(Chrono::Date d)
{
    cout << "Chrono::Date::days_since_epoch(): " << d.days_since_epoch()
         << " days have passed since epoch until " << d << '\n';
}

void test_add_day(Chrono::Date d, int nd, string msg)
{
    d.add_day(nd);
    cout << "Chrono::Date::add_day(" << nd << "): " << msg << d << '\n';
}

void test_add_month(Chrono::Date d, int nm, string msg)
{
    d.add_month(nm);
    cout << "Chrono::Date::add_month(" << nm << "): " << msg << d << '\n';
}

void test_add_year(Chrono::Date d, int ny, string msg)
{
    d.add_year(ny);
    cout << "Chrono::Date::add_year(" << ny << "): " << msg << d << '\n';
}

void test_day_of_week(Chrono::Date d)
{
    cout << "Chrono::day_of_week(): " << d << " is "
         << Chrono::day_of_week(d) << '\n';
}

void test_next_sunday(Chrono::Date d)
{
    cout << "Chrono::next_Sunday(): Next sunday to " << d << " ("
         << Chrono::day_of_week(d) << ") is " << Chrono::next_Sunday(d)
         << " (" << Chrono::day_of_week(Chrono::next_Sunday(d)) << ")\n";
}

void test_next_workday(Chrono::Date d)
{
    cout << "Chrono::next_workday(): Next workday to " << d << " ("
         << Chrono::day_of_week(d) << ") is " << Chrono::next_workday(d)
         << " (" << Chrono::day_of_week(Chrono::next_workday(d)) << ")\n";
}

void test_week_of_year(Chrono::Date d)
{
    cout << "Chrono::week_of_year(): For date " << d << " week of the year is "
         << Chrono::week_of_year(d) << '\n';
}

int main()
try
{
    Chrono::Date date;

    cout << '\n';
    test_days_since_epoch(date);
    test_days_since_epoch(Chrono::Date{2018, Chrono::Month::dec, 10});
    test_days_since_epoch(Chrono::Date{1979, Chrono::Month::jul, 26});
    test_days_since_epoch(Chrono::Date{3493});
    test_days_since_epoch(Chrono::Date{2019, Chrono::Month::jan, 1});
    test_days_since_epoch(Chrono::Date{17897});

    cout << '\n';
    date = Chrono::Date{2018, Chrono::Month::jan, 1};
    test_add_day(date, 7, "January the 8th 2018? ");
    test_add_day(date, 31, "February the 1st 2018? ");
    test_add_day(date, 59, "March the 1st 2018? ");
    test_add_day(date, 364, "December the 31th 2018? ");
    test_add_day(date, 365, "January the 1st 2019? ");
    test_add_day(date, 396, "February the 1st 2019? ");
    date = Chrono::Date{2018, Chrono::Month::jan, 15};
    test_add_day(date, 79, "April the 4th 2018? ");

    cout << '\n';
    date = Chrono::Date{2018, Chrono::Month::jan, 1};
    test_add_month(date, 1, "February the 1st 2018? ");
    test_add_month(date, 3, "April the 1st 2018? ");
    test_add_month(date, 6, "July the 1st 2018? ");
    test_add_month(date, 10, "November the 1st 2018? ");
    test_add_month(date, 15, "April the 1st 2019? ");
    date = Chrono::Date{2018, Chrono::Month::jan, 15};
    test_add_month(date, 1, "February the 15th 2018? ");
    test_add_month(date, 3, "April the 15th 2018? ");
    test_add_month(date, 6, "July the 15th 2018? ");
    test_add_month(date, 10, "November the 15th 2018? ");
    test_add_month(date, 15, "April the 15th 2019? ");
    date = Chrono::Date{2018, Chrono::Month::jan, 31};
    test_add_month(date, 1, "February the 28th 2018? ");
    test_add_month(date, 3, "April the 30th 2018? ");
    test_add_month(date, 6, "July the 31th 2018? ");
    test_add_month(date, 10, "November the 30th 2018? ");
    test_add_month(date, 15, "April the 30th 2019? ");
    date = Chrono::Date{2016, Chrono::Month::feb, 29};
    test_add_month(date, 1, "March the 29th 2018? ");
    test_add_month(date, 12, "February the 28th 2018? ");

    cout << '\n';
    date = Chrono::Date{2018, Chrono::Month::jan, 1};
    test_add_year(date, 1, "January the 1st 2019? ");
    test_add_year(date, 4, "January the 1st 2022? ");
    test_add_year(date, 8, "January the 1st 2026? ");
    date = Chrono::Date{2016, Chrono::Month::feb, 29};
    test_add_year(date, 1, "February the 28th 2017? ");
    test_add_year(date, 4, "February the 29th 2020? ");
    date = Chrono::Date{2019, Chrono::Month::mar, 15};
    test_add_year(date, 1, "March the 15th 2020? ");
    test_add_year(date, 4, "March the 15th 2023? ");
    date = Chrono::Date{2017, Chrono::Month::mar, 15};
    test_add_year(date, 1, "March the 15th 2018? ");
    test_add_year(date, 4, "March the 15th 2021? ");

    cout << '\n';
    test_day_of_week(Chrono::Date{1970, Chrono::Month::jan, 1});
    test_day_of_week(Chrono::Date{1978, Chrono::Month::feb, 23});
    test_day_of_week(Chrono::Date{2010, Chrono::Month::mar, 31});
    test_day_of_week(Chrono::Date{2019, Chrono::Month::may, 28});

    cout << '\n';
    test_next_sunday(Chrono::Date{2019, Chrono::Month::may, 28});
    test_next_sunday(Chrono::Date{2019, Chrono::Month::may, 24});
    test_next_sunday(Chrono::Date{2019, Chrono::Month::may, 29});

    cout << '\n';
    test_next_workday(Chrono::Date{2019, Chrono::Month::may, 24});
    test_next_workday(Chrono::Date{2019, Chrono::Month::may, 26});
    test_next_workday(Chrono::Date{2019, Chrono::Month::may, 27});
    test_next_workday(Chrono::Date{2019, Chrono::Month::may, 28});

    cout << '\n';
    test_week_of_year(Chrono::Date{2019, Chrono::Month::jan, 1});
    test_week_of_year(Chrono::Date{2019, Chrono::Month::jan, 9});
    test_week_of_year(Chrono::Date{2019, Chrono::Month::feb, 7});
    test_week_of_year(Chrono::Date{2019, Chrono::Month::mar, 15});
    test_week_of_year(Chrono::Date{2019, Chrono::Month::may, 28});

    cout << '\n';
    return 0;
}
catch (Chrono::Date::Invalid& e)
{
    cerr << "Invalid Date!!\n";
    return 1;
}
catch (exception& e)
{
    cerr << e.what() << '\n';
    return 2;
}
catch (...)
{
    cerr << "Unknown exception!\n";
    return 3;
}