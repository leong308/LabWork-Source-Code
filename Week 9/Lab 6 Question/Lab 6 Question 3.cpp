// Lab 6 Question 3
// LEONG ZI QI

#include <iostream>
using namespace std;

int main(){
	
	int i, x, sum = 0;
	
	do{
		cout << "Please enter a number:" << endl;
		cin >> x;
		cout << endl;
	
		// prevent infinite loop if char entered 
		if(cin.fail()){
			x = 0;						// declare false value to force whole do while to loop again
			cin.clear();				// clear input buffer
			cin.ignore(INT_MAX, '\n'); 	// ignore last input
		}
		if(x <= 0)
			cout << "Invalid Input. Please try again.\n" << endl;
	}
	while(x <= 0);
	
	for(i = 1; i <= x; i++){
		sum = sum + i;
	}
		cout << "Summation from 1 to " << x << " is " << sum << endl;
	
	return 0;
	
}
