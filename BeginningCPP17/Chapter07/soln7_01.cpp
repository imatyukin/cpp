// Exercise 7-1.
// Write a program that reads and stores the first names of any number of students, along with their grades. Calculate
// and output the average grade and output the names and grades of all the students in a table with the name and grade
// for three students on each line.
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct StudentInfo
{
    string first_name;
    string grades;
};

int main()
{
    vector<StudentInfo> studentList;
    size_t max_length {};
    char c;
    int i {};

    while(true) {
        studentList.emplace_back(StudentInfo());
        cout << "Enter student first name: ";
        cin >> studentList[i].first_name;
        if (max_length < studentList[i].first_name.length())
            max_length = studentList[i].first_name.length();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "and " << studentList[i].first_name << "'s grades: ";
        getline(cin, studentList[i].grades);
        i++;
        cout << "\nPress 'd' to display the average grade or any key to continue.\n" << endl;
        c = getchar();
        if(c == 'd')
            break;
    }

    const size_t perline {3};

    for (size_t j {}; j <= i; ++j) {
        int n {};
        int total {};
        int count {};
        int avg {};
        istringstream is(studentList[j].grades);
        while(is >> n) {
            total += n;
            count++;
        }
        if(count == 0) exit(0);
        avg = total / count;
        cout << "  " << left << setw(max_length) << studentList[j].first_name
             << right << setw(2) << avg;
        if((j+1) % perline) continue;
        cout << endl;
    }
    cout << endl;

    return 0;
}