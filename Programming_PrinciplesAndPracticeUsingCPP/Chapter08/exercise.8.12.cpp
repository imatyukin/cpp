// 12. Write a function that takes a vector<string> argument and returns a vector<int> containing the number of
// characters in each string. Also find the longest and the shortest string and the lexicographically first and last
// string. How many separate functions would you use for these tasks? Why?

#include "std_lib_facilities.h"

void print_str(const vector<string>& v, const string& name)
{
    cout << name << ": (" << v.size() << ") { ";
    for (int i = 0; i<v.size(); ++i) {
        cout << v[i];
        if (i<v.size()-1) cout << ", ";
    }
    cout << " }\n";
}

void print_int(const vector<int>& v, const string& name)
{
    cout << name << ": (" << v.size() << ") { ";
    for (int i = 0; i<v.size(); ++i) {
        cout << v[i];
        if (i<v.size()-1) cout << ", ";
    }
    cout << " }\n";
}

vector<int> number_of_char(const vector<string>& s)
{
    vector<int> n;
    for (string i : s) {
        int length = (i).size();
        n.push_back(length);
    }
    return n;
}

void long_short_str(const vector<int>& v, const vector<string>& s, int n)
{
    int max = v[0], min = v[0];
    vector<string> longest, shortest;

    for(int i = 0; i < n; i++) {
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
    }

    for(string i : s) {
        int length = (i).size();
        if (length == max) longest.push_back(i);
        if (length == min) shortest.push_back(i);
    }

    print_str(longest, "the longest strings");
    print_str(shortest, "the shortest strings");
}

void lexicograph_first_last_str(vector<string>& s)
{
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[i] > s[j]) {
                string temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    cout << "the lexicographically first string: ";
    cout << s[0] << endl;
    cout << "the lexicographically last string: ";
    for (int i = 0; i < s.size(); ++i) {
        if (i == s.size()-1) { cout << s[i] << endl; }
    }

}

int main()
try
{
    vector<string> s{ "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    print_str(s, "s");

    vector<int> i = number_of_char(s);
    print_int(i, "i");

    long_short_str(i, s, i.size());
    lexicograph_first_last_str(s);

    return 0;
}
catch(exception& e)
{
    cerr << e.what() << endl;
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!\n";
    return 2;
}