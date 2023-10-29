// Project submitted Jonathan Sarkarati
// This test scoring program does not accept test 
// scores that are less than 0 or greater than 100.
#include <iostream>
using namespace std;

int main()
{
    // Constants for grade thresholds
    const int   A_SCORE = 90,
        B_SCORE = 80,
        C_SCORE = 70,
        D_SCORE = 60,
        MIN_SCORE = 0,    // Minimum valid score
        MAX_SCORE = 100;  // Maximum valid score

    int testScore;              // Holds the user entered numeric test score

    // Get the numeric test score
    cout << "Enter your numeric test score and I will\n"
        << "tell you the letter grade you earned: ";
    cin >> testScore;

    // An invalid score was entered
    if (testScore < MIN_SCORE || testScore > MAX_SCORE)
        cout << "\nThat is an invalid score. Run the program\n"
        << "again and enter a value in the range of\n"
        << MIN_SCORE << " through " << MAX_SCORE << ".\n";

    switch (testScore / 10)
    {
    case 10: cout << "Great job!\n";
        cout << "Your grade is A+.\n";
        break;
    case 9: cout << "Your grade is A.\n";
        break;
    case 8: cout << "Your grade is B.\n";
        break;
    case 7: cout << "Your grade is C.\n";
        break;
    case 6: cout << "Your grade is D.\n";
        break;
    default: cout << "Your Grade is F.\n" << endl;
    }

    return 0;
}
