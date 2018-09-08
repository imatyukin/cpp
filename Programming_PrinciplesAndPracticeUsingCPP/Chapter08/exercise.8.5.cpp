// 5. Write two functions that reverse the order of elements in a vector<int>. For example, 1, 3, 5, 7, 9 becomes 9, 7,
// 5, 3, 1. The first reverse function should produce a new vector with the reversed sequence, leaving its original
// vector unchanged. The other reverse function should reverse the elements of its vector without using any other
// vectors (hint: swap).

#include "std_lib_facilities.h"

vector<int> create_reverse_vector(vector<int> v) {
    transform(v.begin(), v.begin() + v.size() / 2, v.rbegin(), v.begin(), [](int& x, int& y)
    {
        swap(x, y);
        return x;
    });

    return v;
}

void reverse_vector(vector<int>& v) {
    transform(v.begin(), v.begin() + v.size() / 2, v.rbegin(), v.begin(), [](int& x, int& y)
    {
        swap(x, y);
        return x;
    });
}

int main()
try
{
    vector<int> v, vR;
    for (int i=1; i<10; ++++i) v.push_back(i);      // ++++i - увеличение итератора на 2

    cout << "v содержит: ";
    for (auto i: v)
        cout << i << ' ';

    vR = create_reverse_vector(v);

    cout << "\nvR содержит: ";
    for (auto i = vR.begin(); i != vR.end(); ++i)
        cout << *i << ' ';

    reverse_vector(v);

    cout << "\nv содержит: ";
    for (int i=0; i<v.size(); ++i)
        cout << v[i] << ' ';
}
catch (runtime_error e) {
    cout << e.what() << '\n';
}
catch (...) {
    cout << "exiting\n";
}