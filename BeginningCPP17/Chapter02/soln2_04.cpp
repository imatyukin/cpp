// Exercise 2-4.
// For your birthday you’ve been given a long tape measure and an instrument that measures angles (the angle between the
// horizontal and a line to the top of a tree, for instance). If you know the distance, d, you are from a tree, and the
// height, h, of your eye when peering into your angle-measuring device, you can calculate the height of the tree with
// the formula h + d*tan(angle). Create a program to read h in inches, d in feet and inches, and angle in degrees from
// the keyboard, and output the height of the tree in feet.
#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Tree height calculation.\n" << std::endl;

    const unsigned int inches_per_foot {12};

    unsigned long int height_feet {}, height_inches {}; // the height of the tree in feet and inches

    unsigned long int h {};                             // h in inches
    std::cout << "Enter the height, h, of your eye when peering into your angle-measuring device in inches: ";
    std::cin >> h;

    unsigned long int d_feet {}, d_inches {};           // d in feet and inches
    std::cout << "Enter the distance, d, you are from a tree in feet and inches: ";
    std::cin >> d_feet >> d_inches;

    double angle {};                                    // angle in degrees
    std::cout << "Enter the angle between the horizontal and a line to the top of a tree in degrees: ";
    std::cin >> angle;

    d_inches = d_feet * inches_per_foot + d_inches;

    height_inches = h + d_inches * std::tan(angle);

    height_feet = height_inches / inches_per_foot;
    height_inches = height_inches % inches_per_foot;

    std::cout << "The height of the tree in feet is "
              << height_feet << "." << height_inches << std::endl;
}