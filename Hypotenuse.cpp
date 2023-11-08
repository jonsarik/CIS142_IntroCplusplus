// Created by Jonathan Sarkarati
// 11/8/23
// Homework 5, Problem 1
// Find the Hypotenuse

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void print_intro();
double get_leg1();
double get_leg2();
double get_hypot(double sideA, double sideB);
void exit_program();

int main()
{
    double leg1, leg2, hypotenuse;
    print_intro();          // Program description

    leg1 = get_leg1();      // Get first leg
    while (leg1)
    {
        leg2 = get_leg2();   // Get second leg
        cout << endl;
        // Calculate and return the result
        hypotenuse = get_hypot(leg1, leg2);
        cout << "The length of the hypotenuse is " << hypotenuse << endl;
        cout << "-------------------------------------" << endl;

        // More triangles?
        cout << "\nRun again?";
        leg1 = get_leg1();
    }
    exit_program();
    return 0;
}

// Explain purpose of program
void print_intro()
{
    cout << endl <<
        "+===================================================+" << endl <<
        "| This program calculates the hypotenuse of a right |" << endl <<
        "| triangle when the other two sides are known.      |" << endl <<
        "+===================================================+" << endl;
}

// Get and validate the first leg
double get_leg1()
{
    double sideA;
    cout << "\nEnter the length of the first leg"
        << "\nof the triangle, or 0 to exit: ";
    cin >> sideA;
    while (sideA < 0)
    {
        cout << "Please enter a valid number: ";
        cin >> sideA;
    }
    return sideA;
}

// Get and validate second leg
double get_leg2()
{
    double sideB;
    cout << "\nEnter the length of the second leg"
        "\nof the triangle: ";
    cin >> sideB;
    while (sideB < 0)
    {
        cout << "Please enter a valid number: ";
        cin >> sideB;
    }
    return sideB;
}

// Calculate the hypotenuse using Pythagorean theorem
double get_hypot(double sideA, double sideB)
{
    cout << fixed << showpoint << setprecision(2);
    return sqrt(pow(sideA, 2) + pow(sideB, 2));
}

// End program
void exit_program()
{
    cout << "\nExiting program...\nGoodbye!" << endl;
}