// 18. Write a program to solve quadratic equations. A quadratic equation is of the form
// ax2 + bx + c = 0
// If you don’t know the quadratic formula for solving such an expression, do some research. Remember, researching how
// to solve a problem is often necessary before a programmer can teach the computer how to solve it. Use doubles for the
// user inputs for a, b, and c. Since there are two solutions to a quadratic equation, output both x1 and x2.
#include "std_lib_facilities.h"

int main(){
    double a, b, c = 0;
    double D = 0;
    double x, x1, x2 = 0;

    cout << "Решение квадратного уравнения ax^2 + bx + c = 0." << endl;
    cout << "Введите коэффициенты a, b и c, причем a ≠ 0: " << endl;
    cin >> a >> b >> c;

    cout << "Задача.    Решить уравнение " << a << "x^2 + " << b << "x + " << c << " = 0." << endl;

    cout << "Решение.   Находим дискриминант квадратного уравнения: D = b^2 - 4ac." << endl;
    D = pow(b, 2) - 4 * a * c;

    cout << "   Если D > 0, то уравнение имеет два различных вещественных корня." << endl;
    cout << "   Если D = 0, то оба корня вещественны и равны." << endl;
    cout << "   Если D < 0, то оба корня являются комплексными числами." << endl;

    cout << "D = " << D << endl;

    if (D < 0)
        cout << "Уравнение не имеет решений в действительных числах." << endl;
    else if (D == 0) {
        cout << "Уравнение имеет один корень, который вычисляется по формуле x = frac{-b}{2a}." << endl;
        cout << "x = " << (x = -b / 2 * a) << endl;
    }
    else if (D > 0) {
        cout << "Уравнение имеет два корня, которые вычисляются по формуле x_{1,2} = frac{-b pm sqrt{D}}{2a}." << endl;
        cout << "x1 = " << (x1 = (-b + sqrt(D)) / 2 * a) << endl;
        cout << "x2 = " << (x2 = (-b - sqrt(D)) / 2 * a) << endl;

    }

    return 0;
}
