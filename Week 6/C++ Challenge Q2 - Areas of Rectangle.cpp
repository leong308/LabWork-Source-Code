// C++ Challenge Question 2

#include <iostream>
using namespace std;

int main ()
{
	
	double l1, w1, l2, w2, a1, a2;
	
	// operate while l1 or w1 <= 0
	do{
		cout << "Please input the length and width of the first rectangle." << endl;
		cin >> l1 >> w1;
		
	if (l1 <= 0 || w1 <= 0)			// validate l1 and w1
		cout << "Please input a valid length or width of the first rectangle." << endl;
		
	}
	while (l1 <= 0 || w1 <= 0);	
	
	// operate while l2 or w2 <= 0
	do{
		cout << "Please input the length and width of the second rectangle." << endl;
		cin >> l2 >> w2;
		
	if (l2 <= 0 || w2 <= 0)			// validate l2 and w2
		cout << "Please input a valid length or width of the second rectangle." << endl;
		
	}
	while (l2 <= 0 || w2 <= 0);
	
	a1 = l1 * w1;		// area of rectangle 1
	a2 = l2 * w2;		// area of rectangle 2
	
	if (a1 == a2)
		cout << "\nThe area of both rectangles are the same." << endl;
		
	else if (a1 > a2)
		cout << "\nThe area of the first rectangle is greater." << endl;
		
	else
		cout << "\nThe area of the second rectangle is greater." << endl;
	
	return 0; 
	
}
