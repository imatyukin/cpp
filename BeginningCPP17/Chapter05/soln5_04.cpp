// Exercise 5-4.
// Use std::cin.getline(…) to obtain a C-style string of maximum 1,000 characters from the user. Count the number of
// characters the user entered using an appropriate loop. Next, write a second loop that prints out all characters, one
// by one, but in a reverse order.
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
        for (int i = 0; str[i] != '\0'; i++) {
            count++;
        }
        std::cout << count << " characters read: " << str << '\n';
        break;
    }

    std::cout << "The reverse order: ";
    for (--count; count >= 0; count--) {
        std::cout << str[count];
    }
}