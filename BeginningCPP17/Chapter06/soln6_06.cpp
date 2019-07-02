// Exercise 6-6.
// Revisit Exercise 6-4 and replace any raw pointers with smart pointers there as well.
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    size_t userSize {};
    cout << "Enter vector size: ";
    cin >> userSize;
    auto values = make_unique<vector<double>>(userSize);

    for (size_t i {}; i < userSize; ++i)
        (*values)[i] = 1.0 / pow(i + 1, 2);

    double sum {};
    for (auto value : *values)
        sum += value;

    cout << "The result is " << setprecision(15) << sqrt(sum * 6.0) << endl;

    return 0;
}