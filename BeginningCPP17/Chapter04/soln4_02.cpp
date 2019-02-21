// Exercise 4-2.
// Write another program that prompts for two integers to be entered. This time, any negative number or zero is to be
// rejected. Next, check whether one of the (strictly positive) numbers is an exact multiple of the other. For example,
// 63 is a multiple of 1, 3, 7, 9, 21, or 63. Note that the user should be allowed to enter the numbers in any order.
// That is, it does not matter whether the user enters the largest number first or the smaller one; both should work
// correctly!
#include <iostream>

int main() {
    int a {}, b {};

    std::cout << "Input two positive integers: ";
    std::cin >> a >> b;
    std::cout << std::endl;

    if (a <= 0 || b <= 0) {
        std::cout << "Any negative number or zero is rejected." << std::endl;
        return 1;
    }
    else {
        if (a % b == 0) {
            std::cout << a << " is exactly multiple of " << b << std::endl;
        }
        else if (b % a == 0) {
            std::cout << b << " is exactly multiple of " << a << std::endl;
        }
        else {
            std::cout << "This are not exactly multiple numbers" << std::endl;
        }
    }
}