// Rewrite the character value example from the previous Try this to use a for-statement. Then modify your program to
// also write out a table of the integer values for uppercase letters and digits.
#include "std_lib_facilities.h"

int main()
{
    char c;

    for (int i = 48; i < 58; i++) {
        cout << (c = i) << "\t" << i << "\n";
    }

    for (int i = 65; i < 91; i++) {
        cout << (c = i) << "\t" << i << "\n";
    }

    for (int i = 97; i < 123; i++) {
        cout << (c = i) << "\t" << i << "\n";
    }
}
