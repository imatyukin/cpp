// Exercise 6-2.
// Revisit the previous exercise, but instead of accessing the array values using the loop counter, this time you should
// employ pointer increments (using the ++ operator) to traverse the array when outputting it for the first time. After
// that, use pointer decrements (using --) to traverse the array again in the reverse direction.
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const size_t arrayLength {50};
    int arr[arrayLength];

    // Populate the array.
    for (size_t i {}, j {}; i < arrayLength*2; ++i) {
        if (i % 2) {
            arr[j] = i;
            j++;
        }
    }

    const size_t perline {10};
    // Declare pointer variable.
    int* ptr;
    // Assign the address of arr[0] to ptr.
    ptr = arr;

    // Display the array employ pointer increments.
    for (size_t i {}; i < arrayLength; ++i) {
        cout << setw(5) << *ptr++;
        if ((i + 1) % perline == 0)
            cout << endl;
    }

    // Display the array in reverse order use pointer decrements.
    cout << endl;
    for (size_t i {}; i < arrayLength; ++i) {
        cout << setw(5) << *(--ptr);
        if ((i + 1) % perline == 0)
            cout << endl;
    }

    return 0;
}