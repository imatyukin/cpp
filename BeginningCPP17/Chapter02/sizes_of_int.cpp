// The sizes of the fundamental integer types
#include <iostream>

using namespace std;                // Make all names in std available without qualification

int main()
{
    // signed char
    cout << "Type \"signed char\" occupies "            << sizeof(signed char)            << " bytes." << endl;
    // short, short int, signed short, signed short int
    cout << "Type \"short int\" occupies "              << sizeof(short int)              << " bytes." << endl;
    // int, signed, signed int
    cout << "Type \"int\" occupies "                    << sizeof(int)                    << " bytes." << endl;
    // long, long int, signed long, signed long int
    cout << "Type \"long int\" occupies "               << sizeof(long int)               << " bytes." << endl;
    // long long, long long int, signed long long, singed long long int
    cout << "Type \"long long int\" occupies "          << sizeof(long long int)          << " bytes." << endl;
    // unsigned char
    cout << "Type \"unsigned char\" occupies "          << sizeof(unsigned char)          << " bytes." << endl;
    // unsigned short, unsigned short int
    cout << "Type \"unsigned short int\" occupies "     << sizeof(unsigned short int)     << " bytes." << endl;
    // unsigned, unsigned int
    cout << "Type \"unsigned int\" occupies "           << sizeof(unsigned int)           << " bytes." << endl;
    // unsigned long, unsigned long int
    cout << "Type \"unsigned long int\" occupies "      << sizeof(unsigned long int)      << " bytes." << endl;
    // unsigned long long, unsigned long long int
    cout << "Type \"unsigned long long int\" occupies " << sizeof(unsigned long long int) << " bytes." << endl;
    // char
    cout << "Type \"char\" occupies "                   << sizeof(char)                   << " bytes." << endl;
    // size_t is an unsigned integer type that is defined in the Standard Library header cstddef.
    cout << "Type \"std::size_t\" occupies "            << sizeof(size_t)                 << " bytes." << endl;
}