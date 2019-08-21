// Exercise 7-7.
// Create a program that reads an arbitrarily long sequence of integer numbers typed by the user into a single string
// object. The numbers of this sequence are to be separated by spaces and terminated by a # character. In other words,
// the user does not have to press Enter between two consecutive numbers. Next, use a string stream to extract all
// numbers from the string one by one, add these numbers together, and output their sum.
// Before you get started, you’ll need a bit more information on how to use string streams for input. First, you
// construct a std::stringstream object that contains the same character sequence as a given std::string object
// my_string as follows:
//   std::stringstream ss{ my_string };
// Alternatively, you can assign the contents of a given string to an existing string stream:
//   ss.str(my_string);
// Second, unlike std::cin, there’s a limit to the number of values you can extract from a string stream. For this
// exercise, you can check whether there are more numbers left to extract by converting the stream to a Boolean. As
// long as a stream is capable of producing more values, it will convert to true. Once the stream is depleted, it will
// convert to false. In other words, you should simply use your string input stream variable ss in a loop of the
// following form:
//   while (ss) { /* Extract next number from the stream */ }
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<string> inum;

int main(int argc, char** argv) {
    cout << "Enter an arbitrarily long sequence of integers, separated by spaces and terminated by '#': " << endl;
    inum = vector<string>(argv, argv + argc);
    char quit[] = "#";
    string inumseq;
    long sum {};

    while (getline(cin, inumseq) && inumseq != quit) {
        stringstream ss(inumseq);
        string i;
        while (ss >> i)
            inum.push_back(i);
    }
    inum.erase(inum.begin());

    vector<int> isum;
    transform(inum.begin(), inum.end(), back_inserter(isum),
            [](const string& str) { return stoi(str); });

    for (auto i : isum)
        sum += i;
    cout << "The sum of the numbers is: " << sum << endl;
}