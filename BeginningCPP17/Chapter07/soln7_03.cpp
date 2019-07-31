// Exercise 7-3.
// Write a program that reads a text string of arbitrary length from the keyboard and prompts for entry of a word that
// is to be found in the string. The program should find and replace all occurrences of this word, regardless of case,
// by as many asterisks as there are characters in the word. It should then output the new string. Only whole words are
// to be replaced. For example, if the string is "Our house is at your disposal." and the word that is to be found is
// "our", then the resultant string should be as follows: "*** house is at your disposal." and not "*** house is at y*** 
// disposal.".
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> words;

int main(int argc, char** argv) {
    std::string toSearch;
    std::cout << "Enter the word to be found in the string: " << std::endl;
    getline(std::cin, toSearch);
    for(size_t i {0}; i < toSearch.length(); i++)
        toSearch[i]=tolower(toSearch[i]);

    std::string asterisk {"*"};
    for(size_t i {1}; i < toSearch.length(); ++i) {
        asterisk += "*";
    }

    std::cout << "Enter a text string of arbitrary length: " << std::endl;
    // get the data from argv
    words = std::vector<std::string>(argv, argv + argc);
    char quit[] = "quit";
    std::string line;
    // grab a line at a time
    while(std::getline(std::cin, line) && line != quit) {
        // clear the vector of words
        words.clear();
        // make a string stream to read words from that line
        std::stringstream ss(line);
        // grab all the words into a vector
        std::string word;
        while(ss >> word)
            words.push_back(word);

        std::vector<std::string> words_original(words);

        for (size_t i {}; i < words.size(); i++) {
            for (size_t j {}; j < words[i].size(); j++)
                if (words[i][j] >= 'A' && words[i][j] <= 'Z')
                    words[i][j] = tolower(words[i][j]);
        }

        replace(words.begin(), words.end(), std::string(toSearch), std::string(asterisk));

        for (size_t i {}; i < words_original.size(); ++i) {
            if (words[i] == asterisk)
                std::cout << words[i] << " ";
            else
                std::cout << words_original[i] << " ";
        }
    }
}