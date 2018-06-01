// 6. Write a program that converts from Celsius to Fahrenheit and from Fahrenheit to Celsius (formula in §4.3.3). Use
// estimation (§5.8) to see if your results are plausible.
#include "std_lib_facilities.h"

double ctof(double dc);
double ftoc(double df);

int main()
{
    double t = 0;
    string a;
    cout << "Введите температуру по Фаренгейту (°F) или по Цельсию (°С):" << endl;
    cin >> t >> a;
    for (int i = 0; i < a.length(); i++) {
        a[i] = toupper(a[i]);
    }
    if (a == "°С") {
        t = ctof(t);
        cout << t << "°F" << '\n';
    }
    else if (a == "°F") {
        t = ftoc(t);
        cout << t << "°С" << '\n';
    }
    else error("Недопустимая единица измерения");

    return 0;
}

double ctof(double dc)          // Преобразование температуры по Цельсию в температуру по Фаренгейту
{
    if (dc < -273.15) error("Температура ниже абсолютного нуля -273.15 °С");
    double df = 9.0/5*dc+32;
    return df;
}

double ftoc(double df)          // Преобразование температуры по Фаренгейту в температуру по Цельсию
{
    if (df < -459.67) error("Температура ниже абсолютного нуля -459.67 °F");
    double dc = (df-32)*5/9;
    return dc;
}