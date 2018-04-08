// 5. Modify the program above to ask the user to enter floating-point values and store them in double variables.
// Compare the outputs of the two programs for some inputs of your choice. Are the results the same? Should they be?
// What’s the difference?
#include "std_lib_facilities.h"

int main()
{
    double val1, val2 = 0;

    cout << "Введите два числа с плавающей точкой (val1 и val2):\n";
    cin >> val1 >> val2;

    cout << "val1 = " << val1 << ", " << "val2 = " << val2 << ".\n";

    if (val1 == val2) cout << "Значения val1 и val2 равны.\n";
    if (val1 > val2) cout << "Наибольшее значение val1 = " << val1 << ".\n";
    else cout << "Наибольшее значение val2 = " << val2 << ".\n";

    cout << "Сумма val1 и val2 = " << val1 + val2 << ".\n";
    cout << "Разность val1 и val2 = " << val1 - val2 << ".\n";
    cout << "Произведение val1 и val2 = " << val1 * val2 << ".\n";
    cout << "Частное val1 и val2 = " << val1 / val2 << ".\n";
}
