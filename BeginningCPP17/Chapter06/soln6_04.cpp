// Exercise 6-4.
// Repeat the calculation in Exercise 6-3 but using a vector<> container allocated in the free store. Test the program
// with more than 100,000 elements. Do you notice anything interesting about the result?
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

    vector<unique_ptr<double>> vec;
    for(int i = 0; i < userSize; ++i) {
        vec.push_back(make_unique<double>(1.0 / pow(i + 1, 2)));
    }

    double sum {};
    for(const auto& item : vec)
        sum += *item;

    cout << "The result is " << setprecision(15) << sqrt(sum * 6.0) << endl;

    return 0;
}