// Exercise 6-5.
// Revisit Exercise 6-3, but this time use a smart pointer to store the array, that is, if you haven’t already done so
// from the start. A good student should’ve known not to use the low-level memory allocation primitives….
#include <iostream>
#include <memory>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    size_t userSize {};
    double sum {};
    cout << "Enter array size: ";
    cin >> userSize;
    auto values{make_unique<double[]>(userSize)};

    for (size_t i {}; i < userSize; ++i) {
        values[i] = 1.0 / pow(i + 1, 2);
        sum += values[i];
    }

    cout << "The result is " << setprecision(15) << sqrt(sum * 6.0) << endl;

    return 0;
}