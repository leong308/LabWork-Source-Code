// Lab 6 Worksheet Option 1
// LEONG ZI QI

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	int i;																// for loop counter
	int x = 1;															// counter for person
	int bselect = 0;													// select beverage
	int bvote[4] = {0};													// beverage votes
	string beverage[4] = {"Coffee", "Tea", "Coke", "Orange Juice"};		// beverages
	
	// enter while if user didn't enter bselect = -1
	while(bselect != -1){
		// to modify output clarity
		if(x != 1)
			cout << endl;
			
		// display beverage list
		for(i = 0; i < 4; i++)
			cout << (i + 1) << ". " << beverage[i] << endl;
		
		cout << "\nPlease input the favorite beverage of person #" << x << endl;
		cout << "Choose 1, 2, 3, or 4 from the above menu or -1 to exit the program" << endl;
		cin >> bselect;
		
		// while bselect matches the beverage list selections
		if(bselect != -1 && bselect >= 1 && bselect <= 4){
			
			// update counter
			x++;
			
			// update vote
			if(bselect == 1)
				bvote[0]++;
			else if(bselect == 2)
				bvote[1]++;
			else if(bselect == 3)
				bvote[2]++;
			else
				bvote[3]++;
		}
		else if(bselect != -1 && (bselect < 1 || bselect > 4))
			cout << "Invalid input. Please try again." << endl;
	}
	
	// user exit immediately
	if(x == 1)
		cout << "\nNo data exists." << endl;
	else{
		cout << "\nThe total number of people surveyed is " << (x - 1) << ". The results are as follows:\n" << endl;
		
		// print table header
		cout << "Beverage Number of Votes" << endl;
		cout << "************************" << endl;
		cout << "| " << setw(12) << left << "Beverage" << " |" << setw(6) << right << "Votes" << " |" << endl;
		cout << "_______________________" << endl;
		
		// print table data
		for(i = 0; i < 4; i++)
			cout << "| " << setw(12) << left << beverage[i] << " |" << setw(6) << right << bvote[i] << " |" << endl;
	}
	
	return 0;
	
}
