// Lab 6 Question 12
// LEONG ZI QI

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	
	int width, length;
	double width2, width3 = 0;
	int i, j, k;
	
	do{
		cout << "Width of the tree: ";
		cin >> width;
		width2 = width;
		
		// prevent infinite loop if char entered 
		if(cin.fail()){
			cin.clear();				// clear input buffer
			cin.ignore(INT_MAX, '\n'); 	// ignore last input
		}
		if(width <= 0)
			cout << "Invalid Input. Please try again.\n" << endl;
		else if(width % 2 != 1)
			cout << "Only use odd number as the width. Please try again.\n" << endl;
	}
	while(width <= 0 || (width % 2 != 1));
	
	do{
		cout << "Trunk length of the tree: ";
		cin >> length;
		
		// prevent infinite loop if char entered 
		if(cin.fail()){
			cin.clear();				// clear input buffer
			cin.ignore(INT_MAX, '\n'); 	// ignore last input
		}
		if(length <= 0)
			cout << "Invalid Input. Please try again.\n" << endl;
	}
	while(width <= 0);
	
	cout << endl << setw(width / 2 + 1) << "*" << endl;
	
	for(i = 0; i <= (width / 2 - 1); i++){
		// don't put it into nested loop
		// prevent this line runs again in the same line
		// space (width / 2 - i) times before output *
		cout << setw(width / 2 - i) << right;
		
		// for loop in a single line
		for(j = 0; j <= i; j++)
			cout << "*";
		// middle *
		cout << "*";
		// right side of tree leafs
		for(j = 0; j <= i; j++)
			cout << left << "*";
			
		cout << endl;
	}
	
	while(width2 >= 3){
		width2 -= 2;
		width3++;
	}
	
	for(j = 0; j < length; j++){
		
		for(k = 0; k < width / 3; k++)
			cout << " ";
		
		for(k = 0; k < width / 3; k++)
			cout << "*";
		
		cout << endl;
	}
	return 0;
}
