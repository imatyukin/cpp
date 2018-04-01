// Get this little program to run. Then, modify it to read an int rather than a double. Note that sqrt() is not defined
// for an int so assign n to a double and take sqrt() of that. Also, “exercise” some other operations. Note that for
// ints / is integer division and % is remainder (modulo), so that 5/2 is 2 (and not 2.5 or 3) and 5%2 is 1. The
// definitions of integer *, /, and % guarantee that for two positive ints a and b we have a/b * b + a%b == a.

// Простая программа, демонстрирующая работу операторов
#include "std_lib_facilities.h"

int main()
{
    cout << "Пожалуйста, введите значение с плавающей точкой: ";
    int n;
    cin >> n;
    cout << "n == " << n
         << "\nn+1 == " << n+1
         << "\nтри раза по n == " << 3*n
         << "\nдва раза по n == " << n+n
         << "\nn в квадрате == " << n*n
         << "\nполовина n == " << n/2
         << "\nвычисление остатка от деления n на 2 == " << n%2
         << "\nкорень квадратный из n == " << sqrt(double (n))
         << "\nдля двух положительных переменных а и b типа int выполняется равенство а/b*b + а%b == а"
         << endl; // Переход на новую строку
}
