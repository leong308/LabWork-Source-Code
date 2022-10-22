// This program finds the average time spent programming by a student
// each day over a three day period.

// LEONG ZI QI

#include <iostream>
using namespace std;

int main()
{
	int numStudents;
	float numHours, total, average;
    int student, day = 0;     		// these are the counters for the loops
    int day2;						// user can customize day
	
	cout << "This program will find the average number of hours a day" 
         << " that a student spent programming over a long weekend\n\n";
    cout << "How many students are there ?" << endl;
    cin >> numStudents;
    cout << "\nHow many days did student have for the weekend?" << endl;
    cin >> day2;
       
    for(student = 1; student <= numStudents; student++)
    {
		total = 0;
		for(day = 1; day <= day2; day++)
		{
			cout << "Please enter the number of hours worked by student " 
				 << student <<" on day " << day << "." << endl;
            cin >> numHours;

            total = total + numHours;
		}

        average = total / day2;

		cout << endl;
		cout << "The average number of hours per day spent programming in "  << day2 << " days by "
		     << "student " << student << " is " << average
			 << endl << endl << endl;
	}

    return 0;	
}
