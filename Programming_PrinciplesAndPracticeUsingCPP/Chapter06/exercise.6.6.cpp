// 6. Write a program that checks if a sentence is correct according to the “English” grammar in §6.4.1. Assume that
// every sentence is terminated by a full stop (.) surrounded by whitespace. For example, birds fly but the fish swim .
// is a sentence, but birds fly but the fish swim (terminating dot missing) and birds fly but the fish swim. (no space
// before dot) are not. For each sentence entered, the program should simply respond “OK” or “not OK.” Hint: Don’t
// bother with tokens; just read into a string using >>.
#include "std_lib_facilities.h"

int main()
{
    string str;
    cout << "Проверка корректности предложений на соответствие правил \"английской грамматики\"." << endl;

    while (1) {
        cout << "Введите предложение или 'q' для выхода: " << endl;
        getline(cin, str);

        for (int i = 0; i < str.size()+1; ++i) {
            if (str[0] == 'q')
                exit(0);
            if (str[i] == '\0') {
                if (str[i - 1] == ' ' && str[i - 2] == '.' && str[i - 3] == ' ')
                    cout << "Да" << endl;
                else
                    cout << "Нет" << endl;
            }
        }
        cout << endl;
    }
}
