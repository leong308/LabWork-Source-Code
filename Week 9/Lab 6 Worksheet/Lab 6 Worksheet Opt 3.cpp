// Lab 6 Worksheet Option 2
// LEONG ZI QI

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	int tellers, day;
	int i, j;			// counter
	int total = 0;		// total days
	
	do{
		cout << "How many tellers worked at Nation’s Bank during each of the last three years?" << endl;
		cin >> tellers;
	
		// prevent infinite loop if char entered 
		if(cin.fail()){
			tellers = -1;				// declare false value to force whole do while to loop again
			cin.clear();				// clear input buffer
			cin.ignore(INT_MAX, '\n'); 	// ignore last input
		}
		if(tellers < 0)
			cout << "Invalid Input. Please try again.\n" << endl;
	}
	while(tellers < 0);
	
	// initial i = 1, while i less than tellers, increment i
	for(i = 1; i <= tellers; i++){
		
		// initial j = 1, while j less than 3, increment j
		for(j = 1; j <= 3; j++){
			
			do{
				cout << "How many days was teller " << i << " out sick during year " << j << "?" << endl;
				cin >> day;
	
				// prevent infinite loop if char entered 
				if(cin.fail()){
					day = -1;					// declare false value to force whole do while to loop again
					cin.clear();				// clear input buffer
					cin.ignore(INT_MAX, '\n'); 	// ignore last input
				}
				if(day < 0)
					cout << "Invalid Input. Please try again.\n" << endl; 
			}		
			while(day < 0);
			
			total = total + day;
		}	
		// after this for loop ends, back to main for loop
		// make another loop with incremented i
	}
	
	if(tellers > 0)
		cout << "\nThe " << tellers << " teller/s were out sick for a total of " << total << " days during the last three years." << endl;
	else
		cout << "\nNo teller data inserted." << endl;
	
	return 0;
	
}
