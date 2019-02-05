// Exercise 3-5.
// Write a program that defines an enumeration of type Color where the enumerators are Red, Green, Yellow, Purple, Blue,
// Black, and White. Define the type for enumerators as an unsigned integer type and arrange for the integer value of
// each enumerator to be the RGB combination for the color it represents (you can easily find the hexadecimal RGB
// encoding of any color online). Create variables of type Color initialized with enumerators for yellow, purple, and
// green. Access the enumerator value and extract and output the RGB components as separate values.
#include <iostream>

int main()
{
    enum class Color : unsigned int
    {
        Red    = 0xFF0000,
        Green  = 0x00FF00,
        Yellow = 0xFFFF00,
        Purple = 0x800080,
        Blue   = 0x0000FF,
        Black  = 0x000000,
        White  = 0xFFFFFF
    };

    const Color yellow {Color::Yellow};
    const Color purple {Color::Purple};
    const Color green  {Color::Green};

    std::cout << "Yellow is ";
    unsigned int R = (static_cast<unsigned int>(Color::Yellow) & static_cast<unsigned int>(Color::Red))   >> 16;
    unsigned int G = (static_cast<unsigned int>(Color::Yellow) & static_cast<unsigned int>(Color::Green)) >> 8;
    unsigned int B = (static_cast<unsigned int>(Color::Yellow) & static_cast<unsigned int>(Color::Blue));
    std::cout << "RGB(" << R << "," << G << "," << B << ")" << std::endl;

    std::cout << "Purple is ";
    R = (static_cast<unsigned int>(Color::Purple) & static_cast<unsigned int>(Color::Red))   >> 16;
    G = (static_cast<unsigned int>(Color::Purple) & static_cast<unsigned int>(Color::Green)) >> 8;
    B = (static_cast<unsigned int>(Color::Purple) & static_cast<unsigned int>(Color::Blue));
    std::cout << "RGB(" << R << "," << G << "," << B << ")" << std::endl;

    std::cout << "Green  is ";
    R = (static_cast<unsigned int>(Color::Green) & static_cast<unsigned int>(Color::Red))   >> 16;
    G = (static_cast<unsigned int>(Color::Green) & static_cast<unsigned int>(Color::Green)) >> 8;
    B = (static_cast<unsigned int>(Color::Green) & static_cast<unsigned int>(Color::Blue));
    std::cout << "RGB(" << R << "," << G << "," << B << ")" << std::endl;
}