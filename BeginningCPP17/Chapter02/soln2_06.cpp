// Exercise 2-6.
// Here’s an extra exercise for puzzle fans. Write a program that will prompt the user to enter two different positive
// integers. Identify in the output the value of the larger integer and the value of the smaller integer. Using the
// decision-making facilities of Chapter 5, this would be like stealing a piece of cake from a baby while walking in the
// park. What makes this a brain teaser, though, is that this can be done solely with the operators you’ve learned about
// in this chapter!
#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Identification of the value of the larger integer and the value of the smaller integer.\n"
              << std::endl;

    unsigned long int a, b;
    std::cout << "Enter two different positive integers: ";
    std::cin >> a >> b;

    const unsigned long int larger {(a * (a / b) + b * (b / a)) / (a / b + b / a)};
    const unsigned long int smaller {(b * (a / b) + a * (b / a)) / (a / b + b / a)};

    std::cout << "The larger integer is " << larger << "\n"
              << "The smaller integer is " << smaller << std::endl;
}