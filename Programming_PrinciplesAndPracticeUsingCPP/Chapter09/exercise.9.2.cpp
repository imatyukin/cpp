// 2. Design and implement a Name_pairs class holding (name,age) pairs where name is a string and age is a double.
// Represent that as a vector<string> (called name) and a vector<double> (called age) member. Provide an input operation
// read_names() that reads a series of names. Provide a read_ages() operation that prompts the user for an age for each
// name. Provide a print() operation that prints out the (name[i],age[i]) pairs (one per line) in the order determined
// by the name vector. Provide a sort() operation that sorts the name vector in alphabetical order and reorganizes the
// age vector to match. Implement all “operations” as member functions. Test the class (of course: test early and
// often).

#include "std_lib_facilities.h"

// Класс содержащий пару (имя,возраст)
class Name_pairs {
public:
    void read_names();      // операция ввода считывающая ряд имён
    void read_ages();       // операция предлагающая пользователю ввести возраст для каждого имени
    void print() const;     // операция, которая выводит на экран пары (name[i],age[i]) (по одной в строке) в порядке,
                            // определённом вектором name
    void sort();            // операция, упорядочивающая вектор name в алфавитном порядке и соответствующим образом
                            // реорганизующая вектор age
private:
    vector<string> name;
    vector<double> age;
};

// Считывает ряд имён
void Name_pairs::read_names()
{
    cout << "Введите имена и 'NoName' для завершения: ";
    string s;
    while (cin >> s && s != "NoName") {
        for (int i = 0; i < name.size(); ++i)
            if (name[i] == s) error("Имя уже существует: ", s);
        name.push_back(s);
    }
}

// Предлагает пользователю ввести возраст для каждого имени
void Name_pairs::read_ages()
{
    for (int i = 0; i < name.size(); ++i) {
        cout << "Возраст " << name[i] << ": ";
        double a;
        cin >> a;
        age.push_back(a);
    }
}

// Выводит на экран пары (name[i],age[i]) (по одной в строке) в порядке, определённом вектором name
void Name_pairs::print() const
{
    if (name.size() != age.size())
        error("print(): вектора name и age должны быть одного размера");
    for (int i = 0; i < name.size(); ++i) {
        cout << '(' << name[i] << ',' << age[i] << ')' << endl;
    }
}

// Упорядочивает вектор name в алфавитном порядке и соответствующим образом реорганизует вектор age
void Name_pairs::sort()
{
    if (name.size() != age.size())
        error("sort(): вектора name и age должны быть одного размера");
    Vector<string> name_presort = name;
    Vector<double> age_cp = age;
    std::sort(name.begin(), name.end());
    for (int i = 0; i < name.size(); ++i) {
        for (int j = 0; j < name_presort.size(); ++j) {
            if (name[i] == name_presort[j])
                age[i] = age_cp[j];
        }
    }
}

int main()
try
{
    Name_pairs pairs;

    pairs.read_names();
    pairs.read_ages();
    cout << endl;

    pairs.print();
    cout << endl;

    pairs.sort();
    cout << "В алфавитном порядке:" << endl;
    pairs.print();

    return 0;
}
catch (runtime_error e) {   // этот код предназначен для создания сообщений об ошибках
    cout << e.what() << '\n';
}
catch (...) {	            // этот код предназначен для создания сообщений об ошибках
    cout << "exiting\n";
}