// Exercise 7-8.
// Repeat Exercise 7-7, only this time the user inputs the numbers one by one, each time followed by an enter. The input
// should be gathered as a sequence of distinct strings—for the sake of the exercise still not directly as
// integers—which are then concatenated to a single string. The input is still terminated by a # character. Also, this
// time, you’re not allowed to use a string stream anymore to extract the numbers from the resulting string.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> numbers;
    vector<int> inumbers;
    string num;
    long sum {};

    cout << "Enter a sequence of numbers terminated by '#': " << endl;

    while (cin >> num && num != "#")
        numbers.emplace_back(num);

    transform(numbers.begin(), numbers.end(), back_inserter(inumbers),
              [](const string& str) { return stoi(str); });

    for (auto i : inumbers)
        sum += i;
    cout << "The sum of the numbers is: " << sum << endl;
}