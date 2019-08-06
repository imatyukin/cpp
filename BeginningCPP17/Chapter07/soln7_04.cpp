// Exercise 7-4.
// Write a program that prompts for the input of two words and determines whether one is an anagram of the other. An
// anagram of a word is formed by rearranging its letters, using each of the original letters precisely once. For
// instance, listen and silent are anagrams of one another, but listens and silent are not.
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string str;
    string a, b;
    int a_sum {}, b_sum {}, i {};
    cout << "Enter two words: ";
    getline(cin, str);

    // Used to split string around spaces.
    istringstream ss(str);

    // Traverse through all words
    do {
        // Read a word
        string word;
        ss >> word;

        // Print the read word
        if (a == b) a = word;
        else {
            b = word;
            break;
        }

      // While there is more to read
    } while (ss);

    while (a[i] != '\0') {
        a_sum += (int)a[i];
        b_sum += (int)b[i];
        i++;
    }

    if (a_sum == b_sum)
        cout << "\"" << a << "\"" << " and " << "\"" << b << "\"" << " are anagrams of one another." << endl;
    else
        cout << "\"" << a << "\"" << " and " << "\"" << b << "\"" << " are not anagrams of one another." << endl;
}