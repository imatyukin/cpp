// Exercise 5-5.
// Write a program equivalent to that of Exercise 5-4, except for the following:
// If before you used a for loop to count the characters, you now use while, or vice versa.
// This time you should first reverse the characters in the array, before printing them out left to right (for the sake
// of the exercise you could still use a loop to print out the characters one by one).
#include <iostream>

#define MAX_STR_LENGTH 1000

int main()
{
    char str[MAX_STR_LENGTH + 1];
    int count = 0;

    while (1) {
        std::cout << "Enter a sequence of characters: ";

        std::cin.getline(str, MAX_STR_LENGTH);
        str[MAX_STR_LENGTH]='\0';

        if ((strlen(str) == 0)) {
            std::cout << "ERROR: You must type something." << std::endl;
            std::cin.clear(); // <--- reset the flags
            continue;
        }
        else if (strlen(str) > MAX_STR_LENGTH - 2) {
            std::cout << "ERROR: The string may only be 1000 characters long." << std::endl;
            std::cin.clear(); // <--- reset the flags
            std::cin.ignore(MAX_STR_LENGTH, '\n'); // <-- skip unread chars
            continue;
        }
        while (str[count] != '\0') {
            count++;
        }
        std::cout << count << " characters read: " << str << '\n';
        break;
    }

    std::cout << "The reverse order: ";
    int temp, i;
    for (i = 0; i < count/2; ++i) {
        temp = str[count-i-1];
        str[count-i-1] = str[i];
        str[i] = temp;
    }
    for (i = 0; i < count; ++i) {
        std::cout << str[i];
    }
}