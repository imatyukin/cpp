// Exercise 4-5.
// Add some code at the end of the main() function of Ex4_06.cpp to print an additional message. If you have exactly one
// mouse, output a message of the form “It is a brown/white mouse.” Otherwise, if you have multiple mice, compose a
// grammatically correct message of the form “Of these mice, N is a/are brown mouse/mice.” If you have no mice, no new
// message needs to be printed. Use an appropriate mixture of conditional operators and if/else statements.
#include <iostream>

int main() {
    int mice {};               // Count of all mice
    int brown {};              // Count of brown mice
    int white {};              // Count of white  mice

    std::cout << "How many brown mice do you have? ";
    std::cin >> brown;
    std::cout << "How many white mice do you have? ";
    std::cin >> white;

    mice = brown + white;

    if (brown < 0 || white < 0) {
        std::cout << "Amount of mice cannot be negative." << std::endl;
        return 1;
    }

    std::cout << "You have " << mice
              << (mice == 1? " mouse" : " mice")
              << " in total." << std::endl;

    if (brown == 0 && white == 0) {
        return 0;
    } else if (brown == 1 && white == 0) {
        std::cout << "It is a brown mouse." << std::endl;
    } else if (brown == 0 && white == 1) {
        std::cout << "It is a white mouse." << std::endl;
    } else {
        std::cout << "Of these mice, ";
        if (brown == 0) {
            std::cout << "no brown mice and ";
        } else if (brown == 1) {
            std::cout << "one is a brown mouse and ";
        } else {
            std::cout << brown << " are brown mice and ";
        }
        if (white == 0) {
            std::cout << "no white mice." << std::endl;
        } else if (white == 1) {
            std::cout << "one is a white mouse." << std::endl;
        } else {
            std::cout << white << " are white mice." << std::endl;
        }
    }
}