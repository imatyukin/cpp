// 7. Read five names into a vector<string> name, then prompt the user for the ages of the people named and store the
// ages in a vector<double> age. Then print out the five (name[i],age[i]) pairs. Sort the names (sort(name.begin(),
// name.end())) and print out the (name[i],age[i]) pairs. The tricky part here is to get the age vector in the correct
// order to match the sorted name vector. Hint: Before sorting name, take a copy and use that to make a copy of age in
// the right order after sorting name. Then, do that exercise again but allowing an arbitrary number of names.

#include "std_lib_facilities.h"

vector<string> name;
vector<double> age;

void read_pairs()
{
    string n;
    int v;

    while (cin>>n>>v && n!="NoName") {	                // читает string int пару
        for (int i=0; i<name.size(); ++i)
            if (n==name[i]) error("дублируется: ",n);   // проверяет дублирование
        name.push_back(n);
        age.push_back(v);
    }
}

void write_pairs(string label)
{
    cout << label;
    for (int i=0; i<name.size(); ++i)
        cout << '(' << name[i] << ',' << age[i] << ")\n";
}

int find_index(const vector<string>& v,const string& n)
// найходит n-ые индексы в v
{
    for (int i=0; i<n.size(); ++i)
        if (n==v[i]) return i;
    error("имя не найдено: ",n);

    return 0;
}

int main()
try
{
    read_pairs();

    write_pairs("\nПо порядку:\n");

    vector<string> original_names = name;	            // копирует имена
    vector<double> original_ages = age;		            // копирует возраст

    sort(name.begin(),name.end());			            // сортирует имена

    for(int i=0; i<name.size(); ++i)		            // обновляет возраст
        age[i] = original_ages[find_index(original_names,name[i])];

    write_pairs("\nСортированный:\n");
}
catch (runtime_error e) {	                            // этот код предназначен для создания сообщений об ошибках
    cout << e.what() << '\n';
}
catch (...) {	                                        // этот код предназначен для создания сообщений об ошибках
    cout << "exiting\n";
}