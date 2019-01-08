// Exercise 2-1.
// Write a program that will compute the area of a circle. The program should prompt for the radius of the circle to be
// entered from the keyboard, calculate the area using the formula area = pi * radius * radius, and then display the
// result.
#include <iostream>

int main()
{
    const double pi { 3.141592653589793238 };

    double radius {};

    std::cout << "Enter the circle radius: ";
    std::cin >> radius;

    const double area {pi * radius * radius};

    std::cout << "\nThe area of the circle is " << area << ".\n";
}