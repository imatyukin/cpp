// Exercise 4-6.
// Write a program that determines, using only the conditional operator, if an integer that is entered has a value that
// is 20 or less, is greater than 20 but not greater than 30, is greater than 30 but not exceeding 100, or is greater
// than 100.
#include <iostream>

int main() {
    int i {};

    std::cout << "Enter an integer: ";
    std::cin >> i;

    std::cout << "The integer that is entered has a value "
              << (i > 100? "greater than 100."
                : i > 30?  "greater than 30 but not exceeding 100."
                : i > 20?  "greater than 20 but not greater than 30."
                :          "is 20 or less.")
              << std::endl;
}