// Created by Jonathan Sarkarati
// 11/17/2023
// Homework 5, Problem 2
// Temperature Conversion

#include <iostream>
#include <iomanip>
using namespace std;

// Constants
const int	CEL_MIN = 0,		// Celsius minimum
			CEL_MAX = 100,		// Celsius maximum
			FAHR_MIN = 32,		// Fahrenheit minimum
			FAHR_MAX = 212,		// Fahrenheit maximum
			NUM_ROWS = 51;		// Number of rows per column

void print_intro();
void print_chart();
double convert_to_fahrenheit(int degree);
double convert_to_celsius(int degree);
void exit_program();

int main()
{
	print_intro();				// Program description
	print_chart();				// Display conversion table
	exit_program();
	return 0;
}

// Explain purpose of program
void print_intro()
{
	cout << endl <<
		"	\t+=========================================================================================+" << endl <<
		"	\t| This program displays a table of temperatures converted to both Fahrenheit and Celsius. |" << endl <<
		"	\t+=========================================================================================+" << endl;
}

// Calculate and display conversion table
void print_chart()
{
	cout << endl;
	cout << fixed << showpoint << setprecision(1);
	cout << setw(12) << "Fahrenheit" << setw(9) << "Celsius"
		<< setw(12) << "Fahrenheit" << setw(9) << "Celsius"
		<< setw(12) << "Fahrenheit" << setw(9) << "Celsius"
		<< setw(12) << "Fahrenheit" << setw(9) << "Celsius"
		<< setw(3) << "||"
		<< setw(9) << "Celsius" << setw(12) << "Fahrenheit"
		<< setw(9) << "Celsius" << setw(12) << "Fahrenheit" << endl;
	cout << "--------------------------------------------------------------------------------------"
		<< "-------------------------------------------" << endl;

	int tally2 = FAHR_MIN + NUM_ROWS,		// Control 2nd Fahrenheit column
		tally3 = FAHR_MIN + NUM_ROWS * 2,	// Control 3rd Fahrenheit column
		tally4 = FAHR_MIN + NUM_ROWS * 3,	// Control 4th Fahrenheit column
		cel_tally = CEL_MIN,				// Control 1st Celsius column
		cel_tally2 = CEL_MIN + NUM_ROWS;	// Control 2nd Celsius column

	// 1st column of Fahrenheit conversions
	for (int fahrenheit = FAHR_MIN; fahrenheit < FAHR_MIN + NUM_ROWS; fahrenheit++)
	{
		// 2nd column of Fahrenheit conversions
		for (int fahrenheit2 = FAHR_MIN + NUM_ROWS; fahrenheit2 <= FAHR_MIN + NUM_ROWS * 2; fahrenheit2++)
		{
			if (fahrenheit2 != tally2)
				continue;

			// 3rd column of Fahrenheit conversions
			for (int fahrenheit3 = FAHR_MIN + NUM_ROWS * 2; fahrenheit3 <= FAHR_MIN + NUM_ROWS * 3; fahrenheit3++)
			{
				if (fahrenheit3 != tally3)
					continue;
				
				// 1st column of Celsius conversions
				for (int celsius = CEL_MIN; celsius < NUM_ROWS; celsius++)
				{
					if (celsius != cel_tally)
						continue;
					
					// 2nd column of Celsius conversions
					for (int celsius2 = NUM_ROWS; celsius2 <= CEL_MAX; celsius2++)
					{
						if (celsius2 != cel_tally2)
							continue;
						
						// 4th column of Fahrenheit conversions
						for (int fahrenheit4 = FAHR_MIN + NUM_ROWS * 3; fahrenheit4 <= FAHR_MAX; fahrenheit4++)
						{
							if (fahrenheit4 != tally4)
								continue;
							
							cout << setw(8) << fahrenheit << setw(11) << convert_to_celsius(fahrenheit)
								<< setw(10) << fahrenheit2 << setw(11) << convert_to_celsius(fahrenheit2)
								<< setw(10) << fahrenheit3 << setw(11) << convert_to_celsius(fahrenheit3)
								<< setw(10) << fahrenheit4 << setw(12) << convert_to_celsius(fahrenheit4)
								<< setw(4) << "||"
								<< setw(6) << celsius << setw(12) << convert_to_fahrenheit(celsius) << "\t"
								<< setw(3) << celsius2 << setw(11) << convert_to_fahrenheit(celsius2) << endl;

						}
						// Continue printing when final column for Fahrenheit reaches max
						if (tally4 > FAHR_MAX)
							cout << setw(8) << fahrenheit << setw(11) << convert_to_celsius(fahrenheit)
								<< setw(10) << fahrenheit2 << setw(11) << convert_to_celsius(fahrenheit2)
								<< setw(10) << fahrenheit3 << setw(11) << convert_to_celsius(fahrenheit3)
								<< "\t\t\t"
								<< "     ||"
								<< setw(6) << celsius << setw(12) << convert_to_fahrenheit(celsius) << "\t"
								<< setw(3) << celsius2 << setw(11) << convert_to_fahrenheit(celsius2) << endl;
						
					}
					// Continue printing when final columns for Celsius and Fahrenheit reach max
					if (cel_tally2 > CEL_MAX)
						cout << setw(8) << fahrenheit << setw(11) << convert_to_celsius(fahrenheit)
							<< setw(10) << fahrenheit2 << setw(11) << convert_to_celsius(fahrenheit2)
							<< setw(10) << fahrenheit3 << setw(11) << convert_to_celsius(fahrenheit3)
							<< "\t\t\t"
							<< "     ||"
							<< setw(6) << celsius << setw(12) << convert_to_fahrenheit(celsius) << "\t"
							<< endl;					
				}
			}
		}
		tally2++;
		tally3++;
		tally4++;
		cel_tally++;
		cel_tally2++;
	}
	cout << "--------------------------------------------------------------------------------------"
		<< "-------------------------------------------" << endl;


}

// Convert Celsius to Fahrenheit
double convert_to_fahrenheit(int degree)
{
	return (degree * 9.0 / 5) + 32;
}

// Convert Fahrenheit to Celsius
double convert_to_celsius(int degree)
{
	return (degree - 32) * 5.0 / 9;
}

// End program
void exit_program()
{
	cout << "\nPress Enter to exit program" << endl;
	cin.get();
	cout << "\nExiting program...\nGoodbye!)" << endl;
}
