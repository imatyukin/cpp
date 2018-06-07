// 12. Implement a little guessing game called (for some obscure reason) “Bulls and Cows.” The program has a vector of
// four different integers in the range 0 to 9 (e.g., 1234 but not 1122) and it is the user’s task to discover those
// numbers by repeated guesses. Say the number to be guessed is 1234 and the user guesses 1359; the response should be
// “1 bull and 1 cow” because the user got one digit (1) right and in the right position (a bull) and one digit (3)
// right but in the wrong position (a cow). The guessing continues until the user gets four bulls, that is, has the four
// digits correct and in the correct order.
#include "std_lib_facilities.h"

constexpr short int selection_length{ 4 };
constexpr short int upper_limit{ 10 };

void init_digits(vector<char>& digits);
void get_chars(vector<char>& chars);
void check_input(vector<char>& digits, vector<char>& chars, short int& bulls, short int& cows);

int main() {
    vector<char> digits(selection_length);
    vector<char> chars(selection_length);

    char answer;
    do {
        short int bulls{ 0 }, cows{ 0 };
        unsigned int tries{ 1 };

        init_digits(digits);

        while(true) {
            cout << "Попробуйте угадать 4 символа (0-9): ";

            try {
                get_chars(chars);
            } catch(runtime_error& e) {
                cerr << e.what() << endl;
                continue;
            }

            check_input(digits, chars, bulls, cows);

            if (bulls == 4) {
                cout << "Вы выиграли с " << tries << " попытки." << endl;
                break;
            }

            cout << bulls << " быки и " << cows << " коровы." << endl;
            tries++;
        }

        cout << endl << "Хотите сыграть снова [y/N]? ";
        cin >> answer;
    } while(tolower(answer) == 'y');

    return 0;
}

void init_digits(vector<char>& digits) {
    srand(unsigned(time(NULL)));

    vector<bool> checks(10, false);
    for (short int i{ 0 }; i < selection_length; i++) {
        short int d = (rand() % upper_limit);

        if (checks[d]) {
            i--;
            continue;   // Пропустить дублируемую цифру
        }

        digits[i] = '0' + d;
        checks[d] = true;
    }
}

void get_chars(vector<char>& chars) {
    vector<bool> checks(10, false);
    for (short int i{ 0 }; i < selection_length; i++) {
        char c;
        cin >> c;

        if (!isnumber(c)) {
            string s{c};
            s = "Ошибка: неверный символ \"" + s + "\".";
            throw runtime_error(s);
        }

        unsigned short d = c - '0';

        if (checks[d]) {
            string s{c};
            s = "Ошибка: цифра \"" + s + "\" дублируется.";
            throw runtime_error(s);
        }

        chars[i] = c;
        checks[d] = true;
    }
}

void check_input(vector<char>& digits, vector<char>& chars, short int& bulls, short int& cows) {
    bulls = cows = 0;   // Двойная проверка начального значения.

    for (short int i{ 0 }; i < selection_length; i++) {
        for (short int j{ 0 }; j < selection_length; j++) {
            if (digits[i] == chars[j]) {
                if (i == j) {
                    bulls++;
                    break;
                } else {
                    cows++;
                }
            }
        }
    }
}
