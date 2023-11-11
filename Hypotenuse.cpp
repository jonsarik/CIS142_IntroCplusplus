// Created by Jonathan Sarkarati
// 11/8/23
// Homework 5, Problem 1
// Find the Hypotenuse

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

void print_intro();
double get_leg(string);
double get_hypot(double, double);
void exit_program();

int main()
{
    double leg1, leg2, hypotenuse;
    string first = "first",
        second = "second";
    

    leg1 = get_leg(first);          // Get first leg of triangle
    while (leg1)
    {
        leg2 = get_leg(second);     // Get second leg of triangle
        cout << endl;
        
        // Get and display the hypotenuse
        hypotenuse = get_hypot(leg1, leg2);
        cout << "The length of the hypotenuse is " << hypotenuse << endl;
        cout << "-------------------------------------" << endl;

        // More calculations?
        cout << "\nPress Enter to continue. ";
        cin.get();
        cin.get();
        leg1 = get_leg(first);
    }
    exit_program();
    return 0;
}

// Explain purpose of program
void print_intro()
{
    system("cls");
    cout << endl <<
        "+===================================================+" << endl <<
        "| This program calculates the hypotenuse of a right |" << endl <<
        "| triangle when the other two sides are known.      |" << endl <<
        "+===================================================+" << endl;
}

// Get and validate triangle leg
double get_leg(string leg)
{
    double side;
    if (leg == "first")
    {
        print_intro();                  // Program description
        cout << "\nEnter the length of the " << leg << " leg"
            << "\nof the triangle, or 0 to exit: ";
    }
        
    else
        cout << "\nEnter the length of the " << leg << " leg"
        << "\nof the triangle: ";    
    cin >> side;
    while (side < 0)
    {
        cout << "Please enter a valid number: ";
        cin >> side;
    }
    return side;
}

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
