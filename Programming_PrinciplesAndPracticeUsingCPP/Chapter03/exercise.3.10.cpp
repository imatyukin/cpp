// 10. Write a program that takes an operation followed by two operands and outputs the result. For example:
// + 100 3.14
// * 4 5
// Read the operation into a string called operation and use an if-statement to figure out which operation the user
// wants, for example, if (operation=="+"). Read the operands into variables of type double. Implement this for
// operations called +, –, *, /, plus, minus, mul, and div with their obvious meanings.
#include "std_lib_facilities.h"

int main()
{
    string operation;
    double a, b = 0;

    cout << "Введите символ операции и два операнда:\n";
    cin >> operation >> a >> b;

    if (operation == "+" || operation == "plus")
        cout << a + b << "\n";
    else if (operation == "-" || operation == "minus")
        cout << a - b << "\n";
    else if (operation == "*" || operation == "mul")
        cout << a * b << "\n";
    else if (operation == "/" || operation == "div")
        cout << a / b << "\n";
}
