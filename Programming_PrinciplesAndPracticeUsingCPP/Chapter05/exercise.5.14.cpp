// 14. Read (day-of-the-week,value) pairs from standard input. For example:
// Tuesday 23 Friday 56 Tuesday –3 Thursday 99
// Collect all the values for each day of the week in a vector<int>. Write out the values of the seven day-of-the-week
// vectors. Print out the sum of the values in each vector. Ignore illegal days of the week, such as Funday, but accept
// common synonyms such as Mon and monday. Write out the number of rejected values.
#include "std_lib_facilities.h"

int main()
{
    string day;
    int number;
    vector<int> monday;
    vector<int> tuesday;
    vector<int> wednesday;
    vector<int> thursday;
    vector<int> friday;
    vector<int> saturday;
    vector<int> sunday;
    int sum_of_elems;
    int rejected = 0;

    cout << "Введите пары (день недели, значение):" << endl;
    while (cin >> day >> number) {
        if (day == "Monday"           || day == "monday"      || day == "Mon" || day == "mon" ||
            day == "Понедельник"      || day == "понедельник" || day == "Пн"  || day == "пн")
            monday.push_back(number);
        else if (day == "Tuesday"     || day == "tuesday"     || day == "Tue" || day == "tue" ||
                 day == "Вторник"     || day == "вторник"     || day == "Вт"  || day == "вт")
            tuesday.push_back(number);
        else if (day == "Wednesday"   || day == "wednesday"   || day == "Wed" || day == "wed" ||
                 day == "Среда"       || day == "среда"       || day == "Ср"  || day == "ср")
            wednesday.push_back(number);
        else if (day == "Thursday"    || day == "thursday"    || day == "Thu" || day == "thu" ||
                 day == "Четверг"     || day == "четверг"     || day == "Чт"  || day == "чт")
            thursday.push_back(number);
        else if (day == "Friday"      || day == "friday"      || day == "Fri" || day == "fri" ||
                 day == "Пятница"     || day == "пятница"     || day == "Пт"  || day == "пт")
            friday.push_back(number);
        else if (day == "Saturday"    || day == "saturday"    || day == "Sat" || day == "sat" ||
                 day == "Суббота"     || day == "суббота"     || day == "Сб"  || day == "сб")
            saturday.push_back(number);
        else if (day == "Sunday"      || day == "sunday"      || day == "Sun" || day == "sun" ||
                 day == "Воскресенье" || day == "воскресенье" || day == "Вс"  || day == "вс")
            sunday.push_back(number);
        else
            ++rejected;
    }

    cout << "Значения векторов для каждого из дней недели:" << endl;
    cout << "Пн: "; for (auto i: monday)    cout << i << ' '; cout << endl;
    cout << "Вт: "; for (auto i: tuesday)   cout << i << ' '; cout << endl;
    cout << "Ср: "; for (auto i: wednesday) cout << i << ' '; cout << endl;
    cout << "Чт: "; for (auto i: thursday)  cout << i << ' '; cout << endl;
    cout << "Пт: "; for (auto i: friday)    cout << i << ' '; cout << endl;
    cout << "Сб: "; for (auto i: saturday)  cout << i << ' '; cout << endl;
    cout << "Вс: "; for (auto i: sunday)    cout << i << ' '; cout << endl;

    cout << "Сумма чисел в каждом из векторов:" << endl;
    sum_of_elems = 0; cout << "Пн: "; for (auto& n : monday)    sum_of_elems += n; cout << sum_of_elems << endl;
    sum_of_elems = 0; cout << "Вт: "; for (auto& n : tuesday)   sum_of_elems += n; cout << sum_of_elems << endl;
    sum_of_elems = 0; cout << "Ср: "; for (auto& n : wednesday) sum_of_elems += n; cout << sum_of_elems << endl;
    sum_of_elems = 0; cout << "Чт: "; for (auto& n : thursday)  sum_of_elems += n; cout << sum_of_elems << endl;
    sum_of_elems = 0; cout << "Пт: "; for (auto& n : friday)    sum_of_elems += n; cout << sum_of_elems << endl;
    sum_of_elems = 0; cout << "Сб: "; for (auto& n : saturday)  sum_of_elems += n; cout << sum_of_elems << endl;
    sum_of_elems = 0; cout << "Вс: "; for (auto& n : sunday)    sum_of_elems += n; cout << sum_of_elems << endl;

    cout << "Количество отвергнутых значений: " << rejected << endl;

    return 0;
}
