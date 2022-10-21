// Lab 6 Question 8
// LEONG ZI QI

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	int i;								// counter
	double price, total = 0;			// price, total
	cout << setprecision(2) << fixed;
	
	// infinite loop to get value
	// until user use -1 as score to terminate program
	for(i = 0; price != -1; i++){
		// infinite loop if user key in false range
		do{
			cout << "Key in (-1) to stop and print receipt." << endl;
			cout << "The price of item " << (i + 1) << " is:" << endl;		
			cin >> price;
			cout << endl;
		
			// prevent infinite loop if char entered 
			if(cin.fail()){
				price = -2;					// declare false value to force whole do while to loop again
				cin.clear();				// clear input buffer
				cin.ignore(INT_MAX, '\n'); 	// ignore last input
			}
			if(price <= 0 && price != -1)
				cout << "Invalid Input. The price must be more than 0. Please try again.\n" << endl;
		}
		while(price <= 0 && price != -1);
		
		// prevent final loop affects total
		if(price != -1)
			total = total + price;
	}
	
	if(total > 0){
		cout << "You had purchased " << (i - 1) << " items." << endl;
		cout << "Total is $" << total << endl; 
	}
	else
		cout << "No data." << endl;
	
	return 0;
	
}
