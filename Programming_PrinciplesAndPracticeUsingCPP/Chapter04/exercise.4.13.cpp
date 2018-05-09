// 13. Create a program to find all the prime numbers between 1 and 100. There is a classic method for doing this,
// called the “Sieve of Eratosthenes.” If you don’t know that method, get on the web and look it up. Write your program
// using this method.
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
