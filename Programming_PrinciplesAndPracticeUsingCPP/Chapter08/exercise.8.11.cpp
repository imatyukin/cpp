// 11. Improve print_until_s() from §8.5.2. Test it. What makes a good set of test cases? Give reasons. Then, write a
// print_until_ss() that prints until it sees a second occurrence of its quit argument.

#include "std_lib_facilities.h"

// Выводит вектор до тех пор, пока не встретит строку завершения
void print_until_s(const vector<string>& v, const string& quit)
{
    for (string s : v) {
        if (s == quit) return;
        cout << s << endl;
    }
}

// Выводит вектор до тех пор, пока строка завершения не будет выполнена дважды
void print_until_ss(const vector<string>& v, const string& quit)
{
    bool quit_arg{false};           // Первое появление строки завершения
    for (string s : v) {
        if (s == quit)
            if (quit_arg) return;
            else quit_arg = true;
        cout << s << endl;
    }
}

int main()
try
{
    vector<string> v{"1", "2", "3", "4", "5"};
    const vector<string> null{};
    string quit{"exit"};

    cout << "\nТестирование print_until_s():\n\n";
    print_until_s({"hello", "world", "c++", "quit", "exit"}, "quit");
    print_until_s(v, "");
    print_until_s(null, quit);
    print_until_s({"quit", "hello", "world", "quit", "c++"}, "quit");
    print_until_s({"hello", "world", "c++", "quit", quit}, quit);

    cout << "\nТестирование print_until_ss():\n\n";
    print_until_ss({"hello", "world", "c++", "quit", "exit", "quit",
                    "no more"}, "quit");
    print_until_ss({"hello", "world", quit, "c++", "exit", "quit", quit}, quit);

    return 0;
}
catch(exception& e)
{
    cerr << e.what() << endl;
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 2;
}