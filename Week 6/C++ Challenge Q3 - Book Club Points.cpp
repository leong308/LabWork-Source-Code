// C++ Challenge Question 3
// Enhanced version

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	
	int books, points = 5, x = 3, y;		// x as multiplier
	
	// Operate while books < 0
	do{
		
		cout << "Please input the amount of book/s that you had purchased this month." << endl;
		cin >> books;
		
	if (books < 0)
		cout << "Invalid input detected.\n" << endl;	// Rejects input < 0
		
	}
	while (books < 0);
	
	y = x * pow(2, books - 2);							// formula for >= 2 books
	
	if (books < 2)										// standard formula while books < 2
		points = books * points;
	
	else												// apply y formula for books > 2
		points = points * y;							
	
	cout << "\nYour points awarded on this month is " << points << " points." << endl;
	
	return 0;
	
}
