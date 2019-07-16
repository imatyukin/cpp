// Exercise 7-1.
// Write a program that reads and stores the first names of any number of students, along with their grades. Calculate
// and output the average grade and output the names and grades of all the students in a table with the name and grade
// for three students on each line.
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct StudentInfo
{
    string first_name;
    string grades;
};

void ReadStudentData(StudentInfo& student);
void DisplayStudentData(const StudentInfo& student);

int main()
{
    const int SIZE = 2;
    StudentInfo studentList[SIZE];

    for (int i = 0; i < SIZE; i++) {
        ReadStudentData(studentList[i]);
        DisplayStudentData(studentList[i]);
    }
}

void ReadStudentData(StudentInfo& student) {
    cout << "Enter student first name: ";
    cin >> student.first_name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "and " << student.first_name << "'s grades: ";
    getline(cin, student.grades);
}

void DisplayStudentData(const StudentInfo& student)
{
    cout << "The first name is: " << student.first_name << endl;

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

    cout << "Average grade of " << student.first_name << " is: " << avg << endl;
}