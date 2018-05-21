// 21. Modify the program from exercise 19 so that when you enter an integer, the program will output all the names with
// that score or score not found.
#include "std_lib_facilities.h"
#include <string>

bool is_int(string str, int base = 0) { // if base == 0, base is auto-detected
    size_t pos = 0 ;
    try {
        // http://en.cppreference.com/w/cpp/string/basic_string/stol
        std::stoi(str, std::addressof(pos), base);
        return pos == str.size();       // true if the entire string was consumed
    }
    catch (const std::exception&) {
        return false;
    }
}

int main(){
    vector<string> names;
    vector<int> scores;
    vector<string> entered_twice;
    string name = "";
    int score = 0;
    bool flag = false;
    int score_print = 0;
    string name_print = "";

    cout << "Введите набор пар, состоящих из имени и значения (прекращение ввода NoName 0): " << endl;
    while (cin >> name && name != "NoName" && cin >> score && score != 0) {
        names.push_back(name);
        scores.push_back(score);
    }

    for (size_t i = 0; i < names.size(); i++) {
        for (size_t j = 0; j < names.size(); j++) {
            if (i != j && names[i] == names[j]) {   // skip when it finds itself
                // check if names[i] is already on the list
                int m = 0;
                for (size_t k = 0; k < entered_twice.size(); k++) {
                    if (entered_twice[k] == names[i]) {
                        m++;
                        cout << "ОШИБКА! Имя " << entered_twice[k] << " введено дважды." << endl;
                        exit(0);
                    }
                }
                if (m == 0)
                    entered_twice.push_back(names[i]);
            }
        }
    }

    cout << "Введите имя или количество баллов: " << endl;
    while (cin.get() != '\n')
        continue;
    cin >> name;

    if (!is_int(name, 10)) {
        // Not an integer
        string(score) = name;

        for (size_t index = 0; index < names.size() && index < scores.size(); index++) {
            if (names[index] == name) {
                flag = true;
                score_print = scores[index];
            }
        }

        if (flag == true)
            cout << "Количество баллов: " << score_print << endl;
        else
            cout << "Имя не найдено" << endl;
    }
    else {
        cout << "Имена всех студентов, получивших указанное количество баллов: " << endl;
        for (size_t index = 0; index < names.size() && index < scores.size(); index++) {
            if (scores[index] == std::stoi(name)) {
                flag = true;
                cout << (name_print = names[index]) << endl;
            }
        }

        if (flag == true)
            exit(0);
        else
            cout << "Баллы не найдены" << endl;
    }

    return 0;
}
