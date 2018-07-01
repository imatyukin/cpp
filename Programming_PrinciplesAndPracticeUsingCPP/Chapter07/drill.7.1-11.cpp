// 1. Starting from the file calculator08buggy.cpp, get the calculator to compile.
// 2. Go through the entire program and add appropriate comments.
// 3. As you commented, you found errors (deviously inserted especially for you to find). Fix them; they are not in the
// text of the book.
// 4. Testing: prepare a set of inputs and use them to test the calculator. Is your list pretty complete? What should
// you look for? Include negative values, 0, very small, very large, and “silly” inputs.
// 5. Do the testing and fix any bugs that you missed when you commented.
// 6. Add a predefined name k meaning 1000.
// 7. Give the user a square root function sqrt(), for example, sqrt(2+6.7). Naturally, the value of sqrt(x) is the
// square root of x; for example, sqrt(9) is 3. Use the standard library sqrt() function that is available through the
// header std_lib_facilities.h. Remember to update the comments, including the grammar.
// 8. Catch attempts to take the square root of a negative number and print an appropriate error message.
// 9. Allow the user to use pow(x,i) to mean “Multiply x with itself i times”; for example, pow(2.5,3) is 2.5*2.5*2.5.
// Require i to be an integer using the technique we used for %.
// 10. Change the “declaration keyword” from let to #.
// 11. Change the “quit keyword” from quit to exit. That will involve defining a string for quit just as we did for let
// in §7.8.2.
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "std_lib_facilities.h"

struct Token {
    char kind;
    double value;
    string name;

    // Инициализирует kind символом ch
    Token(char ch) :kind(ch) { }
    // Инициализирует kind и value
    Token(char ch, double val) :kind(ch), value(val) { }
    // Инициализирует kind и name
    Token(char ch, string n) :kind(ch), name(n) { }
};

class Token_stream {
private:
    bool full;      // Есть ли лексема в буфере?
    Token buffer;   // Хранит лексему, возвращённую вызовом putback()
public:
    Token_stream() :full(0), buffer(0) { }

    Token get();                                    // Считывает лексему
    void unget(Token t) { buffer=t; full=true; }    // Возвращает лексему в поток

    void ignore(char c);                            // Отбрасывает символы до символа c включительно
};

const char let = 'L';           // Лексема let
const char quit = 'Q';          // t.kind==quit означает, что t - лексема выхода
const char print = ';';         // t.kind==print означает, что t - лексема печати
const char number = '8';        // t.kind==number означает, что t - число
const char name = 'a';          // Лексема Имя
const string prompt = "> ";     // Используется для указания на то, что далее следует ввод
const string result = "= ";     // Используется для указания на то, что далее следует результат
const string declkey = "let";   // Ключевое слово let

Token Token_stream::get()
{
    if (full) { full=false; return buffer; }
    char ch;
    cin >> ch;
    switch (ch) {
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case ';':
        case '=':
            return Token(ch);
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {	cin.unget();    // Вернуть цифру во входной поток
            double val;
            cin >> val;     // Считать число с плавающей точкой
            return Token(number,val);
        }
        default:
            if (isalpha(ch)) {
                string s;
                s += ch;
                while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s=ch;
                cin.unget();
                if (s == "let") return Token(let);
                if (s == "quit") return Token(name);
                return Token(name,s);
            }
            error("Bad token");
    }
}

void Token_stream::ignore(char c)
{
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch;
    while (cin>>ch)
        if (ch==c) return;
}

struct Variable {
    string name;
    double value;
    Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) return names[i].value;
    error("get: undefined name ",s);
}

void set_value(string s, double d)
{
    for (int i = 0; i<=names.size(); ++i)
        if (names[i].name == s) {
            names[i].value = d;
            return;
        }
    error("set: undefined name ",s);
}

bool is_declared(string s)
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) return true;
    return false;
}

Token_stream ts;

double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
        case '(':
        {	double d = expression();
            t = ts.get();
            if (t.kind != ')') error("'(' expected");
        }
        case '-':
            return - primary();
        case number:
            return t.value; // Возвращает значение числа
        case name:
            return get_value(t.name);
        default:
            error("primary expected");
    }
}

double term()
{
    double left = primary();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
            case '*':
                left *= primary();
                break;
            case '/':
            {	double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                break;
            }
            default:
                ts.unget(t);
                return left;
        }
    }
}

double expression()
{
    double left = term();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
            case '+':
                left += term();
                break;
            case '-':
                left -= term();
                break;
            default:
                ts.unget(t);
                return left;
        }
    }
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != 'a') error ("name expected in declaration");
    string name = t.name;
    if (is_declared(name)) error(name, " declared twice");
    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of " ,name);
    double d = expression();
    names.push_back(Variable(name,d));
    return d;
}

double statement()
{
    Token t = ts.get();
    switch(t.kind) {
        case let:
            return declaration();
        default:
            ts.unget(t);
            return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

void calculate()
{
    while(true) try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t=ts.get();
            if (t.kind == quit) return;
            ts.unget(t);
            cout << result << statement() << endl;
        }
        catch(runtime_error& e) {
            cerr << e.what() << endl;
            clean_up_mess();
        }
}

int main()

try {
    calculate();
    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    char c;
    while (cin >>c&& c!=';') ;
    return 1;
}
catch (...) {
    cerr << "exception\n";
    char c;
    while (cin>>c && c!=';');
    return 2;
}
