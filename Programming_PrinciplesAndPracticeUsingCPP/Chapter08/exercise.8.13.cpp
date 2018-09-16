// 13. Can we declare a non-reference function argument const (e.g., void f(const int);)? What might that mean? Why
// might we want to do that? Why don’t people do that often? Try it; write a couple of small programs to see what works.

#include "std_lib_facilities.h"

using namespace std;

void f(const int n)
{
//  ++n;                // нельзя модифицировать const аргумент
    cout << n << endl;
}

int main()
try
{
    int n = 1;
    f(n);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}