// Lab 6 Question 7
// (b) 
// LEONG ZI QI

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	int i, j, lines;
	
	do{
		cout << "How many line/s of star pattern do you want to print?" << endl;
		cin >> lines;
		cout << endl;
	
		// prevent infinite loop if char entered 
		if(cin.fail()){
			lines = -1;					// declare false value to force whole do while to loop again
			cin.clear();				// clear input buffer
			cin.ignore(INT_MAX, '\n'); 	// ignore last input
		}
		if(lines <= 0)
			cout << "Invalid Input. Please try again.\n" << endl;
	}
	while(lines <= 0);
	
	// line by line for loop
	for(i = 0; i < lines; i++){
		// don't put it into nested loop
		// prevent this line runs again in the same line
		// space (lines - i) times before output *
		cout << setw(lines - i) << right;
		
		// for loop in a single line
		for(j = 0; j <= i; j++)
			cout << "*";
			
		cout << endl;
	}
		
	return 0;
	
}
