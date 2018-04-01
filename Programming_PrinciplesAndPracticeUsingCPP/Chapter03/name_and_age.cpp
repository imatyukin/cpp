// read name and age
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
