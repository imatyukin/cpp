// 15. Write a program that takes an input value n and then finds the first n primes.
#include "std_lib_facilities.h"

int main() {
    int limit;
    cout << "Введите значение для поиска первых n простых чисел: " << endl;
    cin >> limit;

    int startSize = limit;  // стартовый размер массива натуральных чисел
    int addSize = limit;    // размер дополнительного массива натуральных чисел
    vector<bool> nums(startSize);
    vector<int> primeNums(limit);

    int foundPrimes = 0;
    for (int i = 2; i < startSize; i++)
        nums[i] = true;

    bool addition = false;
    while (true) {
        if (addition) {
            nums.resize(nums.size() + addSize, true);

            // исключим составные числа простыми из предыдущих итераций
            for (int i = 0; i < foundPrimes; i++) {
                int cur_num = primeNums[i];
                if ((addSize + ((nums.size() - addSize) % cur_num)) < cur_num)
                    continue;
                for (int j = ((nums.size() - addSize) / cur_num) * cur_num; j < nums.size(); j += cur_num)
                    nums[j] = false;
            }
        }
        else
            addition = true;


        int iter;
        if (foundPrimes == 0)
            iter = 2;
        else
            iter = primeNums[foundPrimes - 1] + 2;

        for ( ; iter < nums.size(); iter++) {
            // выбираем очередное простое число
            if (nums[iter]) {
                primeNums[foundPrimes] = iter;
                foundPrimes++;
                if (foundPrimes == limit)
                    break;
                // просеиваем
                for (int j = iter + iter; j < nums.size(); j += iter)
                    nums[j] = false;
            }
            else
                continue;
        }
        if (foundPrimes == limit)
            break;
    }

    for (int i = 0; i <= primeNums.size()-1; ++i)
        cout << primeNums[i] << " ";

    return 0;
}
