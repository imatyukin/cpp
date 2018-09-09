// 9. Write a function maxv() that returns the largest element of a vector argument.
// 10. Write a function that finds the smallest and the largest element of a vector argument and also computes the mean
// and the median. Do not use global variables. Either return a struct containing the results or pass them back through
// reference arguments. Which of the two ways of returning several result values do you prefer and why?

#include "std_lib_facilities.h"
#include <random>
#include <tuple>

using namespace std;

tuple<int, int, double, int> vMinMaxAvgMed(vector<int> v, int N) {
    const auto size = distance(v.begin(), v.end());
    nth_element(v.begin(), v.begin() + size / 2, v.end());
    auto mm = minmax_element(v.begin(), v.begin() + N);
    auto avg = 1.0 * accumulate(v.begin(), v.end(), 0LL) / size;

    return {*mm.first, *mm.second, avg, *next(v.begin(), size / 2)};
}

int main()
try
{
    // создаем ГПСЧ random_device
    mt19937 gen { random_device()() };
    // создаем распределение uid, инициализируя его начальными значениями
    uniform_int_distribution<int> uid(0, 100);
    const size_t N = 50;
    vector<int> v(N);
    // генерируем 50 СЧ
    generate(v.begin(), v.begin() + N, [&uid, &gen]() -> int
    { return uid(gen); } );
    // выводим содержимое вектора на экран
    copy(v.begin(), v.begin() + N, ostream_iterator<int> (cout, " ") );
    // находим наименьший и наибольший элементы вектора СЧ, а также вычисляем среднее и медиану
    auto [min, max, avg, median] = vMinMaxAvgMed(v, N);
    cout << "\nMin:\t" << min << "\nMax:\t" << max << "\nAvg:\t" << avg << "\nMedian:\t" << median << endl;
}
catch (runtime_error e) {
    cout << e.what() << '\n';
}
catch (...) {
    cout << "exiting\n";
}