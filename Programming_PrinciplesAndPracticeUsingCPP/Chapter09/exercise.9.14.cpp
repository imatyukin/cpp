// Chapter 9 Exercise 14

// 14. Design and implement a Money class for calculations involving dollars and cents where arithmetic has to be
// accurate to the last cent using the 4/5 rounding rule (.5 of a cent rounds up; anything less than .5 rounds down).
// Represent a monetary amount as a number of cents in a long int, but input and output as dollars and cents, e.g.,
// $123.45. Do not worry about amounts that don’t fit into a long int.

#include "std_lib_facilities.h"

constexpr char currency{'$'};

// Функция округления double в long int
long int round_d_to_li(double d)
{
    return (d > 0.0) ? (d + 0.5) : (d - 0.5);
}

// Класс Money для вычислений, связанных с долларами и центами, точность которых определяется по правилам округления 4/5
// (0,5 цента округляется вверх; всё, что меньше 0,5, округляется вниз)
class Money {
public:
    class Division_by_zero { };                         // пользовательское исключение

    Money(long int dollars, long int cents);            // конструктор в долларах и центах
    Money(long int amount);                             // конструктор на сумму в центах
    Money();                                            // конструктор по умолчанию, количество 0

    long int amount() const { return c_amount; };
    long int dollars() const { return c_amount/100; };  // извлечение долларов
    long int cents() const { return c_amount%100; };
private:
    long int c_amount;                                  // количество денег в центах
};

Money::Money(long int dollars, long int cents) : c_amount{dollars*100+cents} { };
Money::Money(long int amount) : c_amount{amount} { };
Money::Money() : c_amount{0} { };

Money operator+(const Money& a, const Money& b)
{
    return Money{a.amount()+b.amount()};
}

Money operator-(const Money& a, const Money& b)
{
    return Money{a.amount()-b.amount()};
}

Money operator-(const Money& b)
{
    return Money{-b.amount()};
}

Money operator*(const Money& a, double b)
{
    return Money{ round_d_to_li(a.amount()*b) };
}

Money operator*(double a, const Money& b)
{
    return Money{ round_d_to_li(a*b.amount()) };
}

Money operator/(const Money& a, double b)
{
    if (b == 0) throw Money::Division_by_zero{};

    return Money{ round_d_to_li(a.amount()/b) };
}

double operator/(const Money& a, const Money& b)
{
    if (b.amount() == 0) throw Money::Division_by_zero{};

    return (double(a.amount())/b.amount());
}

bool operator==(const Money& a, const Money& b)
{
    return (a.amount() == b.amount());
}

bool operator!=(const Money& a, const Money& b)
{
    return (a.amount() != b.amount());
}

ostream& operator<<(ostream& os, const Money& money)
{
    os << currency << money.dollars() << '.';
    if (abs(money.cents()) < 10) os << '0';             // получить $1,01 вместо $1,1
    os << abs(money.cents());

    return os;
}

istream& operator>>(istream& is, Money& money)
{
    long int dollars{0};
    char cur, dot;
    char d, u;

    is >> cur >> dollars >> dot >> d >> u;
    if (!is) return is;
    if (cur != currency || dot != '.' || !isdigit(d) || !isdigit(u)) {
        is.clear(ios_base::failbit);                    // установить бит сбоя
        return is;
    }

    int cents{(d-'0')*10+(u-'0')};

    if (dollars < 0) cents = -cents;
    money = Money{(dollars*100)+cents};

    return is;
}

int main()
try{

    Money m1;
    Money m2(101);
    Money m3(1,23);

    cout << "m1: " << m1 << endl;
    cout << "m2(101): " << m2 << endl;
    cout << "m3(1,23): " << m3 << endl;
    cout << "-m3: " << -m3 << endl;

    cout << m2 << " + " << m3 << " = " << m2+m3 << endl;
    cout << m2 << " - " << m3 << " = " << m2-m3 << endl;
    cout << "2 * " << m2 << " = " << 2*m2 << endl;
    cout << m2 << " * 2 = " << m2*2 << endl;

    cout << m3 << " - " << m2 << " = " << m3-m2 << endl;

    cout << Money(1,0) << " / 7 = " << Money(1,0)/7 << endl;
    cout << Money(0,9) << " / 6 = " << Money(0,9)/6 << endl << endl;

    return 0;
}
catch(Money::Division_by_zero& e)
{
    cerr << "Money class: division by zero\n";
    return 1;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 2;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 3;
}