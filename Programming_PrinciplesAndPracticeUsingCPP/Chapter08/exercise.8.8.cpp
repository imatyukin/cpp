// 8. Write a function that given two vector<double>s price and weight computes a value (an “index”) that is the sum of
// all price[i]*weight[i]. Make sure to have weight.size()==price.size().

#include "std_lib_facilities.h"

vector<double> price;
vector<double> weight;

double calculation(const vector<double>& p, const vector<double>& w)
{
    double sum = 0;

    if (w.size() == p.size())
    {
        for (int i = 0; i < p.size(); ++i) {
            sum += p[i] * w[i];
        }
    }
    else error("\nразмер векторов не совпадает");

    return sum;
}

int main()
try
{
    double sum;

    for (int i=1; i<=5; ++i) price.push_back(i);
    for (int i=1; i<10; ++++i) weight.push_back(i);

    cout << "price: ";
    for (auto i: price) cout << i << ' ';
    cout << "\nweight: ";
    for (auto i: weight) cout << i << ' ';

    sum = calculation(price, weight);
    cout << "\nsum of all price[i]*weight[i]: " << sum << endl;
}
catch (runtime_error e) {
    cout << e.what() << '\n';
}
catch (...) {
    cout << "exiting\n";
}