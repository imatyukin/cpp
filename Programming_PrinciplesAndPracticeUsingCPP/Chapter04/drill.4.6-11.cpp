// Go through this drill step by step. Do not try to speed up by skipping steps. Test each step by entering at least
// three pairs of values — more values would be better.
// 6. Now change the body of the loop so that it reads just one double each time around. Define two variables to keep
// track of which is the smallest and which is the largest value you have seen so far. Each time through the loop write
// out the value entered. If it’s the smallest so far, write the smallest so far after the number. If it is the largest
// so far, write the largest so far after the number.
// 7. Add a unit to each double entered; that is, enter values such as 10cm, 2.5in, 5ft, or 3.33m. Accept the four
// units: cm, m, in, ft. Assume conversion factors 1m == 100cm, 1in == 2.54cm, 1ft == 12in. Read the unit indicator
// into a string. You may consider 12 m (with a space between the number and the unit) equivalent to 12m (without a
// space).
// 8. Reject values without units or with “illegal” representations of units, such as y, yard, meter, km, and gallons.
// 9. Keep track of the sum of values entered (as well as the smallest and the largest) and the number of values
// entered. When the loop ends, print the smallest, the largest, the number of values, and the sum of values. Note that
// to keep the sum, you have to decide on a unit to use for that sum; use meters.
// 10. Keep all the values entered (converted into meters) in a vector. At the end, write out those values.
// 11. Before writing out the values from the vector, sort them (that’ll make them come out in increasing order).
#include "std_lib_facilities.h"

int main() {
    vector<double> numbers;
    double number = 0;
    double smallest = 0;
    double largest = 0;
    bool is_first = true;

    cout << "Введите число или '|' для выхода из программы:\n";
    while (cin >> number) {
        char c;
        c = cin.peek();

        if (c == '|')
            break;
        else {
            cout << "Число " << number << endl;
            numbers.push_back(number);

            if (is_first) {
                smallest = number;
                largest = number;
                cout << "Наибольшее среди введённых" << endl;
                cout << "Наименьшее среди введённых" << endl;
                is_first = false;
                continue;
            }

            for (int i = 0; i < numbers.size(); ++i) {
                if (number < numbers[i])
                    if (number < smallest)
                        smallest = number;
                if (number > numbers[i])
                    if (number > largest)
                        largest = number;
            }

            if (number == smallest)
                cout << "Наименьшее среди введённых" << endl;
            if (number == largest)
                cout << "Наибольшее среди введённых" << endl;
        }
    }

    return 0;
}
