// Lab 6 Question 2
// LEONG ZI QI

#include <iostream>
using namespace std;

int main(){
	
	int i, j;

	do{
		cout << "Please enter a number to fetch the multiplication table." << endl;
		cin >> j;
		cout << endl;
	
		// prevent infinite loop if char entered 
		if(cin.fail()){
			j = -1;						// declare false value to force whole do while to loop again
			cin.clear();				// clear input buffer
			cin.ignore(INT_MAX, '\n'); 	// ignore last input
		}
		if(j <= 0)
			cout << "Invalid Input. Please try again.\n" << endl;
	}
	while(j <= 0);
	
	// while i <= 12, increment i
	for(i = 1; i <= 12; i++)
		cout << j << " x " << i << " = " << (j * i) << endl;
	
	return 0;
	
}
