//  This program will bring in two prices and two quantities of items 
//  from the keyboard and print those numbers in a formatted chart.

// LEONG ZI QI

#include <iostream>
#include <iomanip>  	// Fill in the code to bring in the library for 
                      	// formatted output.
using namespace std;


int main()

{
	
	float price1, price2;	      // The price of 2 items
	int   quantity1, quantity2;   // The quantity of 2 items


	cout << setprecision(2) << fixed << showpoint;
	cout << "Please input the price and quantity of the first item" << endl;
	cin >> price1 >> quantity1;

	cout << "Please input the price and quantity of the second item" << endl;
	cin >> price2 >> quantity2;	

	cout << setw(5) << "\nPRICE" << setw(12) << "QUANTITY\n";
	cout << setw(5) << price1 << setw(8) << quantity1 << endl;
	cout << setw(5) << price2 << setw(8) << quantity2;

	return 0;

}
