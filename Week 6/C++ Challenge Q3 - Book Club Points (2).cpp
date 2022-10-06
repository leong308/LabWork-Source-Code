// C++ Challenge Question 3
// Basic

#include <iostream>
using namespace std;

int main()
{
	
	int books, points = 5;
	
	// Operate while books < 0
	do{
		
		cout << "Please input the amount of book/s that you had purchased this month." << endl;
		cin >> books;
		
	if (books < 0)
		cout << "Invalid input detected.\n" << endl;	// Rejects input < 0
		
	}
	while (books < 0);
	
	if (books < 2)
		points =  books * points;
		
	else if (books == 2)
		points = 3 * points;
	
	else if (books == 3)
		points = 6 * points;
		
	else							// books > 3, points will be capped at 60
		points = 12 * points; 							
	
	cout << "\nYour points awarded on this month is " << points << " points." << endl;
	
	return 0;
	
}
