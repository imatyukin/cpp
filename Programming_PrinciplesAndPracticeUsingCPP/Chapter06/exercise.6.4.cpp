// 4. Define a class Name_value that holds a string and a value. Rework exercise 19 in Chapter 4 to use a
// vector<Name_value> instead of two vectors.
#include "std_lib_facilities.h"

class Name_value {
public:
    string name;
    int score;
    Name_value(string names, int scores)
        :name(names), score(scores) { }
};

int main(){
    vector<Name_value> ns;
    vector<string> entered_twice;
    string name = "";
    int score = 0;

    cout << "Введите набор пар, состоящих из имени и значения (прекращение ввода NoName 0): " << endl;
    while (cin >> name && name != "NoName" && cin >> score && score != 0) {
        ns.push_back(Name_value(name, score));
    }

    for (size_t i = 0; i < ns.size(); i++) {
        for (size_t j = 0; j < ns.size(); j++) {
            if (i != j && ns[i].name == ns[j].name) {    // skip when it finds itself
                // check if ns[i].name is already on the list
                int m = 0;
                for (size_t k = 0; k < entered_twice.size(); k++) {
                    if (entered_twice[k] == ns[i].name) {
                        m++;
                        cout << "ОШИБКА! Имя " << entered_twice[k] << " введено дважды." << endl;
                        exit(0);
                    }
                }
                if (m == 0)
                    entered_twice.push_back(ns[i].name);
            }
        }
    }

    for (size_t index = 0; index < ns.size(); index++)
    {
        cout << ns[index].name; cout << ", " << ns[index].score << endl;
    }

    return 0;
}
