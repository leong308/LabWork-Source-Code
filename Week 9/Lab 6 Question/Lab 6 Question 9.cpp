// Lab 6 Question 9
// LEONG ZI QI

#include <iostream>
#include <time.h>
using namespace std;

int main(){
	int r, num;
	bool guess = false;
	
	// random seed
	srand(time(0));
	// random number range  0 <= r <= 9999
	r = rand() % 10000;
	
	while(guess == false){
		// infnite loop while num entered exceed the range
		do{
			cout << "Guess the secret number between 0 and 9999:" << endl;
			cin >> num;
			
			// prevent infinite loop if char entered 
			if(cin.fail()){
				num = -1;					// declare false value to force whole do while to loop again
				cin.clear();				// clear input buffer
				cin.ignore(INT_MAX, '\n'); 	// ignore last input
			}
			if(num < 0 || num > 9999)
				cout << "Please enter a number between 0 and 9999.\n" << endl;
		}
		while(num < 0 || num > 9999);
		
		// if guessed, declare guess as true
		// to escape whole while loop
		if(num == r){
			cout << "Fantastic! You guessed the secret number correctly!" << endl;
			guess = true;
		}
		else if(num > r)
			cout << "It is too high. Take another guess!\n" << endl;
		else
			cout << "It is too low. Take another guess!\n" << endl;
	}
	
	return 0;
	
}
