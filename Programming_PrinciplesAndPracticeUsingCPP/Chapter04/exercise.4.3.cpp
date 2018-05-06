// 3. Read a sequence of double values into a vector. Think of each value as the distance between two cities along a
// given route. Compute and print the total distance (the sum of all distances). Find and print the smallest and
// greatest distance between two neighboring cities. Find and print the mean distance between two neighboring cities.
#include "std_lib_facilities.h"

int main() {
    vector<double> distances;
    double distance;
    double total = 0;
    double smallest, greatest = 0;
    double mean = 0;

    cout << "Введите значения расстояний между двумя городами расположенными вдоль маршрута:" << endl;
    while (cin>>distance)
        distances.push_back(distance);

    for (int i = 0; i < distances.size(); ++i) {
        total += distances[i];
    }
    cout << "Общее расстояние равно " << total << endl;

    smallest = distances[0];
    for (int i = 0; i < distances.size(); ++i)
        if (distances[i] < smallest)
            smallest = distances[i];
    cout << "Наименьшее расстояние между двумя соседними городами равно " << smallest << endl;

    greatest = distances[0];
    for (int i = 0; i < distances.size(); ++i)
        if (distances[i] > greatest)
            greatest = distances[i];
    cout << "Наибольшее расстояние между двумя соседними городами равно " << greatest << endl;

    mean = total / distances.size();
    cout << "Среднее расстояние между двумя соседними городами равно " << mean << endl;
}
