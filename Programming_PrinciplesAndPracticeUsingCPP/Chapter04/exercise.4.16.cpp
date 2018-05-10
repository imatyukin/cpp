// 16. In the drill, you wrote a program that, given a series of numbers, found the max and min of that series. The
// number that appears the most times in a sequence is called the mode. Create a program that finds the mode of a set of
// positive integers.
#include "std_lib_facilities.h"
#include <random>

int main() {
    mt19937 gen { random_device()() };
    uniform_int_distribution<int> uid(0, 9);
    const size_t N = 20;
    vector<int> v(N);
    // генерируем 20 СЧ
    generate(v.begin(), v.begin() + N, [&uid, &gen]() -> int
        { return uid(gen); } );
    // выводим содержимое вектора на экран
    copy(v.begin(), v.begin() + N, ostream_iterator<int> (cout, " ") );
    auto mm = minmax_element(v.begin(), v.begin() + N);
    cout << "\nМинимум: " << *mm.first << "\nMаксимум: " << *mm.second << endl;

    vector<int> vmode(N);
    int mode = 0;
    int max = vmode[0];

    for (int i = 0; i < v.size(); ++i)
        vmode[v[i]]++;

    for (int i = 0; i < N; ++i)
        if(vmode[i] > max) {
            max = vmode[i];
            mode = i;
        }

    cout << "Мода: " << mode << "\nКоличество повторений: " << max << endl;
}
