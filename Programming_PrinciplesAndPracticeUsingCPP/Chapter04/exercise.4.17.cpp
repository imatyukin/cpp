// 17. Write a program that finds the min, max, and mode of a sequence of strings.
#include "std_lib_facilities.h"

int count(string value, vector<string> words) {
    int c = 0;
    for (string word : words) {
        if (word == value)
            ++c;
    }
    return c;
}

int main(){
    cout << "Введите последовательность слов: " << endl;
    string word;
    vector<string> words;
    while (cin >> word) {
        words.push_back(word);
    }

    if (0 < words.size()) {
        string min = words[0];
        string max = words[0];
        string mode = " ";
        int mode_count = 0;

        for (int i = 0; i < words.size(); ++i) {
            if (words[i] < min)
                min = words[i];
            if (max < words[i])
                max = words[i];
            int count_of_words = count(words[i], words);
            if (mode_count < count_of_words) {
                mode = words[i];
                mode_count = count_of_words;
            }
        }

        cout << "Наименьшее значение: " << min
             << "\nНаибольшее значение: " << max
             << "\nМода: " << mode << " (" << mode_count << ")\n";
    }
}
