// 1. Modify the calculator program from Chapter 7 to make the input stream an explicit parameter (as shown in §8.5.8),
// rather than simply using cin. Also give the Token_stream constructor (§7.8.2) an istream& parameter so that when we
// figure out how to make our own istreams (e.g., attached to files), we can use the calculator for those. Hint: Don’t
// try to copy an istream.

/*
 * Простой калькулятор
 *
 * Эта программа реализует основные выражения калькулятора.
 *
 * Грамматика для ввода:
 *
 * Вычисление:
 *     Инструкция
 *     Команда
 *     Вывод
 *     Вычисление Инструкция
 * Инструкция:
 *     Объявление
 *     Назначение
 *     Выражение
 * Команда:
 *     "help"
 *     "symbols"
 *     "quit"
 * Вывод:
 *     ";"
 *     "\n"
 * Объявление:
 *     "let" Имя "=" Выражение
 *     "const" Имя "=" Выражение
 * Назначение:
 *     Имя "=" Выражение
 * Выражение:
 *     Терм
 *     Выражение "+" Терм
 *     Выражение "-" Терм
 * Терм:
 *     Первичное_выражение
 *     Терм "*" Первичное_выражение
 *     Терм "/" Первичное_выражение
 *     Терм "%" Первичное_выражение
 * Первичное_выражение:
 *     Число
 *     "("Выражение")"
 *     "-" Первичное_выражение
 *     "+" Первичное_выражение
 *     Имя
 *     Функция"("Аргументы")"
 * Функция:
 *     "sqrt"
 *     "pow"
 * Аргументы:
 *     Выражение
 *     Аргумент","Выражение
 * Число:
 *     [Литерал_с_плавающей_точкой]
 * Имя:
 *     [a-zA-Z][a-zA-Z_0-9]*           // Буква, за которой следует ноль или больше букв, символов подчёркивания и цифр
 *
 * Ввод из istream через Token_stream с именем ts.
*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Моделирует токен грамматики из ввода
class Token {
public:
    // Вид лексем (kind) всегда необходим, а значение (value) и имя (name) инициализируются в зависимости от
    // потребности каждого вида (kind). Таким образом, определены три различных конструктора.
    char kind;                                          // Какая лексема
    double value;                                       // Для чисел: значение
    string name;                                        // Для имён: само имя

    // Инициализирует kind символом ch
    Token(char ch)              : kind{ch} { }
    // Инициализирует kind и value
    Token(char ch, double val)  : kind{ch}, value{val} { }
    // Инициализирует kind и name
    Token(char ch, string n)    : kind{ch}, name{n} { }
};

//------------------------------------------------------------------------------

// Моделирует istream как поток токенов (Token)
class Token_stream {
public:
    Token_stream(istream& is)   : input{cin} { }        // Создаёт Token_stream, который читает из cin
    Token get();                                        // Считывает лексему (get() определяется в другом месте)
    void putback(Token t) { buffer.push_back(t); }      // Возвращает лексему назад в поток
    // Копирует t в буфер
    // Буфер сейчас заполнен
    void ignore(char c);                                // Отбрасывает лексемы до символа c включительно
private:
    vector<Token> buffer;
    istream& input;
};

//------------------------------------------------------------------------------

// Типы токенов (Token kinds) - произвольно выбранные
const char let = 'L';                                   // Лексема декларации let
const char constant = 'C';                              // Лексема декларации constant
const char command = 'c';                               // Лексема декларации command
const char print = ';';                                 // t.kind==print означает, что t - лексема печати
const char number = '8';                                // t.kind==number означает, что t - числовая лексема
const char name = 'a';                                  // Лексема Имя
const char sqrtfun = 's';                               // Лексема квадратного корня
const char powfun = 'p';                                // Лексема функции возведения в степень
// Ключевые слова (keywords)
const string declkey = "let";                           // Ключевое слово let
const string constkey = "const";                        // Ключевое слово const
const string symkey = "symbols";                        // Ключевое слово symbols
const string helpkey = "help";                          // Ключевое слово help
const string quitkey = "quit";                          // Ключевое слово quit
// Встроенные функции (builtin functions)
const string sqrtkey = "sqrt";                          // Ключевое слово sqrt
const string powkey = "pow";                            // Ключевое слово pow

//------------------------------------------------------------------------------

Token Token_stream::get()
// Обрабатывает istream для получения токенов из реализованной грамматики
{
    // Если Token уже в буфере, возвращается последний
    if (!buffer.empty()) {
        Token t = buffer.back();
        buffer.pop_back();
        return t;
    }

    char ch = ' ';

    // Отбрасывает пробельные символы, кроме '\n'
    while (isspace(ch) && ch != '\n')
        ch = input.get();                               // вместо > захват пробелов (и других разделителей)

    switch (ch) {
        case ';':                                       // Группируем две альтернативы для печати
        case '\n':
            return Token{print};
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
        case ',':                                       // Добавлен как разделитель для списков аргументов функций
            return Token{ch};                           // Эти литералы напрямую определяют тип Token
        case '.':
        // Числовой литерал:
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            input.putback(ch);                          // Возврат цифры во входной поток
            double val;
            input >> val;                               // Чтение числа с плавающей точкой
            return Token{number, val};
        }
        default:
            // Также возможно ожидать строки. Это ключевые слова для деклараций, выхода из программы и имён переменных.
            if (isalpha(ch)) {                          // Начало с буквы
                string s;
                s += ch;
                // Буквы, цифры и символы подчёркивания
                while (input.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
                input.putback(ch);
                if (s == declkey) return Token{let};                // Ключевое слово объявления "let"
                if (s == constkey) return Token{constant};          // Ключевое слово объявления "const"
                if (s == quitkey) return Token{command, quitkey};   // Ключевое слово выхода
                if (s == helpkey) return Token{command, helpkey};   // Ключевое слово помощи
                if (s == symkey) return Token{command, symkey};
                if (s == sqrtkey) return Token{sqrtfun};            // Ключевое слово квадратного корня
                if (s == powkey) return Token{powfun};              // Ключевое слово возведения в степень
                return Token{name,s};
            }
            error("Неверная лексема");
    }

    return 0;
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
// Очистить ввод до тех пор, пока не будет найдено c или '\n'
// Символ c представляет разновидность лексем
{
    // Сначала проверяем буфер на наличие токена c-типа
    // Извлекаем токены не c-типа
    while (!buffer.empty() && buffer.back().kind != c)
        buffer.pop_back();
    // Буфер содержит символ токена c-типа
    if (!buffer.empty()) return;

    // и работает напрямую на istream
    char ch{' '};
    while (ch != c && ch != '\n')
        ch = input.get();
    return;
}

//------------------------------------------------------------------------------

class Variable {
public:
    string name;
    double value;
    bool constant;
};

//------------------------------------------------------------------------------

class Symbol_table {
// Тип для var_table и связанных функций
    vector<Variable> var_table;                         // Вектор переменных
public:
    double get(string s);                               // Возвращает значение переменной s
    void set(string s, double d);                       // Устанавливает переменную s в d
    bool is_declared(string s);                         // s уже в var_table?
    void declare(string s, double d, bool c);           // Добавляет (s,d) в var_table
    void print();
};

//------------------------------------------------------------------------------

double Symbol_table::get(string s)
// Возвращает значение переменной s
{
    for (const Variable& v : var_table)
        if (v.name == s) return v.value;
    error("get: неопределённая переменная ", s);

    return 0;
}

//------------------------------------------------------------------------------

void Symbol_table::set(string s, double d)
// Устанавливает переменную s в d
{
    for (Variable& v : var_table)
        if (v.name == s) {
            if (v.constant) error(s, " константа");
            v.value = d;
            return;
        }

    error("set: неопределённая переменная ", s);
}

//------------------------------------------------------------------------------

bool Symbol_table::is_declared(string s)
// s уже в var_table?
{
    for (const Variable& v : var_table)
        if (v.name == s) return true;
    return false;
}

//------------------------------------------------------------------------------

void Symbol_table::declare(string s, double d, bool c)
// Добавить (s,d) в var_table
{
    // Это можно рассматривать, как избыточность с declaration(), выполняющим ту же проверку.
    // Но переменные и константы объявляются прямо в главном теле.
    if (is_declared(s)) error(s, "повторное объявление");
    var_table.push_back(Variable{s, d, c});
}

//------------------------------------------------------------------------------

void Symbol_table::print()
{
    for (Variable v : var_table) {
        cout << v.name << " = " << v.value;
        if (v.constant) cout << " (constant)";
        cout << '\n';
    }
}

//------------------------------------------------------------------------------

Symbol_table symbols;                                   // обеспечивает get(), set(), is_declared() и declare()

//------------------------------------------------------------------------------

Token_stream ts{cin};                                   // обеспечивает get() и unget()

//------------------------------------------------------------------------------

double expression();                                    // Декларируется так, чтобы primary() мог вызывать expression()

//------------------------------------------------------------------------------

double eval_function(char c)
// Оценивает функцию вида c. Следующим на входе должено быть "("Expression")".
{
    vector<double> args;                                // Вектор для хранения (variable number) аргументов функции
    Token t = ts.get();
    if (t.kind != '(') error("'(' ожидается после вызова функции");

    // Обработка списка аргументов. По умолчанию: нет аргументов, ничего не делать.
    // Так нет default для инструкции switch.
    switch (c) {
        case sqrtfun:
            args.push_back(expression());
            break;
        case powfun:
            args.push_back(expression());
            t = ts.get();
            if (t.kind != ',') error("Недостаточное количество аргументов функции");
            args.push_back(expression());
            break;
    }

    t = ts.get();
    if (t.kind != ')') error("Недостаточное количество аргументов функции");

    // Оценка и ограничения реализации
    switch (c) {
        case sqrtfun:
            if (args[0] < 0) error("sqrt() не определена для отрицательных чисел");
            return sqrt(args[0]);
        case powfun:
            return pow(args[0], narrow_cast<int>(args[1]));
        default:
            // В случае, если определили имя, как токен для правила функции (Function),
            // но забыли осуществить свою оценку
            error("Функция не реализована");
    }

    return 0;
}

//------------------------------------------------------------------------------

double primary()
// Для работы с числами и круглыми скобками
// Вызывает expression()
{
    Token t = ts.get();
    switch (t.kind) {
        case '(':                                       // Обработка правила '(' Выражение ')'
        {	double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' требуется");
            return d;
        }
        case '-':                                       // Числа с отрицательным знаком
            return - primary();
        case '+':                                       // Числа с положительным знаком
            return primary();
        case number:
            return t.value;                             // Возвращает значение числа
        case name:                                      // Переменная: получить значение из таблицы
            return symbols.get(t.name);
        case sqrtfun:
        case powfun:
            // Вызов eval_function t.kind, чтобы схлопнуть оценку отдельных функций на одной линии
            return eval_function(t.kind);
        default:
            error("Ожидается первичное выражение");
    }

    return 0;
}

//------------------------------------------------------------------------------

double term()
// Для работы с *, / и %
// Вызывает primary()
{
    double left = primary();
    while(true) {
        Token t = ts.get();                             // Получает следующий токен из потока токенов
        switch(t.kind) {
            case '*':
                left *= primary();
                break;
            case '/':
            {	double d = primary();
                if (d == 0) error("деление на нуль");
                left /= d;
                break;
            }
            case '%':
            {   double d = primary();
                if (d == 0) error("%: деление на нуль");
                left = fmod(left, d);
                break;
            }
            default:
                ts.putback(t);                          // Помещает t обратно в поток токенов
                return left;
        }
    }
}

//------------------------------------------------------------------------------

double expression()
// Для работы с + and -
// Вызывает term()
{
    double left = term();                               // Читает и оценивает Term
    while(true) {
        Token t = ts.get();                             // Получает следующий токен из потока токенов
        switch(t.kind) {
            case '+':
                left += term();                         // Оценивает Term и складывает
                break;
            case '-':
                left -= term();                         // Оценивает Term и вычитает
                break;
            default:
                ts.putback(t);                          // Помещает t обратно в поток токенов
                return left;                            // Окончательно: нет + или -: возвращает ответ
        }
    }
}

//------------------------------------------------------------------------------

double assignment()
{
    // Имя и '=' идут дальше.
    Token t = ts.get();
    string var_name = t.name;
    if (!symbols.is_declared(var_name)) error(var_name, " не было объявлено");

    ts.get(); // Избавляемся от '='
    double d = expression();
    symbols.set(var_name, d);
    return d;
}

//------------------------------------------------------------------------------

double declaration()
// Считаем, что мы уже встретили ключевое слово "let"
// Обрабатываем: Имя = Выражение
// Объявление переменной с Именем с начальным значением, заданным Выражением
// k будет "let" или "con"(stant)
{
    // Получить объявление ключевого слова токена, чтобы определить, является ли оно постоянным или нет.
    Token t = ts.get();

    // Проверить по частям правила декларации правила грамматики за «let» или «const».
    Token t2 = ts.get();
    if (t2.kind != name) error ("в объявлении ожидается имя переменной");
    string var_name = t2.name;
    if (symbols.is_declared(var_name)) error(var_name, " объявлен дважды");

    Token t3 = ts.get();
    if (t3.kind != '=') error("пропущен символ = в объявлении " ,var_name);

    double d = expression();
    symbols.declare(var_name, d, t.kind == constant);
    return d;
}

//------------------------------------------------------------------------------

double statement()
// Обрабатывает объявления и выражения
{
    Token t = ts.get();
    switch(t.kind) {
        case let:
        case constant:
            ts.putback(t);
            return declaration();
        case name:
        {
            Token t2 = ts.get();
            // Какой бы ни был t2, мы должны откатить
            ts.putback(t2);
            ts.putback(t);
            if (t2.kind == '=') {
                return assignment();
            }
            return expression();
        }
        default:
            ts.putback(t);
            return expression();
    }
}

//------------------------------------------------------------------------------

void clean_up_mess()
// Очистка ввода после ошибки
{
    ts.ignore(print);                               // Отбросить ввод до команды печати или новой строки (включительно).
}

//------------------------------------------------------------------------------

const string prompt = "> ";
const string result = "= ";

//------------------------------------------------------------------------------

void print_help()
{
    cout << "\n\tСправка и инструкции к простому калькулятору.\n"
            "\n\tОСНОВНОЙ СИНТАКСИС\n\n"
            "\tЗавершите выражение с ; или переходом на новую строку для вывода результатов.\n"
            "\tПоддерживаемые операции: *, /, %, +, -, = (назначение).\n"
            "\tВы можете использовать скобки для определения порядка вычисления: 4*(2+3).\n"
            "\n\tКОМАНДЫ\n\n"
            "\thelp     Выводит данное справочное сообщение.\n"
            "\tsymbols  Выводит объявленные в настоящее время переменные и константы.\n"
            "\tquit     Выход из программы.\n"
            "\n\tФУНКЦИИ\n\n"
            "\tsqrt(n)    Квадратный корень из числа n.\n"
            "\tpow(n,e)   Возводит значение n в степень e, где e целое число.\n"
            "\n\tПЕРЕМЕННЫЕ\n\n"
            "\tИмена переменных должны состоять из буквенно-цифровых символов и знака '_'\n"
            "\tи должны начинаться с алфавитного символа.\n\n"
            "\tlet var = expr     Объявляет переменную var и инициализирует её\n\n"
            "\t                   с вычисленным значением выражения expr.\n\n"
            "\tconst var = expr   Объявляет и инициализирует константу с именем var.\n\n"
            "\tvar = expr         Назначает новое значение ранее объявленной переменной.\n\n"
            "\tПредопределенные переменные:\n"
            "\t\tpi   3.14159265359 (константа)\n"
            "\t\te    2.71828182846 (константа)\n"
            "\t\tk    1000\n\n";
}

//------------------------------------------------------------------------------

void calculate()
// Цикл вычисления выражения
{
    while(true)
        try {
            cout << prompt;                             // Вывод приглашения "> "
            Token t = ts.get();
            while (t.kind == print) t = ts.get();       // Отбрасывание команд вывода
            if (t.kind == command) {
                if (t.name == quitkey) return;          // Выход
                if (t.name == helpkey) print_help();    // Вывод инструкций помощи
                if (t.name == symkey) symbols.print();
                ts.ignore(print);                       // Игнорирование чего-либо после команды
            }
            else {
                ts.putback(t);
                cout << result << statement() << '\n';  // Вывод результатов
            }
        }
        catch(exception& e) {
            cerr << e.what() << '\n';                   // Вывод сообщения об ошибке
            clean_up_mess();                            // Отменить оставшийся ввод и снова запросить пользователя
        }
}

//------------------------------------------------------------------------------

int main()
try {
    // Предопределенные переменные
    symbols.declare("k", 1000, false);
    // Предопределенные константы
    symbols.declare("pi", 3.14159265359, true);
    symbols.declare("e", 2.71828182846, true);

    cout << "Простой калькулятор. Для получения справки введите help.\n";
    calculate();
    return 0;
}
catch (exception& e) {
    cerr << "исключение: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Неизвестное исключение!\n";
    return 2;
}