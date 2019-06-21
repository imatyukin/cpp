// Exercise 6-3.
// Write a program that reads an array size from the keyboard and dynamically allocates an array of that size to hold
// floating-point values. Using pointer notation, initialize all the elements of the array so that the value of the
// element at index position n is 1 / (n + 1)^2. Calculate the sum of the elements using array notation, multiply the
// sum by 6, and output the square root of that result.
#include <iostream>
#include <memory>
#include <cmath>

using namespace std;

int main()
{
    size_t userSize {};
    double sum {};
    cout << "Enter array size: ";
    cin >> userSize;
    unique_ptr<double[]> arr(new double[userSize]);

    for (size_t i {}; i < userSize; ++i) {
        arr[i] = 1.0 / pow(i + 1, 2);
        sum += arr[i];
    }

    cout << "The result is " << sqrt(sum * 6.0) << endl;

    return 0;
}