// Exercise 4-7.
// Implement a program that prompts for input of a letter. Use a library function to determine whether the letter is a
// vowel and whether it is lowercase or not, and output the result. Finally, output the lowercase letter together with
// its character code as a binary value.
// Hint: Even though starting with C++14, C++ supports binary integral literals (of form 0b11001010; see Chapter 2), C++
// standard output functions and streams do not support outputting integral values in binary format. They mostly do
// support hexadecimal and octal formatting—for std::cout, for instance, you can use the std::hex and std::oct output
// manipulators defined in <ios>. But to output a character in binary format, you’ll thus have to write some code
// yourself. It shouldn’t be too hard, though: a char normally has only eight bits, remember? You can just stream these
// bits one by one. Perhaps these binary integer literals can be helpful as well—why else would we have mentioned them
// at the start of this hint?
#include <iostream>

int main() {
    char ch {};
    bool vowel {};
    bool lowercase {};

    std::cout << "Enter a letter: ";
    std::cin >> ch;

    if (isalpha(ch)) {
        if (islower(ch)) lowercase = true;

        switch(tolower(ch)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowel = true;
                break;
            default:
                break;
        }

        std::cout << "The letter " << "'" << ch << "'" << " is a "
                  << (vowel? "vowel" : "consonant")
                  << " and it is "
                  << (lowercase? "lowercase." : "uppercase.")
                  << std::endl;

        if (lowercase) {
            std::cout << "The binary value "
                      << "'" << ch << "'" << " is "
                      << ((ch & 0b10000000)? 1 : 0)
                      << ((ch & 0b01000000)? 1 : 0)
                      << ((ch & 0b00100000)? 1 : 0)
                      << ((ch & 0b00010000)? 1 : 0)
                      << ((ch & 0b00001000)? 1 : 0)
                      << ((ch & 0b00000100)? 1 : 0)
                      << ((ch & 0b00000010)? 1 : 0)
                      << ((ch & 0b00000001)? 1 : 0)
                      << "." << std::endl;
        }
    }
    else {
        std::cout << "Character " << "'" << ch << "'" << " is not alphabetic." << std::endl;
        return 1;
    }
}