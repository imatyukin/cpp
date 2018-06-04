// 8. Write a program that reads and stores a series of integers and then computes the sum of the first N integers.
// First ask for N, then read the values into a vector, then calculate the sum of the first N values. For example:
// “Please enter the number of values you want to sum:”
// 3
// “Please enter some integers (press '|' to stop):”
// 12 23 13 24 15 |
// “The sum of the first 3 numbers ( 12 23 13 ) is 48.”
// Handle all inputs. For example, make sure to give an error message if the user asks for a sum of more numbers than
// there are in the vector.
#include "std_lib_facilities.h"
#include <string>

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
    while (cin.good()) {
        char c;
        c = cin.peek();
        if (c == '|') break;
        else {
            cin >> number;
            numbers.push_back(number);
            counter++;
        }
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
