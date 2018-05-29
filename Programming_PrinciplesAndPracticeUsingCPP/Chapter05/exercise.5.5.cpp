// 5. Add to the program so that it can also convert from Kelvin to Celsius.
#include "std_lib_facilities.h"

double ktoc(double k)           // Пересчёт в градусы Цельсия
{
    if (k < 0) error("Температура ниже абсолютного нуля 0 K");
    double c = k - 273.15;
    return c;
}

double ctok(double c)           // Пересчёт в Кельвины
{
    if (c < -273.15) error("Температура ниже абсолютного нуля -273.15°С");
    double k = c + 273.15;
    return k;
}

int main()
{
    double t = 0;
    string a;
    cout << "Введите температуру в Кельвинах (K) или градусах Цельсия (°С):" << endl;
    cin >> t >> a;
    for (int i = 0; i < a.length(); i++) {
        a[i] = toupper(a[i]);
    }
    if (a == "K") {
        t = ktoc(t);
        cout << t << "°С" << '\n';
    }
    else if (a == "C" || a == "°С") {
        t = ctok(t);
        cout << t << " K" << '\n';
    }
    else error("Недопустимая единица измерения");

    return 0;
}
