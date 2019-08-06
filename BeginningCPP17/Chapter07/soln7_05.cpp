// Exercise 7-5.
// Generalize the program of Exercise 7-4 such that it ignores spaces when deciding whether two strings are anagrams.
// With this generalized definition, funeral and real fun are considered anagrams, as are eleven plus two and twelve
// plus one, along with desperation and a rope ends it.
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    int a_sum {}, b_sum {}, i {}, j {};
    cout << "Enter the first string: ";
    getline(cin, a);
    cout << "Enter the second string: ";
    getline(cin, b);

    while (a[i] != '\0') {
        if (a[i] != ' ') {
            a_sum += (int) a[i];
            i++;
        }
        else i++;
    }
    while (b[j] != '\0') {
        if (b[j] != ' ') {
            b_sum += (int) b[j];
            j++;
        }
        else j++;
    }

    if (a_sum == b_sum)
        cout << "\"" << a << "\"" << " and " << "\"" << b << "\"" << " are anagrams of one another." << endl;
    else
        cout << "\"" << a << "\"" << " and " << "\"" << b << "\"" << " are not anagrams of one another." << endl;
}