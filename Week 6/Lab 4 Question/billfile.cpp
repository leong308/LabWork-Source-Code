// This program will read in the qunatity of a particular item and its price.
// It will then print out the total price.
// The input will come from a data file and the output will go to
// an output file.

// LEONG ZI QI

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
   	ifstream dataIn;		// defines an input stream for a data file
	ofstream dataOut;		// defines an output stream for an output file
	int quantity;			// contains the amount of items purchased
	float itemPrice;		// contains the price of each item
	float  totalBill;		// contains the total bill.  The price of all items

	dataIn.open("transaction.dat");  // This opens the file.
	dataOut.open("bill.out");

	// Fill in the appropriate code in the blank below
	cout << setprecision(2) << fixed << showpoint;  // formatted output

	cout << "Please input the quantity and price of the item: ";
	cin >> quantity >> itemPrice;

	totalBill = quantity * itemPrice;
	
	cout << "\nThe total price is " << totalBill << endl;

	return 0;
}
