// 14. Modify the program described in the previous exercise to take an input value max and then find all prime numbers
// from 1 to max.
#include "std_lib_facilities.h"

int main() {
    int max;
    cout << "Введите максимальное значение: " << endl;
    cin >> max;
    vector<int> primes(max + 1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i <= max; ++i)
        if (primes[i])
            if (i * 1ll * i <= max)
                for (int j = i * i; j <= max; j += i)
                    primes[j] = false;

    for (int i = 2; i <= primes.size(); ++i) {
        if (primes[i]) {
            primes[i] = i;
            cout << primes[i] << " ";
        }
    }
}
