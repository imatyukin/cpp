// 11. Create a program to find all the prime numbers between 1 and 100. One way to do this is to write a function that
// will check if a number is prime (i.e., see if the number can be divided by a prime number smaller than itself) using
// a vector of primes in order (so that if the vector is called primes, primes[0]==2, primes[1]==3, primes[2]==5, etc.).
// Then write a loop that goes from 1 to 100, checks each number to see if it is a prime, and stores each prime found in
// a vector. Write another loop that lists the primes you found. You might check your result by comparing your vector of
// prime numbers with primes. Consider 2 the first prime.
#include "std_lib_facilities.h"

/* Решето Эратосфена — алгоритм, позволяющий найти все простые числа в отрезке [1; n] за O(nloglogn) операций */
int main() {
    // ряд чисел 1 ... n
    int n = 100;
    // помечает все числа, кроме нуля и единицы, как простые
    vector<int> primes(n + 1, true);
    primes[0] = primes[1] = false;
    // процесс отсеивания составных чисел
    for (int i = 2; i <= n; ++i)
        // если текущее число i простое, то помечаем все числа, кратные ему, как составные
        if (primes[i])
            // начинаем идти от i^2, поскольку все меньшие числа, кратные i, обязательно имеют простой делитель меньше i
            if (i * 1ll * i <= n) // i^2 может переполнить тип int, делается проверка с использованием типа long long
                // вычеркива сначала все числа, делящиеся на 2, кроме самого числа 2, затем деляющиеся на 3, кроме
                // самого числа 3, затем на 5, затем на 7, 11, и все остальные простые до n.
                for (int j = i * i; j <= n; j += i)
                    primes[j] = false;

    // преобразовываем найденные простые числа в их значения по индексу вектора
    for (int i = 2; i <= primes.size(); ++i) {
        if (primes[i]) {
            primes[i] = i;
            cout << primes[i] << " ";
        }
    }
}
