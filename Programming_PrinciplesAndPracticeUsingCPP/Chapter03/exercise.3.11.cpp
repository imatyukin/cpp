// 11. Write a program that prompts the user to enter some number of pennies (1-cent coins), nickels (5-cent coins),
// dimes (10-cent coins), quarters (25-cent coins), half dollars (50-cent coins), and one-dollar coins (100-cent coins).
// Query the user separately for the number of each size coin, e.g., “How many pennies do you have?” Then your program
// should print out something like this:
// You have 23 pennies.
// You have 17 nickels.
// You have 14 dimes.
// You have 7 quarters.
// You have 3 half dollars.
// The value of all of your coins is 573 cents.
// Make some improvements: if only one of a coin is reported, make the output grammatically correct, e.g., 14 dimes and
// 1 dime (not 1 dimes). Also, report the sum in dollars and cents, i.e., $5.73 instead of 573 cents.
#include "std_lib_facilities.h"

int main()
{
    int cent, cents_5, cents_10, cents_25, cents_50, dollar, sum_dollars, sum_cents = 0;

    cout << "Введите количество 1-, 5-, 10-, 25-, 50-центовых и долларовых монет.\n";
    cout << "Сколько у вас одноцентовых монет?\n";
    cin >> cent;
    cout << "Сколько у вас пятицентовых монет?\n";
    cin >> cents_5;
    cout << "Сколько у вас десятицентовых монет?\n";
    cin >> cents_10;
    cout << "Сколько у вас двадцатипятицентовых монет?\n";
    cin >> cents_25;
    cout << "Сколько у вас пятидесятицентовых монет?\n";
    cin >> cents_50;
    cout << "Сколько у вас долларовых монет?\n";
    cin >> dollar;

    if (cent != 0) {
        if (cent == 1)
            cout << "У вас " << cent << " одноцентовая монета.\n";
        else
            cout << "У вас " << cent << " одноцентовых монет.\n";
    }
    if (cents_5 != 0) {
        if (cents_5 == 1)
            cout << "У вас " << cents_5 << " пятицентовая монета.\n";
        else
            cout << "У вас " << cents_5 << " пятицентовых монет.\n";
    }
    if (cents_10 != 0) {
        if (cents_10 == 1)
            cout << "У вас " << cents_10 << " десятицентовая монета.\n";
        else
            cout << "У вас " << cents_10 << " десятицентовых монет.\n";
    }
    if (cents_25 != 0) {
        if (cents_25 == 1)
            cout << "У вас " << cents_25 << " двадцатипятицентовая монета.\n";
        else
            cout << "У вас " << cents_25 << " двадцатипятицентовых монет.\n";
    }
    if (cents_50 != 0) {
        if (cents_50 == 1)
            cout << "У вас " << cents_50 << " пятидесятицентовая монета.\n";
        else
            cout << "У вас " << cents_50 << " пятидесятицентовых монет.\n";
    }
    if (dollar != 0) {
        if (dollar == 1)
            cout << "У вас " << dollar << " долларовая монета.\n";
        else
            cout << "У вас " << dollar << " долларовых монет.\n";
    }

    sum_dollars = (cent + cents_5*5 + cents_10*10 + cents_25*25 + cents_50*50 + dollar*100) / 100;
    sum_cents =  (cent + cents_5*5 + cents_10*10 + cents_25*25 + cents_50*50 + dollar*100) % 100;
    cout << "Общая стоимость ваших монет равна " << sum_dollars << " долларов " << sum_cents << " цента.\n";
}