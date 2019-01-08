// Exercise 2-2.
// Using your solution for Exercise 2-1, improve the code so that the user can control the precision of the output by
// entering the number of digits required. To really show off how accurate floating-point numbers can be, you can
// perhaps switch to double-precision floating-point arithmetic as well. You’ll need a more precise approximation of
// π. 3.141592653589793238 will do fine.
#include <iostream>
#include <iomanip>

int main()
{
    const double pi { 3.141592653589793238 };

    double radius {};

    std::cout << "Enter the circle radius: ";
    std::cin >> radius;

    const auto area {pi * radius * radius};

    int precision {};
    std::cout << "Enter the required number of digits for control the precision of the output: ";
    std::cin >> precision;

    std::cout << "\nThe area of the circle is "
              << std::setprecision(precision) << area << "." << std::endl;
}