// 4. Write a program to play a numbers guessing game. The user thinks of a number between 1 and 100 and your program
// asks questions to figure out what the number is (e.g., “Is the number you are thinking of less than 50?”). Your
// program should be able to identify the number after asking no more than seven questions. Hint: Use the < and <=
// operators and the if-else construct.
#include "std_lib_facilities.h"

int main() {
    int current;        // если =, то current = (left+right)/2
    int left = 1;       // если >, то left = (left+right)/2 + 1
    int right = 100;    // если <, то right = (left + right)/2 - 1
    char answer;
    bool True;

    cout << "Задумайте число от 1 до 100." << endl;

    // Угадывает за log2(n) вопросов (при n=100 за 7 вопросов)
    while (!True) {
        current = (left+right) / 2;
        cout << "Задуманное число " << current << "? " << "('=', '<', '>')" << endl;
        cin >> answer;
        if (answer == '=') {
            cout << "Число " << current << " идентифицированно." << endl;
            break;
        }
        else if (answer == '>')
            left = current + 1;
        else
            right = current - 1;
    }

    return 0;
}
