// 1. This drill is to write a program that produces a simple form letter based on user input. Begin by typing the code
// from §3.1 prompting a user to enter his or her first name and writing “Hello, first_name” where first_name is the
// name entered by the user. Then modify your code as follows: change the prompt to “Enter the name of the person you
// want to write to” and change the output to “Dear first_name,”. Don’t forget the comma.

// 2. Add an introductory line or two, like “How are you? I am fine. I miss you.” Be sure to indent the first line. Add
// a few more lines of your choosing — it’s your letter.

// 3. Now prompt the user for the name of another friend, and store it in friend_name. Add a line to your letter: “Have
// you seen friend_name lately?”

// 4. Declare a char variable called friend_sex and initialize its value to 0. Prompt the user to enter an m if the
// friend is male and an f if the friend is female. Assign the value entered to the variable friend_sex. Then use two
// if-statements to write the following:
// If the friend is male, write “If you see friend_name please ask him to call me.”
// If the friend is female, write “If you see friend_name please ask her to call me.”

// 5. Prompt the user to enter the age of the recipient and assign it to an int variable age. Have your program write
// “I hear you just had a birthday and you are age years old.” If age is 0 or less or 110 or more, call
// simple_error("you're kidding!") using simple_error() from std_lib_facilities.h.

// 6. Add this to your letter:
// If your friend is under 12, write “Next year you will be age+1.”
// If your friend is 17, write “Next year you will be able to vote.”
// If your friend is over 70, write “I hope you are enjoying retirement.”
// Check your program to make sure it responds appropriately to each kind of value.

// 7. Add “Yours sincerely,” followed by two blank lines for a signature, followed by your name.
#include "std_lib_facilities.h"

int main()
{
    cout << "Введите имя адресата:\n";
    string first_name;    // first_name is a variable of type string
    cin >> first_name;    // read characters into first_name
    cout << "Введите имя другого приятеля:\n";
    string friend_name;
    cin >> friend_name;
    cout << "Введите значение 'm', если ваш друг - мужчина,\n";
    cout << "и 'f' - если женщина.\n";
    char friend_sex;
    friend_sex = 0;
    cin >> friend_sex;
    cout << "Введите возраст адресата:\n";
    int age;
    cin >> age;
    if (age <= 0 || age >= 110)
        error("ты шутишь!");

    cout << "\nДорогой " << first_name << ",\n";
    cout << "\n";
    cout << "Как дела? У меня всё хорошо. Я скучаю по тебе.\n";
    cout << "Давно ли ты встречал " << friend_name << "?\n";
    if (friend_sex == 'm')
        cout << "Если ты увидишь " << friend_name << ", пожалуйста, попроси его позвонить мне.\n";
    if (friend_sex == 'f')
        cout << "Если ты увидишь " << friend_name << ", пожалуйста, попроси её позвонить мне.\n";
    cout << "Я слышал, ты только что отметил день рождения и тебе исполнилось " << age << " лет.\n";
    if (age < 12)
        cout << "На следующий год тебе исполнится " << age+1 << " лет.\n";
    if (age == 17)
        cout << "В следующем году ты сможешь голосовать.\n";
    if (age > 70)
        cout << "Я надеюсь, что ты не скучаешь на пенсии.\n";
    cout << "Искренне твой\n";
    cout << "\n";
    cout << "\n";
    cout << "Игорь";
}
