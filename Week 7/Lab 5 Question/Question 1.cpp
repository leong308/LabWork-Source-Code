// Question 1

#include <iostream>
using namespace std;

int main()
{
	double avg;
	
	// infinite loop while avg less than 0 or more than 100
	do{
		cout << "Enter your average mark: ";
		cin >> avg;
	
		if(avg < 0 || avg > 100)
			cout << "Invalid average mark.\n" << endl;
	}
	while(avg < 0 || avg > 100);

	if(avg >= 50)
		cout << "\nYou pass." << endl;
	else
		cout << "\nYou fail." << endl;

	return 0;
}
