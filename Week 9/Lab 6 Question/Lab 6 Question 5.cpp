// Lab 6 Question 5
// LEONG ZI QI

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	int i;
	double score, rate, pass = 0;
	cout << setprecision(2) << fixed;
	
	// infinite loop to get value
	// until user use -1 as score to terminate program
	for(i = 0; score != -1; i++){
		// infinite loop if user key in false range
		do{
			cout << "Key in (-1) to stop calculation" << endl;
			cout << "The score of student " << (i + 1) << " in CSC206 is:" << endl;		
			cin >> score;
			cout << endl;
		
			// prevent infinite loop if char entered 
			if(cin.fail()){
				score = -2;					// declare false value to force whole do while to loop again
				cin.clear();				// clear input buffer
				cin.ignore(INT_MAX, '\n'); 	// ignore last input
			}
			if((score < 0 || score > 100) && score != -1)
				cout << "Invalid Input. The score must be between 0 - 100. Please try again.\n" << endl;
		}
		while((score < 0 || score > 100) && score != -1);
	
	// if score valid, determine whether score is pass
	// increment pass if student pass
	if(score != -1){
		if(score >= 50)
			pass++;	
	}
	// calculate rate when user use -1 to terminate program
	else
		rate = (pass / i) * 100;
	}	
	if(rate >= 0){
		cout << "The passing mark of CSC206 is 50%." << endl;
		cout << "The passing rate of ICT1101 is " << rate << "% with " << (i - 1) << " students." << endl;
	}
	else
		cout << "No data available." << endl;
		
	return 0;
	
}
