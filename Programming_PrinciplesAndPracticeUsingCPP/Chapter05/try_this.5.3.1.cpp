// Try to compile those examples and see how the compiler responds.
#include "std_lib_facilities.h"

int area(int length, int width);        // calculate area of a rectangle

int main()
{
    cout << "Площадь прямоугольника равна произведению его сторон (a, b): S = ab" << endl;
    cout << endl;

    int s1 = area(7, 7);        // error: ) missing
    int s2 = area(6, 5);        // error: ; missing
    int s3 = area(3, 4);        // error: Int is not a type
    int s4 = area(2, 1);        // error: non-terminated character (' missing)

    cout << "s1 = " << s1 << "; " << "s2 = " << s2 << "; " << "s3 = " << s3 << "; " << "s4 = " << s4 << "." << endl;

    return 0;
}

int area(int length, int width)
{
    int s = 0;
    s = length * width;
    return s;
}
