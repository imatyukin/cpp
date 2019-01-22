// Exercise 3-1.
// Create a program that prompts for input of an integer and store it as an int. Invert all the bits in the value and
// store the result. Output the original value, the value with the bits inverted, and the inverted value plus 1, each in
// hexadecimal representation and on one line. On the next line, output the same numbers in decimal representation.
// These two lines should be formatted such that they look like a table, where the values in the same column are right
// aligned in a suitable field width. All hexadecimal values should have leading zeros so eight hexadecimal digits
// always appear.
// Note: Flipping all bits and adding one—ring any bells? Can you perhaps already deduce what the output will be before
// you run the program?
#include <iostream>
#include <iomanip>

int main()
{
    int i;
    std::cout << "Enter any integer: ";
    std::cin >> i;
    int invert_i {~i};

    std::cout << "\nIn decimal representation:";
    std::cout << "\nThe original value = " << i;
    std::cout << "\nThe value with the bits inverted = " << invert_i;
    std::cout << "\nThe inverted value plus 1 = " << invert_i + 1;

    std::cout << "\n\nIn hexadecimal representation:" << std::hex << std::showbase;
    std::cout << "\nThe original value = " << i;
    std::cout << "\nThe value with the bits inverted = " << invert_i;
    std::cout << "\nThe inverted value plus 1 = " << invert_i + 1;

    std::cout << "\n\nOn one line:\n" << std::setfill('0');
    std::cout << std::setw(10) << std::right << std::internal << i << '|';
    std::cout << std::setw(10) << std::right << std::internal << invert_i << '|';
    std::cout << std::setw(10) << std::right << std::internal << invert_i + 1 << std::endl;

    std::cout << std::setfill(' ') << std::dec;
    std::cout << std::setw(10) << std::right << i << '|';
    std::cout << std::setw(10) << std::right << invert_i << '|';
    std::cout << std::setw(10) << std::right << invert_i + 1 << std::endl;
}