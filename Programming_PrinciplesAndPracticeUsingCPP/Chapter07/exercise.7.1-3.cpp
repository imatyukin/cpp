// 1. Allow underscores in the calculator’s variable names.
// 2. Provide an assignment operator, =, so that you can change the value of a variable after you introduce it using
// let. Discuss why that can be useful and how it can be a source of problems.
// 3. Provide named constants that you really can’t change the value of. Hint: You have to add a member to Variable that
// distinguishes between constants and variables and check for it in set_value(). If you want to let the user define
// constants (rather than just having pi and e defined as constants), you’ll have to add a notation to let the user
// express that, for example, const pi = 3.14;.

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
 *      # Имя "=" Выражение
 *      "const" Имя "=" Выражение
 * Вывод:
 *      ;
 * Выход:
 *      exit
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
 *      Имя
 *          Имя = Выражение
 *      ( Выражение )
 *      - Первичное_выражение
 *      + Первичное_выражение
 *      sqrt( Выражение )
 *      pow( Выражение , Целочисленный_литерал )
 * Число:
 *      Литерал_с_плавающей_точкой
 *      Имя:
 *          [a-zA-Z][a-zA-Z_0-9]*                       // Буква, за которой следует ноль или больше букв, символов
 *                                                      // подчёркивания и цифр
 *
 * Ввод из потока cin через Token_stream с именем ts.
 */

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Token {
    char kind;                                          // Какая лексема
    double value;                                       // Для чисел: значение
    string name;                                        // Для имён: само имя

    // Инициализирует kind символом ch
    Token(char ch)              : kind(ch), value(0) { }
    // Инициализирует kind и value
    Token(char ch, double val)  : kind(ch), value(val) { }
    // Инициализирует kind и name
    Token(char ch, string n)    : kind(ch), name(n) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    // Конструктор просто заполняется, чтобы указать, что буфер пуст
    Token_stream() : full(0), buffer(0) { }             // Создаёт Token_stream, который читает из cin
    Token get();                                        // Считывает лексему (get() определяется в другом месте)
    void unget(Token t) { buffer=t; full=true; }        // Возвращает лексему назад в поток
                                                        // Копирует t в буфер
                                                        // Буфер сейчас заполнен
    void ignore(char c);                                // Отбрасывает лексемы до символа c включительно
private:
    bool full;                                          // Есть ли лексема в буфере?
    Token buffer;                                       // Хранит лексему, возвращённую вызовом putback()
};

//------------------------------------------------------------------------------

const char let = '#';                                   // Лексема декларации let
const char con = 'C';                                   // Лексема декларации const
const char quit = 'Q';                                  // t.kind==quit означает, что t - лексема выхода
const char print = ';';                                 // t.kind==print означает, что t - лексема печати
const char number = '8';                                // t.kind==number означает, что t - числовая лексема
const char name = 'a';                                  // Лексема Имя
const char square_root = 's';                           // Лексема квадратного корня
const char power = 'p';                                 // Лексема функции возведения в степень
const string prompt = "> ";                             // Используется для указания на то, что далее следует ввод
const string result = "= ";                             // Используется для указания на то, что далее следует результат
const string declkey = "#";                             // Ключевой символ #
const string constkey = "const";                        // Ключевое слово const
const string sqrtkey = "sqrt";                          // Ключевое слово sqrt
const string powkey = "pow";                            // Ключевое слово pow
const string quitkey = "exit";                          // Ключевое слово exit

//------------------------------------------------------------------------------

Token Token_stream::get()
// Чтение символов из cin и составление Token
{
    if (full) { full=false; return buffer; }                   // Проверка наличия Token в буфере
    char ch;
    cin >> ch;                                                 // Заметим, что оператор >> пропускает пробельные символы
                                                               // (space, newline, tab и т.д.)
    switch (ch) {
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
        case '#':
            return Token(ch);                                  // Каждый символ представляет сам себя
        case '.':                                              // Число с плавающей точкой может начинаться с точки
            // Числовой литерал:
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.unget();                                       // Возврат цифры во входной поток
            double val;
            cin >> val;                                        // Чтение числа с плавающей точкой
            return Token(number,val);
        }
        default:
            if (isalpha(ch)) {                                 // Начало с буквы
                string s;
                s += ch;
                // Буквы, цифры и символы подчёркивания
                while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s+=ch;
                cin.unget();
                if (s == declkey) return Token(let);           // Ключевое слово объявления "let"
                if (s == constkey) return Token(con);          // Ключевое слово объявления "const"
                if (s == sqrtkey) return Token(square_root);   // Ключевое слово квадратного корня
                if (s == powkey) return Token(power);          // Ключевое слово возведения в степень
                if (s == quitkey) return Token(quit);          // Ключевое слово выхода
                return Token(name,s);
            }
            error("Неверная лексема");
    }

    return 0;
}

//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------

struct Variable {
    string name;
    double value;
    bool var;                                           // переменная (true) или константа (false)
    Variable(string n, double v, bool va = true) :name(n), value(v), var(va) { }
};

//------------------------------------------------------------------------------

vector<Variable> names;

//------------------------------------------------------------------------------

double get_value(string s)
// Возвращает значение переменной с именем s
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) return names[i].value;
    error("get: неопределённая переменная ",s);

    return 0;
}

//------------------------------------------------------------------------------

void set_value(string s, double d)
// Присваивает объекту s типа Variable значение d
{
    for (int i = 0; i<=names.size(); ++i)
        if (names[i].name == s) {
            if (names[i].var==false) error(s," константа");
            names[i].value = d;
            return;
        }
    error("set: неопределённая переменная ",s);
}

//------------------------------------------------------------------------------

bool is_declared(string var)
// Есть ли переменная var в векторе names
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == var) return true;
    return false;
}

//------------------------------------------------------------------------------

double define_name(string s, double val, bool var=true)
// Добавляем (s,val,var) в вектор names
{
    if (is_declared(s)) error(s," повторное объявление");
    names.push_back(Variable(s,val,var));
    return val;
}

//------------------------------------------------------------------------------

Token_stream ts;                                        // обеспечивает get() и unget()

//------------------------------------------------------------------------------

double expression();                                    // Декларируется так, чтобы primary() мог вызывать expression()

//------------------------------------------------------------------------------

double primary()
// Для работы с числами и круглыми скобками
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':                                        // Обработка правила '(' Выражение ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' требуется");
            return d;
        }
    case number:
        return t.value;                              // Возвращает значение числа
    case name:
        {
            Token next = ts.get();
            if (next.kind == '=') {                  // Обработка правила name = expression
                double d = expression();
                set_value(t.name,d);
                return d;
            }
            else {
                ts.unget(next);                      // не назначен: вернуть значение
                return get_value(t.name);            // вернуть значение переменной
            }
        }
    case '-':
        return - primary();
    case '+':
        return primary();
    case square_root:                                // Обработка правила 'sqrt(' Выражение ')'
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
    case power:                                      // Обработка правила 'pow(' Выражение ',' Целочисленный_литерал ')'
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
    default:
        error("требуется первичное выражение");
    }

    return 0;
}

//------------------------------------------------------------------------------

double term()
// Для работы с *, / и %
{
    double left = primary();
    Token t = ts.get();                                 // Получает следующий токен из потока токенов

    while(true) {
        switch(t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {
                double d = primary();
                if (d == 0) error("деление на нуль");
                left /= d;
                t = ts.get();
                break;
            }
        case '%':
            {
                int i1 = narrow_cast<int>(left);
                int i2 = narrow_cast<int>(term());
                if (i2 == 0) error("%: деление на нуль");
                left = i1%i2;
                t = ts.get();
                break;
            }
        default:
            ts.unget(t);                                // Помещает t обратно в поток токенов
            return left;
        }
    }
}

//------------------------------------------------------------------------------

double expression()
// Для работы с + and -
{
    double left = term();                               // Читает и оценивает Term
    Token t = ts.get();                                 // Получает следующий токен из потока токенов

    while(true) {
        switch(t.kind) {
        case '+':
            left += term();                             // Оценивает Term и складывает
            t = ts.get();
            break;
        case '-':
            left -= term();                             // Оценивает Term и вычитает
            t = ts.get();
            break;
        default:
            ts.unget(t);                                // Помещает t обратно в поток токенов
            return left;                                // Окончательно: нет + или -: возвращает ответ
        }
    }
}

//------------------------------------------------------------------------------

double declaration(Token k)
// Считаем, что мы уже встретили ключевое слово "let"
// Обрабатываем: Имя = Выражение
// Объявление переменной с Именем с начальным значением, заданным Выражением
// k будет "let" или "con"(stant)
{
    Token t = ts.get();
    if (t.kind != name) error ("в объявлении ожидается имя переменной");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("пропущен символ = в объявлении " , var_name);

    double d = expression();
    define_name(var_name,d,k.kind==let);
    return d;
}

//------------------------------------------------------------------------------

double statement()
{
    Token t = ts.get();
    switch(t.kind) {
    case let:
    case con:
        return declaration(t.kind);
    default:
        ts.unget(t);
        return expression();
    }
}

//------------------------------------------------------------------------------

void clean_up_mess()
{
    ts.ignore(print);
}

//------------------------------------------------------------------------------

void calculate()                                        // Цикл вычисления выражения
{
    while(cin)
        try {
            cout << prompt;                             // Вывод приглашения
            Token t = ts.get();
            while (t.kind == print)
                t=ts.get();                             // Отбрасывание команд вывода
            if (t.kind == quit) return;                 // Выход
            ts.unget(t);
            cout << result << statement() << endl;      // Вывод результатов
        }
        catch(exception& e) {
            cerr << e.what() << endl;                   // Вывод сообщения об ошибке
            clean_up_mess();
        }
}

//------------------------------------------------------------------------------

int main()
try {
    // Предопределение имён
    define_name("pi",3.1415926535);                     // Эти предопределённые имена являются константами
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

//------------------------------------------------------------------------------