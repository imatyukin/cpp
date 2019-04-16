// Exercise 5-2.
// Write a program that uses a while loop to accumulate the sum of an arbitrary number of integers entered by the user.
// After every iteration, ask the user whether he or she is done entering numbers. The program should output the total
// of all the values and the overall average as a floating-point value.
#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    std::vector<unsigned int> v;
    unsigned int input{}, sum_of_elems{};

    std::cout << "Enter arbitrary number of integers: ";
    while(std::cin >> input) {
        v.push_back(input);
        sum_of_elems += input;
        if(std::cin.get() == '\n'){
            std::cout << "Whether is done entering numbers?\n";
            std::cout << "Enter arbitrary number of integers to continue or press 'q': ";
            continue;
        }
    }
    std::cout << "The total of all the values is " << sum_of_elems << std::endl
              << "The overall average is " << std::fixed << std::setprecision(2)
              << static_cast<double>(sum_of_elems)/v.size() << std::endl;
}