// The character 'b' is char('a'+1), 'c' is char('a'+2), etc. Use a loop to write out a table of characters with their
// corresponding integer values:
// a     97
// b     98
// . . .
// z     122
#include "std_lib_facilities.h"

int main()
{
    int i = 97;
    char c;

    while (i < 123) {
        c = i;
        cout << c << " \t " << i << "\n";
        ++i;
    }
}
