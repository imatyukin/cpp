// Implement square() without using the multiplication operator; that is, do the x*x by repeated addition (start a
// variable result at 0 and add x to it x times). Then run some version of “the first program” using that square().
#include "std_lib_facilities.h"

int square(int x)   // Используя оператор умножения
{
    return x*x;
}

int repeat_add_square(int x)   // Используя повторяющееся сложение
{
    int result = 0;

    for (int i = 0; i < x; ++i) {
        result += x;
    }

    return result;
}

int main()
{
    cout << repeat_add_square(7) << '\n';
    cout << square(7) << '\n';
}
