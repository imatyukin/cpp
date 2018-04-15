// 9. Write a program that converts spelled-out numbers such as “zero” and “two” into digits, such as 0 and 2. When the
// user inputs a number, the program should print out the corresponding digit. Do it for the values 0, 1, 2, 3, and 4
// and write out not a number I know if the user enters something that doesn’t correspond, such as stupid computer!.
#include "std_lib_facilities.h"

int main()
{
    string number;

    cout << "Введите число в виде слова:\n";
    cin >> number;

    if (number == "нуль")
        cout << "0\n";
    else if (number == "один")
        cout << "1\n";
    else if (number == "два")
        cout << "2\n";
    else if (number == "три")
        cout << "3\n";
    else if (number == "четыре")
        cout << "4\n";
    else if (number == "пять")
        cout << "5\n";
    else if (number == "шесть")
        cout << "6\n";
    else if (number == "семь")
        cout << "7\n";
    else if (number == "восемь")
        cout << "8\n";
    else if (number == "девять")
        cout << "9\n";
    else
        cout << "Я не знаю такого числа!\n";
}
