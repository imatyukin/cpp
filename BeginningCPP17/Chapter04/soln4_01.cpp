// Exercise 4-1.
// Write a program that prompts for two integers to be entered and then uses an if-else statement to output a message
// that states whether the integers are the same.
#include <iostream>

int main()
{
    int a, b;
    std::cout << "Input two integers: ";
    std::cin >> a >> b;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << (a < b ? "a is less than b." : (a == b ? "a is equal to b." : "a is greater than b."));
}