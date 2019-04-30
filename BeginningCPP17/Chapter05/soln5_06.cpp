// Exercise 5-6.
// Create a vector<> container with elements containing the integers from 1 to an arbitrary upper bound entered by the
// user. Output the elements from the vector that contain values that are not multiples of 7 or 13. Output them 10 on a
// line, aligned in columns.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned int> v;
    unsigned int bound{};
    size_t count{};

    cout << "Enter arbitrary upper bound: ";
    cin >> bound;
    for (unsigned int i = 1; i <= bound; i++)
        v.push_back(i);

    for (auto i : v) {
        if ((i % 7) != 0 && (i % 13) != 0) {
            cout << i << '\t';
            count++;
        }
        if (count == 10) {
            cout << '\n';
            count = 0;
        }
    }
}