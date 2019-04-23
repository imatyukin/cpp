// Exercise 5-3.
// Create a program that uses a do-while loop to count the number of nonwhitespace characters entered on a line. The
// count should end when the first # character is found.
#include <iostream>
#include <vector>

int main()
{
    std::cout << "The program counts the number of nonwhitespace characters." << std::endl;
    std::cout << "The count ends when the first # character is found.\n" << std::endl;

    std::vector<char> line;
    char next;

    std::cout << "Enter some text: ";

    do {
        std::cin.get(next);
        line.push_back(next);
    } while (next != '#');

    // count the number of white spaces
    long numberOfWhiteSpace = count(line.begin(), line.end(), ' ');
    // subtract that number from the total length of string
    std::cout << "\nThe number of nonwhitespace: " << line.size() - 1 - numberOfWhiteSpace;
}