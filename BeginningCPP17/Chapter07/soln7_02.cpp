// Exercise 7-2.
// Write a program that reads text entered over an arbitrary number of lines. Find and record each unique word that
// appears in the text and record the number of occurrences of each word. Output the words and their occurrence counts.
// Words and counts should align in columns. The words should align to the left; the counts to the right. There should
// be three words per row in your table.
#include <iostream>
#include <unordered_map>
#include <iomanip>

int main() {
    std::unordered_map<std::string, unsigned> dict;
    for (std::string word; std::cin >> word;) {
        ++dict[word];
    }

    size_t max_length {};
    for (const auto &d : dict) {
        if (max_length < d.first.length()) max_length = d.first.length();
    }
    std::cout << "Number of distinct words are: " << dict.size() << "\n";

    size_t count {};
    const size_t perline {3};

    for (const auto &d : dict) {
        std::cout << std::setw(max_length) << std::left << d.first
                  << std::setw(4) << std::right << d.second << "  ";
        if (!(++count % perline))
            std::cout << std::endl;
    }

    std::cout << std::endl;
}