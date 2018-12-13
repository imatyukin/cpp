// Chapter 9 Exercise 13
//
// 13. Design and implement a rational number class, Rational. A rational number has two parts: a numerator and a
// denominator, for example, 5/6 (five-sixths, also known as approximately .83333). Look up the definition if you need
// to. Provide assignment, addition, subtraction, multiplication, division, and equality operators. Also, provide a
// conversion to double. Why would people want to use a Rational class?

#include "std_lib_facilities.h"

/*
	A rational number is represented by a numerator and a denominator. Its value is numerator/denominator.
*/

int gcd(int x, int y)
// greatest common denominator
// Euclid's algorithm (using remainder)
{
    x = abs(x);	// don't get confused by negative values
    y = abs(y);
    while (y) {
        int t = y;
        y = x%y;
        x = t;
    }
    return x;
}

//--- the class ----------------------------------------------------------------

class Rational {
public:
    Rational(int n, int d) :num(n), den(d) { normalize(); }
    // Rational(int n) :num(n), den(1) { }	// deleted because I kept writing things like Rational(24/8)
    Rational() :num(0), den(1) { }

    void normalize()	// keep denominator positive and minimal
    {
        if (den==0) error("negative denominator");
        if (den<0) { den = -den; num = -num; }
        int n = gcd(num,den);
        if (n>1) { num/=n; den/=n; }
    }

    int num, den;
};

//--- utilities ----------------------------------------------------------------

ostream& operator<<(ostream& os, Rational x)
{
    return cout << '(' << x.num << '/' << x.den << ')';
}

bool operator==(Rational x1, Rational x2)
{
    return x1.num*x2.den==x1.den*x2.num;
}

bool operator!=(Rational x1, Rational x2)
{
    return !(x1==x2);
}

double to_double(Rational x)	// convert to double (to floating point representation)
{
    return double(x.num)/x.den;
}

//----- arithmetic operations --------------------------------------------------------

Rational operator+(Rational x1, Rational x2)
{
    Rational r(x1.num*x2.den+x1.den*x2.num, x1.den*x2.den);
    r.normalize();
    return r;
}

Rational operator-(Rational x1, Rational x2)
{
    Rational r(x1.num*x2.den-x1.den*x2.num, x1.den*x2.den);
    r.normalize();
    return r;
}

Rational operator-(Rational x)	// unary minus
{
    return Rational(-x.num,x.den);
}

Rational operator*(Rational x1, Rational x2)
{
    Rational r(x1.num*x2.num,x1.den*x2.den);
    r.normalize();
    return r;
}

Rational operator/(Rational x1, Rational x2)
{
    Rational r(x1.num*x2.den,x1.den*x2.num);
    r.normalize();
    return r;
}


int main()
try
{
    Rational r1(4,2);
    cout << r1 << "==" << to_double(r1) << '\n';
    Rational r2(42,24);
    cout << r2 << "==" << to_double(r2) <<'\n';
    cout << r1+r2 << "==" << to_double(r1+r2) << "==" << to_double(r1)+to_double(r2) << '\n';
    cout << r1-r2 << "==" << to_double(r1-r2) << "==" << to_double(r1)-to_double(r2) << '\n';
    cout << -r2 << "==" << to_double(-r2) << "==" << -to_double(r2) << '\n';
    cout << r1*r2 << "==" << to_double(r1*r2) << "==" << to_double(r1)*to_double(r2) << '\n';
    cout << r1/r2 << "==" << to_double(r1/r2) << "==" << to_double(r1)/to_double(r2) << '\n';
    if (r2==Rational(14,8)) cout << "equal\n";
    if (r2!=Rational(14,8)) cout << "not equal\n";
    Rational(3,0);	// we're out of here!

}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << e.what() << '\n';
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << "exiting\n";
}

/*
	Why would anyone use rational numbers? Well, floating point is imprecise (e.g. can't represent a third
	exactly) and some things are for good and/or legal reasons required to be exact (e.g. financial calculations).
*/
