// 7. Do exercise 6, but with three string values. So, if the user enters the values Steinbeck, Hemingway, Fitzgerald,
// the output should be Fitzgerald, Hemingway, Steinbeck.
#include "std_lib_facilities.h"

int main()
{
    string a, b, c;
    string min, avg, max;

    cout << "Введите три строковых значения:\n";
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
