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
    // потребности каждого вида. Таким образом, определены три различных конструктора.
    char kind;                                          // Какого вида лексема
    double value;                                       // Для чисел: значение
    string name;                                        // Для переменных и функций: имя
    // Создаёт Token из char
    Token(char ch)              : kind(ch), value(0) { }
    // Создаёт Token из char и double
    Token(char ch, double val)  : kind{ch}, value{val} { }
    // Создаёт Token из char и string
    Token(char ch, string n)    : kind{ch}, name{n} { }
};

//------------------------------------------------------------------------------

// Моделирует istream как поток токенов
class Token_stream {
public:
    Token_stream();                                     // Создаёт Token_stream, который читает из cin
    Token_stream(istream&);                             // Token_stream, который читает из istream
    Token get();                                        // Получает Token (считывает лексему)
                                                        // (get() определяется в другом месте)
    void putback(Token t);                              // Возвращает Token (лексему) назад в поток
    // Копирует t в буфер
    // Буфер сейчас заполнен
    void ignore(char c);                                // Отбрасывает символы (лексемы) до символа c включительно
private:
    bool full;                                          // Есть Token в буфере?
    Token buffer;                                       // Сохраняем Token возвращённый назад используя putback()
};

// Конструктор
Token_stream::Token_stream()
        :full(false), buffer(0) { }                     // Нет Token в буфере

//------------------------------------------------------------------------------

// Виды токенов (Token kinds) - выбираются произвольно
const char let = 'L';                                   // Лексема декларации let (токен декларации)
const char constant = 'C';                              // Лексема декларации constant (токен констант)
const char command = 'c';                               // Лексема декларации command (токен команд)
const char print = ';';                                 // t.kind==print означает, что t - лексема печати (токен вывода)
const char number = '8';                                // t.kind==number означает, что t - числовая лексема
                                                        // (токен чисел)
const char name = 'a';                                  // Лексема Имя (токен имён)
const char sqrtfunc = 's';                               // Лексема функции вычисления квадратного корня
                                                        // (токен функции вычисления квадратного корня)
const char powfunc = 'p';                                // Лексема функции возведения в степень
                                                        // (токен функции возведения в степень)
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
// Читает символы из cin и составляет токен
{
    if (full) {                                         // Проверка находится ли токен в буфере
        full = false;
        return buffer;
    }

    char ch = ' ';
    cin.get(ch);                                        // cin.get() не пропускает пробелы
    while (isspace(ch)) {
        if (ch == '\n') return Token(print);            // Если обнаружен символ перехода на новую строку,
                                                        // то возвращает токен вывода
        cin.get(ch);
    }

    switch (ch) {
        case ';':                                       // Группируем две альтернативы для вывода
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
            return Token{ch};                           // Эти литералы напрямую определяют тип токена
        case '.':                                       // Литерал с плавающей запятой может начинаться с точки
        // Числовые литералы:
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);                            // Возврат цифры во входной поток
            double val;
            cin >> val;                                 // Чтение числа с плавающей запятой
            return Token{number, val};
        }
        default:
            // Возможно ожидать строки. Это ключевые слова для деклараций, выхода из программы и имён переменных.
            if (isalpha(ch)) {                          // Начало с буквы
                string s;
                s += ch;
                // Буквы, цифры и символы подчёркивания
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
                cin.putback(ch);
                if (s == declkey) return Token{let};                // Ключевое слово объявления "let"
                if (s == constkey) return Token{constant};          // Ключевое слово объявления "const"
                if (s == quitkey) return Token{command, quitkey};   // Ключевое слово выхода
                if (s == helpkey) return Token{command, helpkey};   // Ключевое слово помощи
                if (s == symkey) return Token{command, symkey};     // Ключевое слово вывода объявленных в настоящее
                                                                    // время переменных и констант.
                if (s == sqrtkey) return Token{sqrtfunc};            // Ключевое слово функции вычисления
                                                                    // квадратного корня
                if (s == powkey) return Token{powfunc};              // Ключевое слово функции возведения в степень
                return Token{name,s};
            }
            error("Неверная лексема");
    }

    return 0;
}

//------------------------------------------------------------------------------

void Token_stream::putback(Token t)
// Помещает токен обратно в поток токенов
{
    if (full) error("putback() в заполненый буфер");
    buffer = t;                                         // копирует t в буфер
    full = true;                                        // буфер сейчас заполнен
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
// Игнорирует токены определённого вида
// c представляет вид токена
{
    // Первый взгляд в буфер
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // Теперь поиск ввода:
    char ch = 0;
    while (cin>>ch)
        if (ch==c) return;
}

//------------------------------------------------------------------------------

class Variable {
// тип для пар (имя, значение)
public:
    string name;
    double value;
    bool is_const;
    Variable(string n, double v, bool b) :name(n), value(v), is_const(b) { }
};

//------------------------------------------------------------------------------

class Symbol_table {
// Тип для var_table и связанных функций
public:
    double get(string s);                               // Возвращает значение переменной s
    void set(string s, double d);                       // Устанавливает переменную с именем s в d
    bool is_declared(string var);                       // Проверяет находится ли var в var_table
    double declare(string var, double val, bool b);     // Добавляет (var,val) в var_table
    void print();
private:
    vector<Variable> var_table;                         // Вектор переменных
};

//------------------------------------------------------------------------------

double Symbol_table::get(string s)
// Возвращает значение переменной s
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == s) return var_table[i].value;
    error("get: неопределённая переменная ", s);

    return 0;
}

//------------------------------------------------------------------------------

void Symbol_table::set(string s, double d)
// Устанавливает переменную s в d
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == s) {
            if (var_table[i].is_const) error(s," константа");
            var_table[i].value = d;
            return;
        }

    error("set: неопределённая переменная ", s);
}

//------------------------------------------------------------------------------

bool Symbol_table::is_declared(string var)
// Проверяет нахождение s в var_table
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == var) return true;
    return false;
}

//------------------------------------------------------------------------------

double Symbol_table::declare(string var, double val, bool b)
// Добавляет (var,val) в var_table
{
    if (is_declared(var)) error(var," объявляется дважды");
    var_table.push_back(Variable(var,val,b));
    return val;
}

//------------------------------------------------------------------------------

void Symbol_table::print()
{
    for (Variable v : var_table) {
        cout << v.name << " = " << v.value;
        if (v.is_const) cout << " (constant)";
        cout << '\n';
    }
}

//------------------------------------------------------------------------------

Symbol_table st;                                        // обеспечивает get(), set(), is_declared() и declare()

//------------------------------------------------------------------------------

double expression(Token_stream& ts);                    // Декларируется так, чтобы primary() мог вызывать expression()

//------------------------------------------------------------------------------

double eval_function(char c)
// Вычисляет функцию вида c. Следующим на входе должено быть "("Выражение")".
{
    Token_stream ts;

    vector<double> args;                                // Вектор для сохранения аргументов функции (переменное число)
    Token t = ts.get();
    if (t.kind != '(') error("'(' требуется после вызова функции");

    // Обработка списка аргументов. По умолчанию: нет аргументов, ничего не делать (для оператора switch нет default)
    switch (c) {
        case sqrtfunc:
            args.push_back(expression(ts));
            break;
        case powfunc:
            args.push_back(expression(ts));
            t = ts.get();
            if (t.kind != ',') error("Неправильное количество аргументов функции");
            args.push_back(expression(ts));
            break;
    }

    t = ts.get();
    if (t.kind != ')') error("Неправильное количество аргументов функции");

    // Вычисление и ограничения реализации
    switch (c) {
        case sqrtfunc:
            if (args[0] < 0) error("sqrt() не определённо для отрицательных чисел");
            return sqrt(args[0]);
        case powfunc:
            return pow(args[0], narrow_cast<int>(args[1]));
        default:
            // В случае, если определили имя, как токен для правила функции,
            // но забыли реализовать вычисление функции
            error("Функция не реализована");
    }

    return 0;
}

//------------------------------------------------------------------------------

double primary(Token_stream& ts)
// Обработка чисел, унарных +/-, скобок, вычисление квадратного корня, возведение в степень, работа с именами
// и назначениями
// Вызывает expression()
{
    Token t = ts.get();
    switch (t.kind) {
        case '(':                                       // Обработка правила "("Выражение")"
        {	double d = expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' требуется");
            return d;
        }
        case '-':                                       // Числа с отрицательным знаком
            return - primary(ts);
        case '+':                                       // Числа с положительным знаком
            return primary(ts);
        case number:
            return t.value;                             // Возвращает значение числа
        case name:                                      // Переменная: получает значение из таблицы
        {   Token t2 = ts.get();                        // Проверяет следующий токен
            if (t2.kind == '=') {                       // Обработка правила Имя "=" Выражение
                double d = expression(ts);
                st.set(t.name,d);
                return d;
            }
            else {                                      // Не назначено
                ts.putback(t2);
                return st.get(t.name);
            }
        }
        case sqrtfunc:                                  // Обработка правила "sqrt(" Выражение ")"
        case powfunc:                                   // Обработка правила "pow(" Выражение ")"
            // Вызывает eval_function() для свертывания вычисления различных функций в одном месте
            return eval_function(t.kind);
        default:
            error("Ожидается первичное выражение");
    }

    return 0;
}

//------------------------------------------------------------------------------

double term(Token_stream& ts)
// Обработка *, / и %
// Вызывает primary()
{
    double left = primary(ts);
    while(true) {
        Token t = ts.get();                             // Получает следующий токен из Token_stream
        switch(t.kind) {
            case '*':
                left *= primary(ts);
                break;
            case '/':
            {	double d = primary(ts);
                if (d == 0) error("деление на нуль");
                left /= d;
                break;
            }
            case '%':
            {   double d = primary(ts);
                if (d == 0) error("%: деление на нуль");
                left = fmod(left, d);
                break;
            }
            default:
                ts.putback(t);                          // Помещает t обратно в Token_stream
                return left;
        }
    }
}

//------------------------------------------------------------------------------

double expression(Token_stream& ts)
// Обработка + and -
// Вызывает term()
{
    double left = term(ts);                             // Читает и вычисляет Term
    while(true) {
        Token t = ts.get();                             // Получает следующий токен из потока токенов
        switch(t.kind) {
            case '+':
                left += term(ts);                       // Вычисляет Term и складывает
                break;
            case '-':
                left -= term(ts);                       // Вычисляет Term и вычитает
                break;
            case '=':
                error("использование '=' вне декларации");
            default:
                ts.putback(t);                          // Помещает t обратно в поток токенов
                return left;                            // Окончательно: нет + или -; возвращает ответ
        }
    }
}

//------------------------------------------------------------------------------

double declaration(bool b, Token_stream& ts)
// Обработка: Имя "=" Выражение
// Объявление переменной названной "name" с начальным значением "expression"
{
    Token t = ts.get();
    if (t.kind != name) error("в объявлении требуется имя переменной");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("пропущен символ = в объявлении " ,var_name);

    double d = expression(ts);
    st.declare(var_name,d,b);
    return d;
}

//------------------------------------------------------------------------------

double statement(Token_stream& ts)
// Обработка объявлений и выражений
{
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration(false,ts);
        case constant:
            return declaration(true,ts);
        default:
            ts.putback(t);
            return expression(ts);
    }
}

//------------------------------------------------------------------------------

void clean_up_mess(Token_stream& ts)
// Очистка ввода после ошибки
{
    ts.ignore(print);                                   // Сбросить ввод до команды вывода
                                                        // или символа новой строки (включительно).
}

//------------------------------------------------------------------------------

const string prompt = "> ";
const string result = "= ";                             // используется для обозначения, что далее следует результат

//------------------------------------------------------------------------------

void print_help()
// Вывод инструкций помощи
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
    Token_stream ts;
    while(true)
        try {
            cout << prompt;                             // Вывод приглашения "> "
            Token t = ts.get();
            while (t.kind == print) t = ts.get();       // Отбрасывание всех команд вывода
            if (t.kind == command) {
                if (t.name == quitkey) return;          // Выход
                if (t.name == helpkey) print_help();    // Вывод инструкций помощи
                if (t.name == symkey) st.print();       // Вывод объявленных в настоящее время переменных и констант
                ts.ignore(print);                       // Игнорирование чего-либо после команды
            }
            else {
                ts.putback(t);
                cout << result << statement(ts) << endl;    // Вывод результата
            }
        }
        catch(exception& e) {
            cerr << e.what() << '\n';                   // Написать сообщение об ошибке
            clean_up_mess(ts);                          // Отменить оставшийся ввод и снова запросить пользователя
        }
}

//------------------------------------------------------------------------------

int main()
try {
    // Предопределенные переменные
    st.declare("k", 1000, false);
    // Предопределенные константы
    st.declare("pi", 3.14159265359, true);
    st.declare("e", 2.71828182846, true);

    cout << "Простой калькулятор. Для получения справки введите help.\n";
    calculate();
    return 0;
}
catch (exception& e) {
    cerr << "исключение: " << e.what() << endl;
    char c;
    while (cin>>c && c!=';');
    return 1;
}
catch (...) {
    cerr << "Неизвестное исключение!\n";
    char c;
    while (cin>>c && c!=';');
    return 2;
}