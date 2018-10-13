// 3. Replace Name_pair::print() with a (global) operator << and define == and != for Name_pairs.

#include "std_lib_facilities.h"

// Класс содержащий пару (имя,возраст)
class Name_pairs {
public:
    void read_names();      // операция ввода считывающая ряд имён
    void read_ages();       // операция предлагающая пользователю ввести возраст для каждого имени
    void sort();            // операция, упорядочивающая вектор name в алфавитном порядке и соответствующим образом
                            // реорганизующая вектор age
    const vector<string>& get_name() const { return name; }
    const vector<double>& get_age() const { return age; }
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

// Операторы
ostream& operator<<(ostream& os, const Name_pairs& np)
{
    if (np.get_name().size() != np.get_age().size())
        error("<<: вектора name и age должны быть одного размера");
    for (int i = 0; i<np.get_name().size(); ++i)
        os << '(' << np.get_name()[i] << ',' << np.get_age()[i] << ')' << endl;
    return os;
}

bool operator==(const Name_pairs& a, const Name_pairs& b)
{
    if (a.get_name().size()!=b.get_name().size() || a.get_age().size() != b.get_age().size())
        return false;
    bool equal = true;
    for (int i = 0; i<a.get_name().size(); ++i) {
        if (a.get_name()[i] != b.get_name()[i])
            return false;
    }
    for (int i = 0; i<a.get_age().size(); ++i) {
        if (a.get_age()[i] != b.get_age()[i])
            return false;
    }
    return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
    return !(a==b);
}

int main()
try
{
    Name_pairs pairs;

    pairs.read_names();
    pairs.read_ages();
    cout << endl;
    cout << pairs << endl;

    pairs.sort();
    cout << "В алфавитном порядке:" << endl;
    cout << pairs << endl;

    Name_pairs others;

    others.read_names();
    others.read_ages();
    cout << endl;
    others.sort();
    cout << others;

    if ( pairs == others )
        cout << "Те же лица.\n";
    if ( pairs != others )
        cout << "Ещё один набор.\n";

    return 0;
}
catch (runtime_error e) {   // этот код предназначен для создания сообщений об ошибках
    cout << e.what() << '\n';
}
catch (...) {	            // этот код предназначен для создания сообщений об ошибках
    cout << "exiting\n";
}