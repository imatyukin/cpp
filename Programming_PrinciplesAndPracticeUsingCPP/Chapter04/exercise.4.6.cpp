// 6. Make a vector holding the ten string values "zero", "one", . . . "nine". Use that in a program that converts a
// digit to its corresponding spelled-out value; e.g., the input 7 gives the output seven. Have the same program, using
// the same input loop, convert spelled-out numbers into their digit form; e.g., the input seven gives the output 7.
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
    string digit;

    cout << "Введите цифру или строковое представление цифры: " << endl;
    while (cin >> digit) {
        for (int i = 0; i < digits.size(); ++i) {
            std::string s = std::to_string(i);
            if (digit == s)
                cout << digits[i] << endl;
            else if (digit == digits[i])
                cout << i << endl;
        }
    }
}
