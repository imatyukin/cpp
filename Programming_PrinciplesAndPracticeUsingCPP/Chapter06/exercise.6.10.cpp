// 10. A permutation is an ordered subset of a set. For example, say you wanted to pick a combination to a vault. There
// are 60 possible numbers, and you need three different numbers for the combination. There are P(60,3) permutations for
// the combination, where P is defined by the formula
//           a!
// P(a,b)= ------,
//         (a-b)!
// where ! is used as a suffix factorial operator. For example, 4! is 4*3*2*1.
// Combinations are similar to permutations, except that the order of the objects doesn’t matter. For example, if you
// were making a “banana split” sundae and wished to use three different flavors of ice cream out of five that you had,
// you wouldn’t care if you used a scoop of vanilla at the beginning or the end; you would still have used vanilla. The
// formula for combinations is
//         P(a,b)
// C(a,b)= ------.
//           b!
// Design a program that asks users for two numbers, asks them whether they want to calculate permutations or
// combinations, and prints out the result. This will have several parts. Do an analysis of the above requirements.
// Write exactly what the program will have to do. Then, go into the design phase. Write pseudo code for the program,
// and break it into sub-components. This program should have error checking. Make sure that all erroneous inputs will
// generate good error messages.
#include "std_lib_facilities.h"

constexpr long long factorial(int n);
int permutations(int a, int b);
int combinations(int a, int b);

int main()
try
{
    cout << "Введите два числа (разделённые пробелами)\n"
            "первое число - количество элементов во множестве,\n"
            "второе число - количество элементов в его подмножестве:" << endl;
    int a, b;
    if (!(cin >> a >> b)) error("два числа не целые");

    cout << "Введите, что необходимо вычислить:\n"
            "'P' - количество перестановок,\n"
            "'C' - количество сочетаний,\n"
            "'B' - количество перестановок и сочетаний:" << endl;

    bool permutation = false;
    bool combination = false;
    string str;
    cin >> str;
    if (str=="P")
        permutation = true;
    else if (str=="C")
        combination = true;
    else if (str=="B") {
        permutation = true;
        combination = true;
    }
    else
        error("неправильный ввод");

    if (permutation) cout << "P(" << a << ',' << b << ") = " << permutations(a, b) << endl;
    if (combination) cout << "C(" << a << ',' << b << ") = " << combinations(a, b) << endl;

    return 0;
}
catch (runtime_error e) {
    cout << e.what() << endl;
}

constexpr long long factorial(int n)
{
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    if (result < 1) {
        error("переполнение переменной");
        exit(0);
    }
    else
        return result;
}

int permutations(int a, int b)
{
    if (a < b || a < 1 || b < 1) error("неправильный размер перестановки");
    return factorial(a) / factorial(a - b);
}

int combinations(int a, int b)
{
    return permutations(a, b) / factorial(b);
}
