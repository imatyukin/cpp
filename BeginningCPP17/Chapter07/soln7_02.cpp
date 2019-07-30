// Exercise 7-2.
// Write a program that reads text entered over an arbitrary number of lines. Find and record each unique word that
// appears in the text and record the number of occurrences of each word. Output the words and their occurrence counts.
// Words and counts should align in columns. The words should align to the left; the counts to the right. There should
// be three words per row in your table.
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> words;

int main(int argc, char** argv) {
    // get the data from argv
    words = std::vector<std::string>(argv, argv + argc);

    char quit[] = "quit";
    int total_words = 0;

    std::string line;
    // grab a line at a time
    while(std::getline(std::cin, line) && line != quit) {
        // clear the vector of words
        words.clear();
        // make a string stream to read words from that line
        std::stringstream ss(line);
        // grab all the words into a vector
        std::string word;
        while(ss >> word) {
            words.push_back(word);
        }
        std::cout <<"You entered " <<words.size() <<" words." <<std::endl;
    }
}