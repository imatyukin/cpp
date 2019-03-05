// Exercise 4-3.
// Create a program that prompts for input of a number (nonintegral numbers are allowed) between 1 and 100. Use a nested
// if, first to verify that the number is within this range and then, if it is, to determine whether it is greater than,
// less than, or equal to 50. The program should output information about what was found.
#include <iostream>

int main() {
    double number {};

    std::cout << "Enter a number (nonintegral numbers are allowed) between 1 and 100: ";
    std::cin >> number;
    std::cout << std::endl;

    if (number > 0 && number <= 100) {
        std::cout << "The number is " << number << "." << std::endl;
        std::cout << (number > 50 ? "The number is greater than 50." :
                     (number == 50 ? "The number is equal to 50." : "The number is less than 50."));
    }
    else {
        std::cout << "The numbers outside the range from 1 to 100 is not allowed." << std::endl;
        return 1;
    }
}