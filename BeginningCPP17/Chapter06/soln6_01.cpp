// Exercise 6-1.
// Write a program that declares and initializes an array with the first 50 odd (as in not even) numbers. Output the
// numbers from the array ten to a line using pointer notation and then output them in reverse order, also using pointer
// notation.
#include <iostream>
#include <memory>
#include <iomanip>

using namespace std;

int main()
{
    const size_t nArrayLength {50};
    const size_t perline {10};

    // Allocate an Array with 50 int values initialized with 0.
    unique_ptr<int[]> upArray(new int[nArrayLength]);

    // Fill the array with the first 50 odd numbers and display.
    for (auto i = 0, j = 0; i < nArrayLength*2; ++i) {
        if (i % 2) {
            upArray[j] = i;
            j++;
        }
    }

    // Display the array using pointer notation.
    for (auto i = 0; i < nArrayLength; ++i) {
        cout << setw(5) << upArray[i];
        if ((i + 1) % perline == 0)
            cout << endl;
    }

    // Reversing the array using pointers.
    for (int i = 0, j = nArrayLength-1; i < j; ++i, --j) {
        int temp = upArray[i];
        upArray[i] = upArray[j];
        upArray[j] = temp;
    }

    // Display the array in reverse order using pointer notation.
    cout << endl;
    for (auto i = 0; i < nArrayLength; ++i) {
        cout << setw(5) << upArray[i];
        if ((i + 1) % perline == 0)
            cout << endl;
    }

    return 0;
}