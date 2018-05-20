// 19. Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22. For each
// pair, add the name to a vector called names and the number to a vector called scores (in corresponding positions, so
// that if names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. Check that each name is unique and
// terminate with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.
#include "std_lib_facilities.h"

int main(){
    vector<string> names;
    vector<int> scores;
    vector<string> entered_twice;
    string name = "";
    int score = 0;

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


    for (size_t index = 0; index < names.size() && index < scores.size(); index++)
    {
        cout << names[index]; cout << ", " << scores[index] << endl;
    }

    return 0;
}
