// Find a pair of values so that the pre-condition of this version of area holds, but the post-condition doesn’t.
#include "std_lib_facilities.h"

int area(int length, int width);

int main()
{
    cout << area(INT_MAX/2, INT_MAX/2);
}

int area(int length, int width)
// calculate area of a rectangle;
// pre-conditions: length and width are positive
// post-condition: returns a positive value that is the area
{
    if (length<=0 || width <=0) error("area() pre-condition");
    int a = length*width;
    if (a<=0) error("area() post-condition");
    return a;
}
