// 8. Redo the “Bulls and Cows” game from exercise 12 in Chapter 5 to use four letters rather than four digits.
#include "std_lib_facilities.h"
#include <random>

constexpr short int selection_length{ 4 };

typedef vector<char> char_array;

char_array charset()
{
    return char_array(
            {'a','b','c','d','e','f',
             'g','h','i','j','k',
             'l','m','n','o','p',
             'q','r','s','t','u',
             'v','w','x','y','z'
            });
};

void init_digits(vector<char>& digits);
string random_string( size_t length, std::function<char(void)> rand_char );
bool check_duplicate(string str);
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
            cout << "Попробуйте угадать 4 буквы (a-z): ";

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

// given a function that generates a random character,
// return a string of the requested length
string random_string(size_t length, function<char(void)> rand_char)
{
    string str(length,0);
    generate_n(str.begin(), length, rand_char);
    return str;
}

bool check_duplicate(string str) {
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = i+1; str[j] != '\0'; j++) {
            if (str[i] == str[j])
                return false;
        }
    }
    return true;
}

void init_digits(vector<char>& digits) {
    // create the character set.
    const auto ch_set = charset();

    // create a non-deterministic random number generator
    default_random_engine rng(random_device{}());

    // create a random number "shaper" that will give uniformly distributed indices into the character set
    uniform_int_distribution<> dist(0, ch_set.size()-1);

    // create a function that ties them together, to get:
    // a non-deterministic uniform distribution from the character set of your choice.
    auto randchar = [ ch_set,&dist,&rng ](){return ch_set[ dist(rng) ];};

    // set the length of the string
    auto length = 4;

    string str = random_string(length,randchar);

    while (check_duplicate(str) == false) {
        str = random_string(length,randchar);
        check_duplicate(str);
    }

    for (int i = 0; i < str.size(); ++i) {
         digits[i] = str[i];
    }
}

void get_chars(vector<char>& chars) {
    vector<bool> checks(127, false);
    for (short int i{ 0 }; i < selection_length; i++) {
        char c;
        cin >> c;

        if (!isalpha(c)) {
            string s{c};
            s = "Ошибка: неверный символ \"" + s + "\".";
            throw runtime_error(s);
        }

        unsigned short d = c;

        if (checks[d]) {
            string s{c};
            s = "Ошибка: буква \"" + s + "\" дублируется.";
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
