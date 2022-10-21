// Lab 6 Question 10
// LEONG ZI QI

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	int num, terms, sum = 0;
	int j = 0;
	bool valid;
	
	// infnite loop while num entered exceed the range
	do{
		cout << "Please enter an integer." << endl;
		cin >> num;
		
		// prevent infinite loop after first error
		valid = true;	
		// prevent infinite loop if char entered 
		if(cin.fail()){
			valid = false;										// declare false value to force whole do while to loop again
			cin.clear();										// clear input buffer
			cin.ignore(INT_MAX, '\n'); 							// ignore last input
			cout << "Please enter a valid integer.\n" << endl;
		}
	}
	while(valid == false);
	
	// calculate terms of the num
	while(valid == true){
		terms = 1 * pow(10, j);
		j++;
			
		// escape while loop
		// store num into terms
		if(terms > num){
			valid = false;
			terms = num;
		}
	}
	
	// num % 10, add remiander into sum
	// remove part that went thru %
	// loop until reach the terms of num
	for(int i = 1; i < j; i++){
		sum = sum + num % 10;
		num /= 10;
	}

	cout << "\nThe sum of the seperate number " << terms << " is " << sum << endl;
	
	return 0;
	
}
