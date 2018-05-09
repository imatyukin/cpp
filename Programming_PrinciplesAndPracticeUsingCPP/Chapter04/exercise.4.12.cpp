// 12. Modify the program described in the previous exercise to take an input value max and then find all prime numbers
// from 1 to max.
#include "std_lib_facilities.h"

int main() {
    int max;
    cout << "Введите максимальное значение: " << endl;
    cin >> max;
    vector<int> primes;

    primes.push_back(2);
    cout << primes[0] << " ";

    for (int i = 3; i < max; i++) {
        bool prime = true;
        for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++) {
            // Если при каком-то j обнаружится нулевой остаток, значит, i делится на j нацело, и число i составное
            if (i % primes[j] == 0) {
                prime = false;
                break;
            }
        }
        // Если же при делении обнаруживались только ненулевые остатки, значит, число простое
        if (prime) {
            primes.push_back(i);
            cout << i << " ";
        }
    }

    return 0;
}
