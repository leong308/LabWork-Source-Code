// Question 4

#include <iostream>
using namespace std;

int main()
{
	double avg;			// average
	string c;			// categories
	
	// infinite loop while avg < 0
	// or avg > 0
	do{
		cout << "Please enter your average marks: ";
		cin >> avg;
		
		if(avg < 0 || avg > 100)
			cout << "Invalid data.\n" << endl;
	}
	while(avg < 0 || avg > 100);
	
	// determine categories
	if(avg >= 90)
		c = "You obtained grade A.";
	else if(avg >= 80)
		c = "You obtained grade B.";
	else if(avg >= 60)
		c = "You Pass.";
	else
		c = "You Fail.";

	cout << endl << c << endl;
	
	return 0;
	
}
