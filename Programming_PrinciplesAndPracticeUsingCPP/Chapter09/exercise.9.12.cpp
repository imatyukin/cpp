// Файл exercise.9.12.cpp
//
// 12. Change the representation of a Date to be the number of days since January 1, 1970 (known as day 0), represented
// as a long int, and re-implement the functions from §9.8. Be sure to reject dates outside the range we can represent
// that way (feel free to reject days before day 0, i.e., no negative days).

#include "std_lib_facilities.h"
#include "exercise.9.12.Chrono.h"

int main()
try {
    Chrono::Date date;

    return 0;
}
catch (Chrono::Date::Invalid& e)
{
    cerr << "Invalid Date!\n";
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