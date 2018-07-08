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
/*
 * Простой калькулятор
 *
 * Эта программа реализует основные выражения калькулятора.
 * Ввод осуществляется из потока cin; вывод - в поток cout.
 *
 * Грамматика для ввода:
 *
 * Вычисление:
 *      Инструкция
 *      Вывод
 *      Выход
 *      Вычисление Инструкция
 * Инструкция:
 *      Объявление
 *      Выражение
 * Объявление:
 *      "let" Имя "=" Выражение
 * Вывод:
 *      ;
 * Выход:
 *      Q
 * Выражение:
 *      Терм
 *      Выражение + Терм
 *      Выражение - Терм
 * Терм:
 *      Первичное_выражение
 *      Терм * Первичное_выражение
 *      Терм / Первичное_выражение
 *      Терм % Первичное_выражение
 * Первичное_выражение:
 *      Число
 *      ( Выражение )
 *      - Первичное_выражение
 *      + Первичное_выражение
 *      sqrt( Выражение )
 *      pow( Выражение , Целочисленный_литерал )
 * Число:
 *      Литерал_с_плавающей_точкой
 *
 * Ввод из потока cin через Token_stream с именем ts.
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
public:
    Token_stream() :full(0), buffer(0) { }
    Token get();                                        // Считывает лексему
    void unget(Token t) { buffer=t; full=true; }        // Возвращает лексему в поток
    void ignore(char c);                                // Отбрасывает символы до символа c включительно

private:
    bool full;                                          // Есть ли лексема в буфере?
    Token buffer;                                       // Хранит лексему, возвращённую вызовом putback()
};

const char let = 'L';                                   // Лексема let
const char quit = 'Q';                                  // t.kind==quit означает, что t - лексема выхода
const char print = ';';                                 // t.kind==print означает, что t - лексема печати
const char number = '8';                                // t.kind==number означает, что t - число
const char name = 'a';                                  // Лексема Имя
const char square_root = 's';                           // Лексема квадратного корня
const char power = 'p';                                 // Лексема функции возведения в степень
const string prompt = "> ";                             // Используется для указания на то, что далее следует ввод
const string result = "= ";                             // Используется для указания на то, что далее следует результат
const string declkey = "let";                           // Ключевое слово let
const string sqrtkey = "sqrt";                          // Ключевое слово sqrt
const string powkey = "pow";                            // Ключевое слово pow

Token Token_stream::get()
    // Чтение символов из cin и составление Token
{
    if (full) { full=false; return buffer; }                // Проверка наличия Token в буфере
    char ch;
    cin >> ch;                                              // Заметим, что оператор >> пропускает пробельные символы
    switch (ch) {
    case quit:
    case print:
    case '(':
    case ')':
    case '-':
    case '+':
    case '*':
    case '/':
    case '%':
    case '=':
    case ',':
        return Token(ch);                                   // Каждый символ представляет сам себя
    case '.':                                               // Число с плавающей точкой может начинаться с точки
    // Числовой литерал:
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {
            cin.unget();                                    // Возврат цифры во входной поток
            double val;
            cin >> val;                                     // Чтение числа с плавающей точкой
            return Token(number,val);
        }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
            cin.unget();
            if (s == declkey) return Token(let);            // Ключевое слово объявления
            if (s == sqrtkey) return Token(square_root);    // Ключевое слово квадратного корня
            if (s == powkey) return Token(power);           // Ключевое слово возведения в степень
            if (s == "quit") return Token(name);
            return Token(name,s);
        }
        error("Неверная лексема");
    }

    return 0;
}

void Token_stream::ignore(char c)
    // Символ c представляет разновидность лексем
{
    // Сначала проверяем буфер:
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // Теперь проверяем входные данные:
    char ch = 0;
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
    // Возвращает значение переменной с именем s
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) return names[i].value;
    error("get: неопределённая переменная ",s);

    return 0;
}

void set_value(string s, double d)
    // Присваивает объекту s типа Variable значение d
{
    for (int i = 0; i<=names.size(); ++i)
        if (names[i].name == s) {
            names[i].value = d;
            return;
        }
    error("set: неопределённая переменная ",s);
}

bool is_declared(string s)
    // Есть ли переменная s в векторе names
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) return true;
    return false;
}

double define_name(string var, double val)
    // Добавляем пару (var,val) в вектор names
{
    if (is_declared(var)) error(var," повторное объявление");
    names.push_back(Variable(var,val));
    return val;
}

Token_stream ts;

double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case number:
        return t.value;                             // Возвращает значение числа
    case '(':                                       // Обработка правила '(' Выражение ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' требуется");
            return d;
        }
    case '-':
        return - primary();
    case '+':
        return primary();
    case square_root:                               // Обработка правила 'sqrt(' Выражение ')'
        {
            t = ts.get();
            if (t.kind != '(') error("'(' требуется");
            double d = expression();
            if (d < 0) error("корень чётной степени из отрицательного числа не существует в области вещественных "
                             "чисел");
            t = ts.get();
            if (t.kind != ')') error("')' требуется");
            return sqrt(d);
        }
    case power:                                     // Обработка правила 'pow(' Выражение ',' Целочисленный_литерал ')'
        {
            t = ts.get();
            if (t.kind != '(') error("'(' требуется");
            double d = expression();
            t = ts.get();
            if (t.kind != ',') error("',' требуется");
            t = ts.get();
            if (t.kind != number) error("второй аргумент pow() должен быть целым числом");
            int i = int(t.value);
            if (t.value != i) error("второй аргумент pow() должен быть целым числом");
            t = ts.get();
            if (t.kind != ')') error("')' требуется");
            return pow(d,i);
        }
    case name:
        return get_value(t.name);
    default:
        error("требуется первичное выражение");
    }

    return 0;
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
            {
                double d = primary();
                if (d == 0) error("деление на нуль");
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
    // Считаем, что мы уже встретили ключевое слово "let"
    // Обрабатываем: Имя = Выражение
    // Объявление переменной с Именем с начальным значением, заданным Выражением
{
    Token t = ts.get();
    if (t.kind != name) error ("в объявлении ожидается имя переменной");
    string var_name = t.name;

    if (is_declared(var_name)) error(var_name, " объявлена дважды");

    Token t2 = ts.get();
    if (t2.kind != '=') error("пропущен символ = в объявлении " ,var_name);

    double d = expression();
    define_name(var_name,d);
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

void calculate()                                    // Цикл вычисления выражения
{
    while(true)
    try {
        cout << prompt;                             // Вывод приглашения
        Token t = ts.get();
        while (t.kind == print)
            t=ts.get();                             // Отбрасывание команд вывода
        if (t.kind == quit) return;                 // Выход
        ts.unget(t);
        cout << result << statement() << endl;      // Вывод результатов
    }
    catch(runtime_error& e) {
        cerr << e.what() << endl;                   // Вывод сообщения об ошибке
        clean_up_mess();
    }
}

int main()
try {
    // Предопределённые имена
    define_name("pi",3.1415926535);
    define_name("e",2.7182818284);
    define_name("k",1000);

    calculate();

    return 0;
}
catch (exception& e) {
    cerr << "исключение: " << e.what() << endl;
    char c;
    while (cin>>c && c!=';') ;
    return 1;
}
catch (...) {
    cerr << "исключение\n";
    char c;
    while (cin>>c && c!=';');
    return 2;
}
