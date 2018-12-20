// 15. Refine the Money class by adding a currency (given as a constructor argument). Accept a floating-point
// initializer as long as it can be exactly represented as a long int. Don’t accept illegal operations. For example,
// Money*Money doesn’t make sense, and USD1.23+DKK5.00 makes sense only if you provide a conversion table defining the
// conversion factor between U.S. dollars (USD) and Danish kroner (DKK).

// 16. Define an input operator (>>) that reads monetary amounts with currency denominations, such as USD1.23 and
// DKK5.00, into a Money variable. Also define a corresponding output operator (>>).

#include "std_lib_facilities.h"

namespace Financial {

// Функция округления double в long int
long int iround(double d)
{
    return (d > 0.0) ? (d + 0.5) : (d - 0.5);
}

// Класс Money для вычислений, точность которых определяется по правилам округления 4/5
// (0,5 округляется вверх; всё, что меньше 0,5, округляется вниз)
class Money {
public:
    // Перечисление Currency
    enum Currency {
        USD, EUR, RUR
    };
    Money() :cents(0), cur(USD) { }
    Money(long int c) :cents(c), cur(USD) { }
    Money(int d, int c) :cents(d*100 + c), cur(USD)
    {
        if (c >= 100) error("cents must be between 0 and 99");
    }
    Money(long int c, Currency cur) :cents(c), cur(cur) { }
    Money(int d, int c, Currency cur)
            :cents(d*100 + c), cur(cur) { }
    int get_dollars() const { return cents/100; }
    int get_cents() const { return cents%100; }
    long int cents;
    Currency cur;
};

// один юнит с2 стоит юнитов с1
double exch_rate(Money::Currency c1, Money::Currency c2)
{
    switch (c1) {
        case Money::USD:
            switch (c2) {
                case Money::EUR:
                    return 1.1395;
                case Money::RUR:
                    return 0.0149;
                default:
                    error("exch_rate: illegal combination of currencies");
            }
        case Money::EUR:
            switch (c2) {
                case Money::USD:
                    return 0.8776;
                case Money::RUR:
                    return 0.0131;
                default:
                    error("exch_rate: illegal combination of currencies");
            }
        case Money::RUR:
            switch (c2) {
                case Money::USD:
                    return 67.1121;
                case Money::EUR:
                    return 76.4742;
                default:
                    error("exch_rate: illegal combination of currencies");
            }
        default:
            error("exch_rate: illegal combination of currencies");
    }
    return 0;
}

// результат в валюте первого слагаемого
Money operator+(const Money& a, const Money& b)
{
    if (a.cur == b.cur) // возвращает ту же валюту
        return Money(a.cents+b.cents,a.cur);

    double d = exch_rate(a.cur,b.cur);

    return Money(a.cents + iround(d*double(b.cents)),a.cur);
}

Money operator-(const Money& a, const Money& b)
{
    if (a.cur == b.cur) // возвращает ту же валюту
        return Money(a.cents-b.cents,a.cur);

    double d = exch_rate(a.cur,b.cur);

    return Money(a.cents - iround(d*double(b.cents)),a.cur);
}

Money operator-(const Money& m)
{
    return Money(-m.cents,m.cur);
}

Money operator*(int n, const Money& m)
{
    return Money(n * m.cents,m.cur);
}

Money operator*(const Money& m, int n)
{
    return n*m;
}

Money operator/(const Money& m, int n)
{
    if (n == 0) error("division by zero");
    double d = double(m.cents) / n;
    long int c = iround(d);
    return Money(c,m.cur);
}

ostream& operator<<(ostream& os, const Money::Currency& cur)
{
    switch (cur) {
        case Money::USD:
            return os << "USD";
        case Money::EUR:
            return os << "EUR";
        case Money::RUR:
            return os << "RUR";
    }
}

ostream& operator<<(ostream& os, const Money& m)
{
    os << m.cur << m.get_dollars() << '.';
    if (abs(m.get_cents()) < 10) os << '0';      // получить $1,01 вместо $1,1
    os << abs(m.get_cents());
    return os;
}

istream& operator>>(istream& is, Money& m)
{
    int d, c;
    string s;
    char ch;
    is >> s >> d >> ch >> c;
    if (!is) return is;
    if (!(s=="USD" || s=="EUR" || s=="RUR") || ch!='.') { // format error
        is.clear(ios_base::failbit);                    // установить бит сбоя
        return is;
    }
    Money::Currency cur;
    if (s=="USD") cur = Money::USD;
    else if (s=="EUR") cur = Money::EUR;
    else if (s=="RUR") cur = Money::RUR;
    else error("illegal currency in input");
    m = Money(d,(c<10)?(10*c):c,cur);   // '123.1' означает '123.10', а не '123.01'
    return is;
}

}; // namespace Financial

using namespace Financial;

int main()
try {
    Money m1;
    Money m2(105);
    Money m3(5,12);

    cout << "m1: " << m1 << endl;
    cout << "m2(105): " << m2 << endl;
    cout << "m3(5,12): " << m3 << endl;
    cout << "-m3: " << -m3 << endl;

    cout << m2 << " + " << m3 << " = " << m2+m3 << endl;
    cout << m2 << " - " << m3 << " = " << m2-m3 << endl;
    cout << "5 * " << m2 << " = " << 5*m2 << endl;
    cout << m2 << " * 5 = " << m2*5 << endl;

    cout << m3 << " - " << m2 << " = " << m3-m2 << endl;

    cout << Money(1,0) << " / 7 = " << Money(1,0)/7 << endl;
    cout << Money(0,9) << " / 6 = " << Money(0,9)/6 << endl << endl;

    m1 = Money(1,12,Money::USD);
    m2 = Money(2,5,Money::EUR);
    m3 = Money(100,50,Money::RUR);
    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;
    cout << "m3 = " << m3 << endl << endl;
    cout << m1 << " + " << m2 << " = " << m1+m2 << endl;
    cout << m1 << " + " << m3 << " = " << m1+m3 << endl;
    cout << m2 << " + " << m1 << " = " << m2+m1 << endl;
    cout << m2 << " + " << m3 << " = " << m2+m3 << endl;
    cout << m3 << " + " << m1 << " = " << m3+m1 << endl;
    cout << m3 << " + " << m2 << " = " << m3+m2 << endl;
    cout << m3 << " - " << m2 << " = " << m3-m2 << endl;
    cout << 3 << " * " << m2 << " = " << 3*m2 << endl;
    cout << m3 << " / " << 17 << " = " << m3/17 << endl;

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}