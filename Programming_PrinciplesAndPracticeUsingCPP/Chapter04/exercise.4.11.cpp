// 11. Create a program to find all the prime numbers between 1 and 100. One way to do this is to write a function that
// will check if a number is prime (i.e., see if the number can be divided by a prime number smaller than itself) using
// a vector of primes in order (so that if the vector is called primes, primes[0]==2, primes[1]==3, primes[2]==5, etc.).
// Then write a loop that goes from 1 to 100, checks each number to see if it is a prime, and stores each prime found in
// a vector. Write another loop that lists the primes you found. You might check your result by comparing your vector of
// prime numbers with primes. Consider 2 the first prime.
#include "std_lib_facilities.h"

int main() {
    vector<int> primes;

    primes.push_back(2);
    cout << primes[0] << " ";

    for (int i = 3; i < 100; i++) {
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
