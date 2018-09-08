// 6. Write versions of the functions from exercise 5, but with a vector<string>.

#include "std_lib_facilities.h"

vector<string> create_reverse_vector(vector<string> v) {
    transform(v.begin(), v.begin() + v.size() / 2, v.rbegin(), v.begin(), [](string& x, string& y)
    {
        swap(x, y);
        return x;
    });

    return v;
}

void reverse_vector(vector<string>& v) {
    transform(v.begin(), v.begin() + v.size() / 2, v.rbegin(), v.begin(), [](string& x, string& y)
    {
        swap(x, y);
        return x;
    });
}

int main()
try
{
    vector<string> v, vR;
    v.push_back("one");
    v.push_back("three");
    v.push_back("five");
    v.push_back("seven");
    v.push_back("nine");

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