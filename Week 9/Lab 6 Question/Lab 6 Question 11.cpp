// Lab 6 Question 11
// LEONG ZI QI

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	int num, num2, numtemp, terms;
	int j = 0;
	string number[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven","eight", "nine"};
	string numberout[6];
	bool valid = true;
	
	// infnite loop while num entered exceed the range
	do{
		cout << "Please enter an integer." << endl;
		cin >> num;
		
		// prevent infinite loop if char entered 
		if(cin.fail()){
			cin.clear();										// clear input buffer
			cin.ignore(INT_MAX, '\n'); 							// ignore last input
		}
		if(num < 1 || num > 9999)
			cout << "Invalid Input. Please try again.\n" << endl;
	}
	while(num < 1 || num > 9999);
	
	// calculate terms of the num
	while(valid == true){
		terms = 1 * pow(10, j);
		j++;
			
		// escape while loop
		// store num into terms for output
		if(terms > num){
			valid = false;
			terms = num;
			// decrement to prevent additional zero output
			// while num terms < 4
			j--;
		}
	}
	
	// num % with 10
	// use num to enter switch case
	// loop until reach the max terms
	for(int i = 1; i < 5; i++){
		numtemp = num;
		numtemp %= 10;
		num /= 10;
			
			// declare string output for every num
			switch(numtemp){
				case 0:		numberout[i] = number[0];
							break;
				case 1:		numberout[i] = number[1];
							break;
				case 2:		numberout[i] = number[2];
							break;
				case 3:		numberout[i] = number[3];
							break;
				case 4:		numberout[i] = number[4];
							break;
				case 5:		numberout[i] = number[5];
							break;
				case 6:		numberout[i] = number[6];
							break;
				case 7:		numberout[i] = number[7];
							break;
				case 8:		numberout[i] = number[8];
							break;
				case 9:		numberout[i] = number[9];
							break;
			}
		}
	
	// front part of output
	cout << "\nThe number " << terms << " is ";
	// loop to output word form number
	for(j; j > 0; j--)
		cout << numberout[j] << " ";
		
	return 0;
	
}
