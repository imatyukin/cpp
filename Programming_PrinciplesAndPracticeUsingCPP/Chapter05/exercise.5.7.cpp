// 7. Quadratic equations are of the form
// a · x2 + b · x + c = 0
// To solve these, one uses the quadratic formula:
// x = -b ± √(b2 - 4ac) / 2a
// There is a problem, though: if b2–4ac is less than zero, then it will fail. Write a program that can calculate x for
// a quadratic equation. Create a function that prints out the roots of a quadratic equation, given a, b, c. When the
// program detects an equation with no real roots, have it print out a message. How do you know that your results are
// plausible? Can you check that they are correct?
#include "std_lib_facilities.h"

double solutions(double a, double b, double c);

int main()
{
    double a, b, c = 0;
    cout << "Введите коэффициенты квадратного уравнения a, b и c, причем a ≠ 0:" << endl;
    cin >> a >> b >> c;
    solutions(a, b, c);

    return 0;
}

double solutions(double a, double b, double c)
{
    double D = 0;

    if (a == 0) error("a не может быть равно 0.");
    cout << "Уравнение " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    D = pow(b, 2) - 4 * a * c;  // Discriminant
    if (D < 0) error("Уравнение не имеет решений в действительных числах.");
    else if (D == 0)
        cout << "x = " << (-b / (2 * a)) << endl;
    else {
        cout << "x1 = " << ((-b + sqrt(D)) / (2 * a)) << endl;
        cout << "x2 = " << ((-b - sqrt(D)) / (2 * a)) << endl;
    }

    return 0;
}
