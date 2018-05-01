// Go through this drill step by step. Do not try to speed up by skipping steps. Test each step by entering at least
// three pairs of values — more values would be better.
// 1. Write a program that consists of a while-loop that (each time around the loop) reads in two ints and then prints
// them. Exit the program when a terminating '|' is entered.
// 2. Change the program to write out the smaller value is: followed by the smaller of the numbers and the larger value
// is: followed by the larger value.
// 3. Augment the program so that it writes the line the numbers are equal (only) if they are equal.
// 4. Change the program so that it uses doubles instead of ints.
// 5. Change the program so that it writes out the numbers are almost equal after writing out which is the larger and
// the smaller if the two numbers differ by less than 1.0/100.
#include "std_lib_facilities.h"

int main()
{
    double number1 = 0;
    double number2 = 0;
    double smallest = 0;
    double largest = 0;

    cout << "Введите два числа или '|' для выхода из программы:\n";
    while( cin.good() ) {
        char c;
        c = cin.peek();

        if (c == '|')
            break;
        else {
            cin >> number1 >> number2;
            largest = smallest = number1;
            if (number1 != number2) {
                if (number2 > largest)
                    largest = number2;
                if (number2 < smallest)
                    smallest = number2;
                cout << "Наименьшее значение равно: " << smallest << endl;
                cout << "Наибольшее значение равно: " << largest << endl;
                double diff = 1.0/100;
                if ((largest - smallest) <= diff)
                    cout << "Числа почти равны" << endl;
            } else {
                cout << "Числа равны" << endl;
            }
        }
    }

    return 0;
}
