// 11. Write a program that writes out the first so many values of the Fibonacci series, that is, the series that starts
// with 1 1 2 3 5 8 13 21 34. The next number of the series is the sum of the two previous ones. Find the largest
// Fibonacci number that fits in an int.
#include "std_lib_facilities.h"
#include <limits>

int Fibonacci(int n);

int main()
{
    int imax = numeric_limits<int>::max();
    int n = 2;

    cout << "Последовательность Фибоначчи: ";
    while (Fibonacci(n) <= 34) {
        cout << Fibonacci(n) << ' ';
        ++n;
    }
    cout << "\b" << endl;

    cout << "Наибольшее число Фибоначчи, которое можно записать в переменную типа int: ";
    while (Fibonacci(n) > 0 && Fibonacci(n) <= imax)
        n++;
    cout << Fibonacci(n - 1) << endl;

    return 0;
}

// Calculate the nth Fibonacci number (n greater than 1 and counting the first 1 in the sequence as the second term)
int Fibonacci(int n) {
    int a = 0;
    int b = 1;
    int k = 2;
    while (n > k) {
        int c = a + b;
        a = b;
        b = c;
        k = k + 1;
    }
    return b;
}
