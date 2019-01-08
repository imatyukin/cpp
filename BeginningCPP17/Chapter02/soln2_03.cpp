// Exercise 2-3.
// Create a program that converts inches to feet and inches. In case you’re unfamiliar with imperial units: 1 foot
// equals 12 inches. An input of 77 inches, for instance, should thus produce an output of 6 feet and 5 inches. Prompt
// the user to enter an integer value corresponding to the number of inches and then make the conversion and output the
// result.
#include <iostream>

int main()
{
    std::cout << "Convert inches into feet and inches.\n" << std::endl;

    const unsigned int inches_per_foot {12};

    unsigned long int feet {}, inches {};

    unsigned long int total_inches {};
    std::cout << "Enter an integer value corresponding to the number of inches: ";
    std::cin >> total_inches;

    feet   = total_inches / inches_per_foot;
    inches = total_inches % inches_per_foot;

    std::cout << total_inches << " inches equals "
              << feet         << " feet and "
              << inches       << " inches." << std::endl;
}