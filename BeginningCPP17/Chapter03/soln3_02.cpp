// Exercise 3-2.
// Write a program to calculate how many square boxes can be contained in a single layer on a rectangular shelf, with no
// overhang. The dimensions of the shelf in feet and the dimension of a side of the box in inches are read from the
// keyboard. Use variables of type double for the length and depth of the shelf and type int for the length of the side
// of a box. Define and initialize an integer constant to convert from feet to inches (1 foot equals 12 inches).
// Calculate the number of boxes that the shelf can hold in a single layer of type long and output the result.
#include <iostream>

int main()
{
    std::cout << "The program to calculate how many square boxes can be contained in a single layer on a rectangular "
              << "shelf, with no overhang.\n" << std::endl;

    const double inches_per_foot {12.0};

    double shelf_length {}, shelf_depth {};     // The length and depth of the shelf in feet
    unsigned int side_box_length {};            // The length of the side of a box in inches
    unsigned long int number_boxes;             // The number of boxes that the shelf can hold in a single layer

    std::cout << "Enter the dimensions of the shelf in feet and the dimension of a side of the box in inches: ";
    std::cin >> shelf_length >> shelf_depth >> side_box_length;

    const double area_shelf {(shelf_length * inches_per_foot) * (shelf_depth * inches_per_foot)};
    const unsigned int area_box {side_box_length * side_box_length};

    number_boxes = static_cast<unsigned long int>(area_shelf) / static_cast<unsigned long int>(area_box);

    std::cout << "\nThe number of boxes that the shelf can hold in a single layer is "
              << number_boxes << std::endl;
}