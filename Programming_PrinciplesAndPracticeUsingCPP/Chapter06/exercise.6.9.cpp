// 9. Write a program that reads digits and composes them into integers. For example, 123 is read as the characters 1,
// 2, and 3. The program should output 123 is 1 hundred and 2 tens and 3 ones. The number should be output as an int
// value. Handle numbers with one, two, three, or four digits. Hint: To get the integer value 5 from the character '5'
// subtract '0', that is, '5'–'0'==5.
#include "std_lib_facilities.h"
#include <string>

int check_size(string str);
int parse_digit(char digit);

int main() {
    string digits = "";
    int ones, tens, hundreds, thousands = 0;
    cout << "Enter one, two, three or four digits:" << endl;
    getline(cin, digits);
    int size = check_size(digits);

    switch(size)
    {
        case 1:
            ones = parse_digit(digits[0]);
            if (ones == 1)
                cout << digits << " is " << ones << " one." << endl;
            else
                cout << digits << " is " << ones << " ones." << endl;
            break;
        case 2:
            ones = parse_digit(digits[1]);
            tens = parse_digit(digits[0]);
            if (tens == 1 && ones == 1)
                cout << digits << " is " << tens << " ten and " << ones << " one." << endl;
            else if (ones == 1)
                cout << digits << " is " << tens << " tens and " << ones << " one." << endl;
            else if (tens == 1)
                cout << digits << " is " << tens << " ten and " << ones << " ones." << endl;
            else
                cout << digits << " is " << tens << " tens and " << ones << " ones." << endl;
            break;
        case 3:
            ones = parse_digit(digits[2]);
            tens = parse_digit(digits[1]);
            hundreds = parse_digit(digits[0]);
            if (hundreds == 1 && tens == 1 && ones == 1)
                cout << digits << " is " << hundreds << " hundred and " << tens << " ten and " << ones << " one."
                     << endl;
            else if (tens == 1 && ones == 1)
                cout << digits << " is " << hundreds << " hundreds and " << tens << " ten and " << ones << " one."
                     << endl;
            else if (hundreds == 1 && ones == 1)
                cout << digits << " is " << hundreds << " hundred and " << tens << " tens and " << ones << " one."
                     << endl;
            else if (hundreds == 1 && tens == 1)
                cout << digits << " is " << hundreds << " hundred and " << tens << " ten and " << ones << " ones."
                     << endl;
            else if (ones == 1)
                cout << digits << " is " << hundreds << " hundreds and " << tens << " tens and " << ones << " one."
                     << endl;
            else if (tens == 1)
                cout << digits << " is " << hundreds << " hundreds and " << tens << " ten and " << ones << " ones."
                     << endl;
            else if (hundreds == 1)
                cout << digits << " is " << hundreds << " hundred and " << tens << " tens and " << ones << " ones."
                     << endl;
            else
                cout << digits << " is " << hundreds << " hundreds and " << tens << " tens and " << ones << " ones."
                     << endl;
            break;
        case 4:
            ones = parse_digit(digits[3]);
            tens = parse_digit(digits[2]);
            hundreds = parse_digit(digits[1]);
            thousands = parse_digit(digits[0]);
            if (thousands == 1 && hundreds == 1 && tens == 1 && ones == 1)
                cout << digits << " is " << thousands << " thousand and " << hundreds << " hundred and "
                     << tens << " ten and " << ones << " one." << endl;
            else if (thousands == 1 && hundreds == 1 && tens == 1)
                cout << digits << " is " << thousands << " thousand and " << hundreds << " hundred and "
                     << tens << " ten and " << ones << " ones." << endl;
            else if (thousands == 1 && hundreds == 1 && ones == 1)
                cout << digits << " is " << thousands << " thousand and " << hundreds << " hundred and "
                     << tens << " tens and " << ones << " one." << endl;
            else if (thousands == 1 && tens == 1 && ones == 1)
                cout << digits << " is " << thousands << " thousand and " << hundreds << " hundreds and "
                     << tens << " ten and " << ones << " one." << endl;
            else if (hundreds == 1 && tens == 1 && ones == 1)
                cout << digits << " is " << thousands << " thousands and " << hundreds << " hundred and "
                     << tens << " ten and " << ones << " one." << endl;
            else if (hundreds == 1 && tens == 1)
                cout << digits << " is " << thousands << " thousands and " << hundreds << " hundred and "
                     << tens << " ten and " << ones << " ones." << endl;
            else if (hundreds == 1 && ones == 1)
                cout << digits << " is " << thousands << " thousands and " << hundreds << " hundred and "
                     << tens << " tens and " << ones << " one." << endl;
            else if (tens == 1 && ones == 1)
                cout << digits << " is " << thousands << " thousands and " << hundreds << " hundreds and "
                     << tens << " ten and " << ones << " one." << endl;
            else if (thousands == 1)
                cout << digits << " is " << thousands << " thousand and " << hundreds << " hundreds and "
                     << tens << " tens and " << ones << " ones." << endl;
            else if (hundreds == 1)
                cout << digits << " is " << thousands << " thousands and " << hundreds << " hundred and "
                     << tens << " tens and " << ones << " ones." << endl;
            else if (tens == 1)
                cout << digits << " is " << thousands << " thousands and " << hundreds << " hundreds and "
                     << tens << " ten and " << ones << " ones." << endl;
            else if (ones == 1)
                cout << digits << " is " << thousands << " thousands and " << hundreds << " hundreds and "
                     << tens << " tens and " << ones << " one." << endl;
            else
                cout << digits << " is " << thousands << " thousands and " << hundreds << " hundreds and "
                     << tens << " tens and " << ones << " ones." << endl;
            break;
        default:
            cout << "You didn't enter any digits." << endl;
    }

    return 0;
}

int check_size(string str) {
    if (str.size() > 4) {
        error("ERROR: The number must consist of one, two, three or four digits.");
        exit(0);
    }
    else if (str.size() > 0)
        return str.size();
    else
        return 0;
}

int parse_digit(char digit) {
    return digit - '0';
}
