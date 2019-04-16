// Exercise 5-1.
// Write a program that outputs the squares of the odd integers from 1 up to a limit that is entered by the user.
#include <iostream>

int main()
{
    unsigned int limit{};
    std::cout << "This program outputs the squares of the odd integers from 1 up to a limit.\n";
    std::cout << "What upper limit would you like? ";
    std::cin >> limit;

    for(unsigned int i {1}; i <= limit; i++)
        if(i % 2 !=0)
            std::cout << i*i << " ";
}