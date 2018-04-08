// 4. Write a program that prompts the user to enter two integer values. Store these values in int variables named val1
// and val2. Write your program to determine the smaller, larger, sum, difference, product, and ratio of these values
// and report them to the user.
#include "std_lib_facilities.h"

int main()
{
    int val1, val2 = 0;

    cout << "Введите два целочисленных значения (val1 и val2):\n";
    cin >> val1 >> val2;

    cout << "val1 = " << val1 << ", " << "val2 = " << val2 << ".\n";

    if (val1 == val2) cout << "Значения val1 и val2 равны.\n";
    if (val1 > val2) cout << "Наибольшее значение val1 = " << val1 << ".\n";
    else cout << "Наибольшее значение val2 = " << val2 << ".\n";

    cout << "Сумма val1 и val2 = " << val1 + val2 << ".\n";
    cout << "Разность val1 и val2 = " << val1 - val2 << ".\n";
    cout << "Произведение val1 и val2 = " << val1 * val2 << ".\n";
    cout << "Частное val1 и val2 = " << val1 / val2 << ".\n";
}
