// Exercise 7-1.
// Write a program that reads and stores the first names of any number of students, along with their grades. Calculate
// and output the average grade and output the names and grades of all the students in a table with the name and grade
// for three students on each line.
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct StudentInfo
{
    string first_name;
    string grades;
};

void DisplayStudentData(const StudentInfo& student);

int main()
{
    vector<StudentInfo> studentList;

    char c;
    int i = 0;
    cout << "Press 'd' to display the average grade or any key to continue." << endl;

    while(true) {
        c = getchar();
        if(c == 'd')
            break;

        studentList.emplace_back(StudentInfo());
        cout << "Enter student first name: ";
        cin >> studentList[i].first_name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "and " << studentList[i].first_name << "'s grades: ";
        getline(cin, studentList[i].grades);
        i++;
        cout << "\nPress 'd' to display the average grade or any key to continue.\n" << endl;
    }

    for(int j=0; j<=i; j++) {
        DisplayStudentData(studentList[j]);
    }

    cout << "\nExit" << endl;

    return 0;
}

void DisplayStudentData(const StudentInfo& student)
{
    cout << student.first_name << " ";

    istringstream is(student.grades);
    int n;
    int total {};
    int count {};
    int avg {};
    while( is >> n ) {
        total += n;
        count++;
    }
    avg = total / count;

    cout << avg << endl;
}