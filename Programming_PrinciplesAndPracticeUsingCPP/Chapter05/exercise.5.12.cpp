// 12. Implement a little guessing game called (for some obscure reason) “Bulls and Cows.” The program has a vector of
// four different integers in the range 0 to 9 (e.g., 1234 but not 1122) and it is the user’s task to discover those
// numbers by repeated guesses. Say the number to be guessed is 1234 and the user guesses 1359; the response should be
// “1 bull and 1 cow” because the user got one digit (1) right and in the right position (a bull) and one digit (3)
// right but in the wrong position (a cow). The guessing continues until the user gets four bulls, that is, has the four
// digits correct and in the correct order.
#include "std_lib_facilities.h"
#include <random>

bool contains_duplicates(string s)
{
    sort(s.begin(), s.end());
    return adjacent_find(s.begin(), s.end()) != s.end();
}

void game()
{
    typedef string::size_type index;

    string symbols = "0123456789";
    unsigned int const selection_length = 4;

    mt19937 g{random_device{}()};
    shuffle(symbols.begin(), symbols.end(), g);
    string selection = symbols.substr(0, selection_length);
    string guess;
    while (cout << "Ваша догадка? ", getline(cin, guess))
    {
        if (guess.length() != selection_length
            || guess.find_first_not_of(symbols) != string::npos
            || contains_duplicates(guess))
        {
            cout << guess << " не является допустимой догадкой!";
            continue;
        }

        unsigned int bulls = 0;
        unsigned int cows = 0;
        for (index i = 0; i != selection_length; ++i)
        {
            index pos = selection.find(guess[i]);
            if (pos == i)
                ++bulls;
            else if (pos != string::npos)
                ++cows;
        }
        cout << bulls << " быки, " << cows << " коровы.\n";
        if (bulls == selection_length)
        {
            cout << "Поздравляю! Вы выиграли!\n";
            return;
        }
    }
    cerr << "Ошибка ввода или введён end-of-file!\nВыход.\n";
    exit(EXIT_FAILURE);
}

int main()
{
    cout << "Игра на угадывание «Быки и коровы».\nХотите сыграть? ";
    string answer;
    while (true)
    {
        while (true)
        {
            if (!getline(cin, answer))
            {
                cout << "Ответ не получен. Выход.\n";
                return EXIT_FAILURE;
            }
            if (answer == "да" || answer == "Да" || answer == "д" || answer == "Д" ||
                answer == "yes" || answer == "Yes" || answer == "y" || answer == "Y")
                break;
            if (answer == "нет" || answer == "Нет" || answer == "н" || answer == "Н" ||
                answer == "no" || answer == "No" || answer == "n" || answer == "N")
            {
                cout << "Программа завершена.\n";
                return EXIT_SUCCESS;
            }
            cout << "Ответьте «да» или «нет»: ";
        }
        game();
        cout << "Другая игра? ";
    }
}
