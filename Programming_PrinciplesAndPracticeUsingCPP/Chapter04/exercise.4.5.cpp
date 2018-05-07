// 5. Write a program that performs as a very simple calculator. Your calculator should be able to handle the four
// basic math operations — add, subtract, multiply, and divide — on two input values. Your program should prompt the
// user to enter three arguments: two double values and a character to represent an operation. If the entry arguments
// are 35.6, 24.1, and '+', the program output should be The sum of 35.6 and 24.1 is 59.7. In Chapter 6 we look at a
// much more sophisticated simple calculator.
#include "std_lib_facilities.h"

int main() {
    double var1, var2 = 0;
    char operation;

    cout << "Введите три аргумента: два значения и символ операции '+', '-', '*', '/'" << endl;
    cin >> var1 >> var2 >> operation;

    switch (operation) {
        case '+':
            cout << "Сумма " << var1 << " и " << var2 << " равна " << var1+var2 << endl;
            break;
        case '-':
            cout << "Разность " << var1 << " и " << var2 << " равна " << var1-var2 << endl;
            break;
        case '*':
            cout << "Произведение " << var1 << " и " << var2 << " равно " << var1*var2 << endl;
            break;
        case '/':
            cout << "Частное " << var1 << " и " << var2 << " равно " << var1/var2 << endl;
            break;
        default:
            cout << "Вы ввели неизвестный символ операции '"
                 << operation << "'" << endl;
            break;
    }
}
