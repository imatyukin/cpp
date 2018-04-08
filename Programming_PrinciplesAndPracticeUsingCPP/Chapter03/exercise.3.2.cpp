// 2 Write a program in C++ that converts from miles to kilometers. Your program should have a reasonable prompt for
// the user to enter a number of miles. Hint: There are 1.609 kilometers to the mile.
#include "std_lib_facilities.h"

int main()
{
    double mi = 0;

    cout << "Введите количество миль:\n";
    cin >> mi;

    cout << mi << " миль = " << mi * 1.609 << " километров.\n";
}
