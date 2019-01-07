// Invalid Floating-Point Results
#include <iostream>

int main()
{
    double a{ 1.5 }, b{}, c{};
    double result { a / b };
    std::cout << a << "/" << b << " = " << result << std::endl;
    std::cout << result << " + " << a << " = " << result + a << std::endl;
    result = b / c;
    std::cout << b << "/" << c << " = " << result << std::endl;
}