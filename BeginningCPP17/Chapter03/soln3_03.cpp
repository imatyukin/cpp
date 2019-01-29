// Exercise 3-3. Without running it, can you work out what the following code snippet will produce as output?
// auto k {430u};
// auto j {(k >> 4) & ∼(∼0u << 3)};
// std::cout << j << std::endl;
#include <iostream>
#include <bitset>

int main()
{
    auto k {430u};
    std::cout << " k          = 0b" << std::bitset<9>(k)           << std::endl;
    std::cout << " k >> 4     = 0b" << std::bitset<9>(k >> 4)      << std::endl;
    std::cout << " 0u         = 0b" << std::bitset<9>(0u)          << std::endl;
    std::cout << "~0u         = 0b" << std::bitset<9>(~0u)         << std::endl;
    std::cout << "~0u << 3    = 0b" << std::bitset<9>(~0u << 3)    << std::endl;
    std::cout << "~(~0u << 3) = 0b" << std::bitset<9>(~(~0u << 3)) << std::endl;
    std::cout << "(k >> 4) & ~(~0u << 3) = 0b" << std::bitset<9>((k >> 4) & ~(~0u << 3)) << std::endl;
    std::cout << "0b" << std::bitset<9>((k >> 4) & ~(~0u << 3)) << " = " << ((k >> 4) & ~(~0u << 3)) << std::endl;
    auto j {(k >> 4) & ~(~0u << 3)};
    std::cout << j << std::endl;
}