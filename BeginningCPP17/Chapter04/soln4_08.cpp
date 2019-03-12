// Exercise 4-8.
// Create a program that prompts the user to enter an amount of money between $0 and $10 (decimal places allowed). Any
// other value is to be rejected politely. Determine how many quarters (25c), dimes (10c), nickels (5c), and pennies
// (1c) are needed to make up that amount. For our non-American readers, one dollar ($) equals 100 cents (c). Output
// this information to the screen and ensure that the output makes grammatical sense (for example, if you need only one
// dime, then the output should be “1 dime” and not “1 dimes”).
#include <iostream>

int main() {
    const unsigned int quarter {25};
    const unsigned int dime {10};
    const unsigned int nickel {5};
    const unsigned int penny {1};

    double money {0.0};
    std::cout << "Enter an amount of money between $0 and $10 (decimal places allowed): ";
    std::cin >> money;

    if (money >=0 && money <= 10.0) {
        auto pennies  {static_cast<unsigned int>(money * 100 / penny)};
        auto nickels  {static_cast<unsigned int>(money * 100 / nickel)};
        auto dimes    {static_cast<unsigned int>(money * 100 / dime)};
        auto quarters {static_cast<unsigned int>(money * 100 / quarter)};

        std::cout << "Needed to make up that amount: " << std::endl;
        std::cout << pennies  << (pennies  == 1? " penny"   : " pennies")  << std::endl;
        std::cout << nickels  << (nickels  == 1? " nickel"  : " nickels")  << std::endl;
        std::cout << dimes    << (dimes    == 1? " dime"    : " dimes")    << std::endl;
        std::cout << quarters << (quarters == 1? " quarter" : " quarters") << std::endl;
    }
    else {
        std::cout << "An amount of money should be between $0 and $10." << std::endl;
        return 1;
    }
}