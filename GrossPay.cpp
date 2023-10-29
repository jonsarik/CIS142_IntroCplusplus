// Created by Jonathan Sarkarati
// 10/13/2024
// This program calculates gross pay using a do-while loop
// with input validation for hours worked.

#include <iostream>
#include <iomanip>
using namespace std;

const int		MAX_HOURS = 168,		// Max available hours in a week
				MIN_HOURS = 0,			// Min available hours in a week
				OVER_TIME = 40,			// Hours worked for "straight time"
				EXIT = -1;				// Sentinel exit program
const double	TIME_AND_HALF = 1.5;	// Overtime pay rate multiplier

int main()
{
	int hours_worked;
	double pay_rate, gross_pay;

	// Get hours worked and pay rate for employee

	cout << "This program calculates and displays the gross pay for each employee.\n";
	cout << "Enter hours worked (-1 to end): ";
	cin >> hours_worked;

	do
	{
		cout << "Enter hourly rate of the employee ($00.00): ";
		cin >> pay_rate;
		if (hours_worked >= MIN_HOURS && hours_worked <= OVER_TIME)		// Pay for 40 hours or less
		{
			gross_pay = (hours_worked * pay_rate);	
		}
		else if (hours_worked > OVER_TIME && hours_worked <= MAX_HOURS)	// Pay if worked overtime
		{
			gross_pay = ((hours_worked - OVER_TIME) * pay_rate  * TIME_AND_HALF) + (OVER_TIME * pay_rate);	
		}
		else	// If hours entered greater than exist in a week, or negative
		{
			cout << "\nInvalid number of hours. Please check and enter again.\n";
			cout << "\nEnter hours worked (-1 to end): ";
			cin >> hours_worked;
			continue;
		}
		cout << fixed << showpoint << setprecision(2);
		cout << "\nSalary is $" << gross_pay << endl << endl;
		cout << "Enter hours worked (-1 to end): ";
		cin >> hours_worked;
	}
	while (hours_worked != EXIT);	// Sentinel value to exit program
	return 0;
}
