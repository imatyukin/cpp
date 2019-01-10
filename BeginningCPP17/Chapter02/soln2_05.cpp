// Exercise 2-5.
// Your body mass index (BMI) is your weight, w, in kilograms divided by the square of your height, h, in meters
// (w/(h*h)). Write a program to calculate the BMI from a weight entered in pounds and a height entered in feet and
// inches. A kilogram is 2.2 pounds, and a foot is 0.3048 meters.
#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Calculation of body mass index (BMI).\n" << std::endl;

    const double lbs_per_kg {2.2};
    const double inches_per_foot {12.0};
    const double meters_per_foot {0.3048};

    double weight_lbs;
    std::cout << "Enter your weight in pounds: ";
    std::cin >> weight_lbs;

    unsigned int height_feet, height_inches;
    std::cout << "Enter your height in feet and inches: ";
    std::cin >> height_feet >> height_inches;
    const double height_ft {height_feet + height_inches / inches_per_foot};

    const double w {weight_lbs / lbs_per_kg};
    const double h {height_ft * meters_per_foot};
    const double bmi {w / (h * h)};

    std::cout << "Your body mass index (BMI) is "
              << std::fixed << std::setprecision(1)
              << bmi << std::endl;
}