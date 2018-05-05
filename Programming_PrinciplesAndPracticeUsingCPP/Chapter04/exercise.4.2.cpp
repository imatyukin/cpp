// 2. If we define the median of a sequence as “a number so that exactly as many elements come before it in the
// sequence as come after it,” fix the program in §4.6.3 so that it always prints out a median. Hint: A median need not
// be an element of the sequence.
#include "std_lib_facilities.h"

double nlogn_median(vector<double> list);

int main() {
    vector<double> temps;
    double temp;

    cout << "Введите набор чисел для получения медианы:" << endl;
    while (cin>>temp)
        temps.push_back(temp);

    cout << "Медиана равна " << nlogn_median(temps) << endl;
}

double nlogn_median(vector<double> list) {
    sort(list.begin(), list.end());

    if (list.size() == 0)
        return 0;
    else if (list.size() % 2 == 1)
        // медиана - середина массива при нечётном количестве элементов
        return list[list.size() / 2];
    else
        // медиана - число лежащее между двумя средними элементами набора при чётном количестве элементов
        return 0.5 * (list[list.size() / 2 - 1] + list[list.size() / 2]);
}
