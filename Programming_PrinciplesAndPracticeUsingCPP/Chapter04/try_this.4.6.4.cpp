// Write a program that “bleeps” out words that you don’t like; that is, you read in words using cin and print them
// again on cout. If a word is among a few you have defined, you write out BLEEP instead of that word. Start with one
// “disliked word” such as
//      string disliked = “Broccoli”;
// When that works, add a few more.
#include "std_lib_facilities.h"

bool disliked(string);

int main() {
    for (string temp; cin >> temp;) {   // Чтение слов, разделенных пробельными символами
        if (disliked(temp) == true)
            cout << "BLEEP" << '\n';
        else
            cout << temp << '\n';
    }
}

bool disliked(string temp)
{
    vector<string> disliked = {"Broccoli", "Mushrooms", "Cactus"};  // Вектор из трёх строк

    for (int i = 0; i < disliked.size(); ++i) {
        if (temp == disliked[i])
            return true;
    }
    return false;
}
