// Test this program with a variety of values. Print out the values of area1, area2, area3, and ratio. Insert more tests
// until all errors are caught. How do you know that you caught all errors? This is not a trick question; in this
// particular example you can give a valid argument for having caught all errors.
#include "std_lib_facilities.h"

int area(int length, int width);
int framed_area(int x, int y);
int f(int x, int y, int z);

int main()
{
    f(1, 3, 3);
}

int f(int x, int y, int z)
{
    int area1 = area(x,y);
    if (area1<=0) error("non-positive area");
    // int area2 = framed_area(1,z);            // ERROR -- non-positive area
    int area3 = framed_area(y,z);
    if (area3<=0) error("non-positive area");
    double ratio = double(area1)/area3;

    cout << "area1 = " << area1 << endl;
    cout << "area2 = ERROR -- non-positive area" << endl;
    cout << "area3 = " << area3 << endl;
    cout << "ratio = " << ratio << endl;

    return 0;
}

int area(int length, int width)         // Площадь прямоугольника
{
    if (length<=0 || width<=0) error("Неположительный аргумент функции area()");
    return length*width;
}

int framed_area(int x, int y)           // Площадь в пределах рамки
{
    constexpr int frame_width = 2;
    if (x-frame_width<=0 || y-frame_width<=0)
        error("Неположительный аргумент функции area()"
              " при вызове из функции framed_area()");
    return area(x-frame_width, y-frame_width);
}
