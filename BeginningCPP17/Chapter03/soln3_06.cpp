// Exercise 3-6.
// We’ll conclude with one more exercise for puzzle fans (and exclusively so). Write a program that prompts for two
// integer values to be entered and store them in integer variables, a and b, say. Swap the values of a and b without
// using a third variable. Output the values of a and b.
// Hint: This is a particularly tough nut to crack. To solve this puzzle, you exclusively need one single compound
// assignment operator.
#include <iostream>

int main()
{
    std::cout << "Swap the values of a and b without using a third variable.\n" << std::endl;

    int a, b;
    std::cout << "Enter two integer values: ";
    std::cin >> a >> b;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    a ^= b;
    b ^= a;
    a ^= b;
    std::cout << "After swapping (using bitwise XOR):\na = " << a << ", b = " << b << std::endl;
}