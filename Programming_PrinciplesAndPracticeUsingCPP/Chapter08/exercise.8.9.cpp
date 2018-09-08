// 9. Write a function maxv() that returns the largest element of a vector argument.

#include "std_lib_facilities.h"
#include <random>
#include <tuple>

const size_t N = 50;

tuple<int, int> maxv(const vector<int>& v) {
    auto mm = minmax_element(v.begin(), v.begin() + N);

    return {*mm.first, *mm.second};
}

int main()
try
{
    // создаем ГПСЧ random_device
    mt19937 gen { random_device()() };
    // создаем распределение uid, инициализируя его начальными значениями
    uniform_int_distribution<int> uid(0, 100);
    vector<int> v(N);
    // генерируем 50 СЧ
    generate(v.begin(), v.begin() + N, [&uid, &gen]() -> int
    { return uid(gen); } );
    // выводим содержимое вектора на экран
    copy(v.begin(), v.begin() + N, ostream_iterator<int> (cout, " ") );
    // находим максимальный и минимальный элементы вектора СЧ
    auto [min, max] = maxv(v);
    cout << "\nMin: " << min << "\nMax: " << max << endl;
}
catch (runtime_error e) {
    cout << e.what() << '\n';
}
catch (...) {
    cout << "exiting\n";
}