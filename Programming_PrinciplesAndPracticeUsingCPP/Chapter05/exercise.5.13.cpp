// 13. The program is a bit tedious because the answer is hard-coded into the program. Make a version where the user can
// play repeatedly (without stopping and restarting the program) and each game has a new set of four digits. You can get
// four random digits by calling the random number generator randint(10) from std_lib_facilities.h four times. You will
// note that if you run that program repeatedly, it will pick the same sequence of four digits each time you start the
// program. To avoid that, ask the user to enter a number (any number) and call srand(n) where n is the number the user
// entered before calling randint(10). Such an n is called a seed, and different seeds give different sequences of
// random numbers.
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
