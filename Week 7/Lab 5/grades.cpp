//  This program prints "You Pass" if a student's average is 
//  60 or higher and prints "You Fail" otherwise

// PLACE YOUR NAME HERE

#include <iostream>
using namespace std;

int main()
{

	float average; // holds the average

	cout << "Input your average:" << endl;
	cin >> average;

	if (average > 100)
		cout << "It is an invalid data" << endl;
	
	else if (average >= 90)							// (average >= 90 && average <= 100)
		cout << "You achieved Grade A" << endl;
		
	else if (average >= 80)							// (average >= 80 && average < 90)
		cout << "You achieved Grade B" << endl;
		
	else if (average >= 60)							// (average >= 60 && average < 80)
		cout << "You Pass" << endl;
		
	else if (average >= 0)
		cout << "You Fail" << endl;
		
	else
		cout << "It is an invalid data" << endl;

    return 0;	
}
