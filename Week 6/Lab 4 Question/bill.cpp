// This program will read in the quantity of a particular item and its price.
// It will then print out the total price.
// The input will come from the keyboard and the output will go to the screen.

//  LEONG ZI QI

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()

{
	int   quantity;			// contains the amount of items purchased
	float itemPrice;		// contains the price of each item
	float totalBill;		// contains the total bill. 
	string item;			// contains the name of item 

	cout << setprecision(2) << fixed << showpoint;  //formatted output

	cout << "Please input the name of the item bought" << endl;
	getline(cin,item);		// include multiple terms

	cout << "Please input the number of items bought" << endl;   
	cin >> quantity;

	cout << "Please input the price of each item" << endl;
	cin >> itemPrice;
	
	totalBill = quantity * itemPrice;
	
	cout << "\nThe item you bought is " << item;
	cout << "\nThe total bill is: $" << totalBill << endl;

	return 0;
}
