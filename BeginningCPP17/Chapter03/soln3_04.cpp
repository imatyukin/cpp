// Exercise 3-4.
// Write a program to read four characters from the keyboard and pack them into a single integer variable. Display the
// value of this variable as hexadecimal. Unpack the four bytes of the variable and output them in reverse order, with
// the low-order byte first.
#include <iostream>
#include <bitset>
#include <iomanip>

int main()
{
    char c0 {}, c1 {}, c2 {}, c3 {};
    int pack4chars {};

    std::cout << "Enter four characters from the keyboard: ";
    std::cin >> c0 >> c1 >> c2 >> c3;

    std::cout << c0 << " = " << std::bitset<8>(static_cast<unsigned long long int>(c0)) << std::endl;
    std::cout << c1 << " = " << std::bitset<8>(static_cast<unsigned long long int>(c1)) << std::endl;
    std::cout << c2 << " = " << std::bitset<8>(static_cast<unsigned long long int>(c2)) << std::endl;
    std::cout << c3 << " = " << std::bitset<8>(static_cast<unsigned long long int>(c3)) << std::endl;

    pack4chars = (c0 << 24) | (c1 << 16) | (c2 << 8) | c3;
    std::cout << "display the single integer variable as binary = "
              << std::bitset<32>(static_cast<unsigned long long int>(pack4chars)) << std::endl;
    std::cout << "display the single integer variable as hexadecimal = "
              << std::hex << std::showbase << std::internal << std::setfill('0') << pack4chars << std::endl;

    int unpack_c0 = pack4chars >> 24;
    int unpack_c1 = pack4chars >> 16;
    int unpack_c2 = pack4chars >> 8;
    int unpack_c3 = pack4chars;

    const unsigned int mask_swap_left_four_bits {0xF0};
    const unsigned int mask_swap_right_four_bits {0x0F};
    const unsigned int mask_swap_left_adj_pairs {0xCC};
    const unsigned int mask_swap_right_adj_pairs {0x33};
    const unsigned int mask_swap_left_adj_single_bits {0xAA};
    const unsigned int mask_swap_right_adj_single_bits {0x55};

    std::cout << std::dec << "output in reverse order, with the low-order byte first:" << std::endl;

    unpack_c3 = (unpack_c3 & mask_swap_left_four_bits) >> 4 | (unpack_c3 & mask_swap_right_four_bits) << 4;
    unpack_c3 = (unpack_c3 & mask_swap_left_adj_pairs) >> 2 | (unpack_c3 & mask_swap_right_adj_pairs) << 2;
    unpack_c3 = (unpack_c3 & mask_swap_left_adj_single_bits) >> 1 | (unpack_c3 & mask_swap_right_adj_single_bits) << 1;
    std::cout << c3 << " = " << std::bitset<8>(static_cast<unsigned long long int>(unpack_c3)) << std::endl;

    unpack_c2 = (unpack_c2 & mask_swap_left_four_bits) >> 4 | (unpack_c2 & mask_swap_right_four_bits) << 4;
    unpack_c2 = (unpack_c2 & mask_swap_left_adj_pairs) >> 2 | (unpack_c2 & mask_swap_right_adj_pairs) << 2;
    unpack_c2 = (unpack_c2 & mask_swap_left_adj_single_bits) >> 1 | (unpack_c2 & mask_swap_right_adj_single_bits) << 1;
    std::cout << c2 << " = " << std::bitset<8>(static_cast<unsigned long long int>(unpack_c2)) << std::endl;

    unpack_c1 = (unpack_c1 & mask_swap_left_four_bits) >> 4 | (unpack_c1 & mask_swap_right_four_bits) << 4;
    unpack_c1 = (unpack_c1 & mask_swap_left_adj_pairs) >> 2 | (unpack_c1 & mask_swap_right_adj_pairs) << 2;
    unpack_c1 = (unpack_c1 & mask_swap_left_adj_single_bits) >> 1 | (unpack_c1 & mask_swap_right_adj_single_bits) << 1;
    std::cout << c1 << " = " << std::bitset<8>(static_cast<unsigned long long int>(unpack_c1)) << std::endl;

    unpack_c0 = (unpack_c0 & mask_swap_left_four_bits) >> 4 | (unpack_c0 & mask_swap_right_four_bits) << 4;
    unpack_c0 = (unpack_c0 & mask_swap_left_adj_pairs) >> 2 | (unpack_c0 & mask_swap_right_adj_pairs) << 2;
    unpack_c0 = (unpack_c0 & mask_swap_left_adj_single_bits) >> 1 | (unpack_c0 & mask_swap_right_adj_single_bits) << 1;
    std::cout << c0 << " = " << std::bitset<8>(static_cast<unsigned long long int>(unpack_c0)) << std::endl;
}