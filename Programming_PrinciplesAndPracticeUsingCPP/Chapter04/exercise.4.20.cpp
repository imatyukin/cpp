// 20. Modify the program from exercise 19 so that when you enter a name, the program will output the corresponding
// score or name not found.
#include "std_lib_facilities.h"

int main(){
    vector<string> names;
    vector<int> scores;
    vector<string> entered_twice;
    string name = "";
    int score = 0;
    bool flag = false;
    int score_print = 0;

    cout << "Введите набор пар, состоящих из имени и значения (прекращение ввода NoName 0): " << endl;
    while (cin >> name && name != "NoName" && cin >> score && score != 0) {
        names.push_back(name);
        scores.push_back(score);
    }

    for (size_t i = 0; i < names.size(); i++) {
        for (size_t j = 0; j < names.size(); j++) {
            if (i != j && names[i] == names[j]){    // skip when it finds itself
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

    cout << "Введите имя: " << endl;
    while (cin.get() != '\n')
        continue;
    getline(cin, name);

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

    return 0;
}
