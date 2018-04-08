// 6. Write a program that prompts the user to enter three integer values, and then outputs the values in numerical
// sequence separated by commas. So, if the user enters the values 10 4 6, the output should be 4, 6, 10. If two values
// are the same, they should just be ordered together. So, the input 4 5 4 should give 4, 4, 5.
#include "std_lib_facilities.h"

int main()
{
    int a, b, c = 0;
    int min, avg, max;

    cout << "Введите три целых числа:\n";
    cin >> a >> b >> c;

    min = a; max = a;

    if (b > max) max = b;
    if (b < min) min = b;
    if (c > max) max = c;
    if (c < min) min = c;

    if (max == min) avg = max;
    else {
        if (a != max and a != min) avg = a;
        if (b != max and b != min) avg = b;
        if (c != max and c != min) avg = c;

        if (b == max and b == a) avg = a;
        if (b == min and b == a) avg = a;
        if (c == max and c == a) avg = a;
        if (c == min and c == a) avg = a;

        if (a == max and a == b) avg = b;
        if (a == min and a == b) avg = b;
        if (c == max and c == b) avg = b;
        if (c == min and c == b) avg = b;

        if (a == max and a == c) avg = c;
        if (a == min and a == c) avg = c;
        if (b == max and b == c) avg = c;
        if (b == min and b == c) avg = c;
    }

    cout << min << ", " << avg << ", " << max;
}