#include <iostream>
using namespace std;

int main(){
	
	bool loop = true;
	int org, days;
	double grow;
	char c;
	
	// infinite loop while loop is set as true
	while(loop == true){
		// input initial organisms no
		do{
			cout << "Please input the starting number of organisms: ";
			cin >> org;
			// prevent infinite loop if char entered 
			if(cin.fail()){
				org = 0;					// declare false value to force whole do while to loop again
				cin.clear();				// clear input buffer
				cin.ignore(INT_MAX, '\n'); 	// ignore last input
			}
			if(org < 2)
				cout << "Invalid Input. Please try again.\n" << endl;
		}
		while(org < 2);
		
		// input grow rate
		do{
			cout << "The average daily population increase of the organisms (%): ";
			cin >> grow;
			// prevent infinite loop if char entered 
			if(cin.fail()){
				grow = -1;					// declare false value to force whole do while to loop again
				cin.clear();				// clear input buffer
				cin.ignore(INT_MAX, '\n'); 	// ignore last input
			}
			if(grow < 0)
				cout << "Invalid Input. Please try again.\n" << endl;
		}
		while(grow < 0);
		
		// input grow days
		do{
			cout << "The number of days they will multiply: ";
			cin >> days;
			// prevent infinite loop if char entered 
			if(cin.fail()){
				days = -1;						// declare false value to force whole do while to loop again
				cin.clear();				// clear input buffer
				cin.ignore(INT_MAX, '\n'); 	// ignore last input
			}
			if(days < 0)
				cout << "Invalid Input. Please try again.\n" << endl;
		}
		while(days < 1);
		
		// display initial day status	
		cout << endl;
		cout << "Day 0. The population of organisms is " << org << endl;
		
		// display x days status
		for(int i = 1; i <= days; i++){
			org = org * (1 + (grow / 100));
			cout << "Day " << i << ". The population of organisms is " << org << endl;
		}
		
		// ask user whether to continue
		cout << "\nDo you still want to continue to calculate another set of data? 'Y' or 'N'" << endl;
		cin >> c;
		cout << endl;
		
		// escape while loop 
		if(c == 'N')	
			loop = false;	
	}
	return 0;
}
