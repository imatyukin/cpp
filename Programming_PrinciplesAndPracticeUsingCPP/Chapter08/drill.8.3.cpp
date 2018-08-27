// 3. Write a program using a single file containing three namespaces X, Y, and Z so that the following main() works
// correctly:
// int main()
// {
//      X::var = 7;
//      X::print();             // print X’s var
//      using namespace Y;
//      var = 9;
//      print();                // print Y’s var
//      {    using Z::var;
//           using Z::print;
//           var = 11;
//           print();           // print Z’s var
//      }
//      print();                // print Y’s var
//      X::print();             // print X’s var
// }
// Each namespace needs to define a variable called var and a function called print() that outputs the appropriate var
// using cout.

#include "std_lib_facilities.h"

namespace X {
    int var {0};
    void print() { cout << "Значение переменной X::var = " << var << '\n'; }
} // Конец namespace X

namespace Y {
    int var {0};
    void print() { cout << "Значение переменной Y::var = " << var << '\n'; }
} // Конец namespace Y

namespace Z {
    int var {0};
    void print() { cout << "Значение переменной Z::var = " << var << '\n'; }
} // Конец namespace Z

int main()
{
    X::var = 7;
    X::print();             // Вывод var из пространства имен Х
    using namespace Y;
    var = 9;
    print();                // Вывод var из пространства имен Y
    {
        using Z::var;
        using Z::print;
        var = 11;
        print();            // Вывод var из пространства имен Z
    }
    print();                // Вывод var из пространства имен Y
    X::print();             // Вывод var из пространства имен Х
}