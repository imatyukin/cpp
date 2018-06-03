// 9. Modify the program from exercise 8 to write out an error if the result cannot be represented as an int.
#include "std_lib_facilities.h"
#include <string>
#include <sstream>

int main()
{
    int N = 0;
    string theInput;
    vector<int> numbers;
    int number = 0;
    int counter = 0;
    int sum = 0;

    cout << "Введите количество суммируемых значений:" << endl;
    getline(cin, theInput);
    while (cin.fail() || cin.eof() || theInput.find_first_not_of("0123456789") != string::npos) {
        cout << "ОШИБКА -- Требуется ввести целое положительное число." << endl;
        if (theInput.find_first_not_of("0123456789") == string::npos) {
            cin.clear();
            cin.ignore(256,'\n');
        }
        getline(cin, theInput);
    }
    string::size_type st;
    N = stoi(theInput,&st);

    cout << "Введите несколько целых чисел (| для окончания ввода):" << endl;
    getline(cin, theInput);
    while (cin.fail() || cin.eof() || theInput.find_first_not_of("0123456789| ") != string::npos) {
        cout << "ОШИБКА -- Требуется ввести ряд целых положительных чисел и | для окончания ввода." << endl;
        if (theInput.find_first_not_of("0123456789| ") == string::npos) {
            cin.clear();
            cin.ignore(256, '\n');
        }
        getline(cin, theInput);
    }

    size_t endstr = theInput.find("|");
    if (endstr == string::npos) error ("ОШИБКА -- Не найден | для окончания ввода.");

    char split_char = ' ';
    istringstream split(theInput);
    vector<string> tokens;
    for (string each; getline(split, each, split_char); tokens.push_back(each));

    for (size_t i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] != "|") {
            number = atoi(tokens.at(i).c_str());
            numbers.push_back(number);
            counter++;
        }
        else break;
    }

    if (counter == 0) error ("ОШИБКА -- Вектор не содержит чисел.");
    else if (N == 0) error ("ОШИБКА -- Требуется просуммировать 0 чисел.");
    else if (N > counter) error ("ОШИБКА -- Требуется просуммировать чисел больше, чем сохранено в векторе.");
    else {
        cout << "Сумма первых " << N << " чисел (";
        for (size_t i = 0; i < N; ++i)
            cout << numbers[i] << " ";
        cout << "\b) равна ";
        for (size_t i = 0; i < N; ++i)
            sum += numbers[i];
        cout << sum << "." << endl;
    }

    return 0;
}
