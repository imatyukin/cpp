// 4. Define a class Name_value that holds a string and a value. Rework exercise 19 in Chapter 4 to use a
// vector<Name_value> instead of two vectors.
#include "std_lib_facilities.h"

class Name_value {
public:
    string name;
    int value;
    Name_value(string names, int values)
        :name(names), value(values) { }
};

int main(){
    vector<Name_value> nv;
    vector<string> entered_twice;
    string name = "";
    int value = 0;

    cout << "Введите набор пар, состоящих из имени и значения (прекращение ввода NoName 0): " << endl;
    while (cin >> name && name != "NoName" && cin >> value && value != 0) {
        nv.push_back(Name_value(name, value));
    }

    for (size_t i = 0; i < nv.size(); i++) {
        for (size_t j = 0; j < nv.size(); j++) {
            if (i != j && nv[i].name == nv[j].name) {    // skip when it finds itself
                // check if nv[i].name is already on the list
                int m = 0;
                for (size_t k = 0; k < entered_twice.size(); k++) {
                    if (entered_twice[k] == nv[i].name) {
                        m++;
                        cout << "ОШИБКА! Имя " << entered_twice[k] << " введено дважды." << endl;
                        exit(0);
                    }
                }
                if (m == 0)
                    entered_twice.push_back(nv[i].name);
            }
        }
    }

    for (size_t index = 0; index < nv.size(); index++)
    {
        cout << nv[index].name; cout << ", " << nv[index].value << endl;
    }

    return 0;
}
