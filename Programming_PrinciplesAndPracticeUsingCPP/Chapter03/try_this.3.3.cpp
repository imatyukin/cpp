// Get the “name and age” example to run. Then, modify it to write out the age in months: read the input in years and
// multiply (using the * operator) by 12. Read the age into a double to allow for children who can be very proud of
// being five and a half years old rather than just five.
#include "std_lib_facilities.h"

int main()
{
    cout << "Пожалуйста, введите своё имя и возраст:\n";
    string first_name = "???"; // string variable
                               // ("???" means "don't know the name")
    double age = -1;              // integer variable (-1 means "don't know the age")
    cin >> first_name >> age;  // read a string followed by an integer
    age = age * 12;
    cout << "Привет, " << first_name << " (возраст в месяцах " << age << ")\n";
}
