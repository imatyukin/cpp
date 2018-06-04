// 10. Modify the program from exercise 8 to use double instead of int. Also, make a vector of doubles containing the
// N–1 differences between adjacent values and write out that vector of differences.
#include "std_lib_facilities.h"
#include <string>

int main()
{
    int N = 0;
    string theInput;
    vector<double> numbers;
    double number = 0;
    int counter = 0;
    double sum = 0;
    vector<double> adj_diff;

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

    cout << "Введите несколько чисел (| для окончания ввода):" << endl;
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

    if (numbers.size() - 1  < 2)
        error ("ОШИБКА -- Необходимо минимум два значения для разности между соседними величинами");
    for (size_t i = 0; i < numbers.size() - 2; i++)
        adj_diff.push_back(numbers[i] - numbers[i + 1]);

    for (int i = 0; i < adj_diff.size(); ++i)
        cout << adj_diff[i] << " ";
    cout << "\b" << endl;

    return 0;
}
