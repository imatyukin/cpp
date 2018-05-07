// 7. Modify the “mini calculator” from exercise 5 to accept (just) single-digit numbers written as either digits or
// spelled out.
#include "std_lib_facilities.h"
#include <string>

int main() {
    vector<string> digits(10);
    digits[0] = "zero";
    digits[1] = "one";
    digits[2] = "two";
    digits[3] = "three";
    digits[4] = "four";
    digits[5] = "five";
    digits[6] = "six";
    digits[7] = "seven";
    digits[8] = "eight";
    digits[9] = "nine";
    int var1, var2;
    string var3, var4;
    char operation;

    cout << "Введите два цифровых значения (или их строковое представление) и символ операции '+', '-', '*', '/'"
         << endl;

    while (cin >> var3 >> var4 >> operation) {
        for (int i = 0; i < digits.size(); ++i) {
            std::string s = std::to_string(i);
            if (var3 == digits[i])
                var1 = i;
            if (var3 == s)
                var1 = std::stoi(var3);
            if (var4 == digits[i])
                var2 = i;
            if (var4 == s)
                var2 = std::stoi(var4);
        }
        switch (operation) {
            case '+':
                cout << "Сумма " << var1 << " и " << var2 << " равна " << var1 + var2 << endl;
                break;
            case '-':
                cout << "Разность " << var1 << " и " << var2 << " равна " << var1 - var2 << endl;
                break;
            case '*':
                cout << "Произведение " << var1 << " и " << var2 << " равно " << var1 * var2 << endl;
                break;
            case '/':
                cout << "Частное " << var1 << " и " << var2 << " равно " << var1 / var2 << endl;
                break;
            default:
                cout << "Вы ввели неизвестный символ операции '"
                     << operation << "'" << endl;
                break;
        }
    }
}
