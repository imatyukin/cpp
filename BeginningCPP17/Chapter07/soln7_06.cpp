// Exercise 7-6.
// Write a program that reads a text string of arbitrary length from the keyboard followed by a string containing one or
// more letters. Output a list of all the whole words in the text that begin with any of the letters, uppercase or
// lowercase.
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<std::string> words;
std::vector<std::string> list;

int main(int argc, char** argv) {
    std::cout << "Enter a text string of arbitrary length terminated by 'quit': " << std::endl;
    words = std::vector<std::string>(argv, argv + argc);
    char quit[] = "quit";
    std::string line;

    while(std::getline(std::cin, line) && line != quit) {
        // Removes punctuation from a string.
        line.erase (std::remove_if (line.begin (), line.end (), ispunct), line.end ());
        std::stringstream ss(line);
        std::string word;
        while (ss >> word)
            words.push_back(word);
    }

    std::string letters;
    std::cout << "\nEnter a string containing one or more the starting letters for the words you want to find: "
              << std::endl;
    std::cin >> letters;

    for (auto ch : letters) {
        for (auto word : words) {
            if (std::toupper(word[0]) == std::toupper(ch)) {
                list.push_back(word);
            }
        }
    }

    for (size_t i {}; i < list.size(); ++i) {
        std::cout << list[i] << " ";
    }
}