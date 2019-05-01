// Exercise 5-7.
// Write a program that will read and store an arbitrary sequence of records relating to products. Each record includes
// three items of data—an integer product number, a quantity, and a unit price. For product number 1001, the quantity is
// 25, and the unit price is $9.95. Because you do not know yet how to create compound types, simply use three different
// array-like sequences to represent these records. The program should output each product on a separate line and
// include the total cost. The last line should output the total cost for all products. Columns should align, so the
// output should be something like this:
// Product  Quantity    Unit Price  Cost
// 1001     25          $9.95       $248.75
// 1003     10          $15.50      $155.00
//                                  $403.75
#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    std::string product {};
    unsigned int qty {};
    double unit_price {};
    std::vector<std::string> products;
    std::vector<unsigned int> quantity;
    std::vector<double> unit_prices;
    bool valid = false;
    double total_cost {};

    do {
        std::cout << "Enter the product number, quantity and unit price or 'q' to quit: " << std::flush;
        std::cin >> product;
        if (product == "q") {
            valid = true;
            break;
        }
        std::cin >> qty >> unit_price;
        if (std::cin.good()) {
            products.push_back(product);
            quantity.push_back(qty);
            unit_prices.push_back(unit_price);
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "\nERROR: Invalid input; please re-enter.\n" << std::endl;
        }

    } while (!valid);

    std::cout << std::endl
              << std::setw(10) << "Product"
              << std::setw(10) << "Quantity"
              << std::setw(12) << "Unit Price"
              << std::setw(8)  << "Cost" << std::endl;
    for (size_t pn=0, qt=0, up=0; pn < products.size() && qt < quantity.size() && up < unit_prices.size();
        pn++, qt++, up++) {
        auto cost = quantity[qt] * unit_prices[up];
        total_cost += cost;
        std::cout << std::setw(8) << products[pn]
                  << std::setw(8) << quantity[qt]
                  << std::setw(9) << "$" << std::fixed << std::setprecision(2) << std::setw(5) << unit_prices[up]
                  << std::setw(7) << "$" << cost << std::endl;
    }
    std::cout << std::setw(37) << "$" << std::fixed << std::setprecision(2) << std::setw(5) << total_cost << std::endl;

    std::cout << "\nThe program closed." << std::endl;
}