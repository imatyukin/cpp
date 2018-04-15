// 8. Write a program to test an integer value to determine if it is odd or even. As always, make sure your output is
// clear and complete. In other words, don’t just output yes or no. Your output should stand alone, like The value 4 is
// an even number. Hint: See the remainder (modulo) operator in §3.4.
#include "std_lib_facilities.h"

int main()
{
    int number = 0;

    cout << "Введите целое число:\n";
    cin >> number;

    if(number % 2 == 0) // чётное
        cout << "Число " << number << " является чётным.\n";
    else
        cout << "Число " << number << " является нечётным.\n";
}
