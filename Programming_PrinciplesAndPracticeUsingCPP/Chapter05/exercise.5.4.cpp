// 4. Do exercise 3 again, but this time handle the error inside ctok().
#include "std_lib_facilities.h"

double ctok(double c)                                       // converts Celsius to Kelvin
{
    if (c < -273.15) error("Температура ниже -273.15°С");
    double k = c + 273.15;
    return k;
}

int main()
{
    double c = 0;                                           // declare input variable
    cin >> c;                                               // retrieve temperature to input variable
    double k = ctok(c);                                     // convert temperature
    cout << k << '\n';                                      // print out temperature
}
