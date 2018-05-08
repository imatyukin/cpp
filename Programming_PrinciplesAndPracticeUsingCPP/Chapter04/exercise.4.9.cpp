// 9. Try to calculate the number of rice grains that the inventor asked for in exercise 8 above. You’ll find that the
// number is so large that it won’t fit in an int or a double. Observe what happens when the number gets too large to
// represent exactly as an int and as a double. What is the largest number of squares for which you can calculate the
// exact number of grains (using an int)? What is the largest number of squares for which you can calculate the
// approximate number of grains (using a double)?
#include "std_lib_facilities.h"

int main() {
    int square = 2;             // текущий номер клетки
    double grains_cur = 1;      // количество зерен в текущей клетке
    double grains_all_prev = 0; // количество зерен во всех предыдущих клетках

    cout << "Текущий номер клетки 1" << endl;
    cout << "Количество зерен в текущей клетке 1" << endl;
    while (square <= 64) {
        cout << "Текущий номер клетки " << square++ << endl;
        cout << "Количество зерен во всех предыдущих клетках " << (grains_all_prev += grains_cur) << endl;
        cout << "Количество зерен в текущей клетке " << (grains_cur *= 2) << endl;
        cout << "Количество зерен во всех клетках " << (grains_all_prev+grains_cur) << endl;
    }
}
