// Week 5 C++ Challenge Question
/*
Write a program that calculates the price of gasoline.
The program should ask the user to input the volume of gasoline in litres.
It should then display the volume in gallons and the corresponding prices.
Assume that the price of gasoline is $3.58 per gallon. 
Note that 1 gallon = 4.546 litres
*/
// LEONG ZI QI

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	
	double gallon, litre, price, total;														// declare double var
	
	cout << "Please input the volume of gasoline in litres: ";								// fetch litre	
	cin >> litre;
	
	price = 3.58;
	gallon = litre / 4.56;																	// cal 1 gallon = 4.546 litre
	total = gallon * price;																	// cal price per gallon
	
	cout << setprecision(2) << fixed;
	cout << "\n\nThe price($) of gasoline per gallon: " << setw(14) << right << price;		// output price of 1 gallon
	
	cout << setprecision(3) << fixed;														// output vol in gallon
	cout << "\n\nThe volume of gasoline in gallons: " << setw(16) << right <<  gallon;			
	
	cout << setprecision(3) << fixed;														// output total price
	cout << "\nThe total($) for " << gallon << " gallon of gasoline: "
		 << setprecision(2) << fixed << setw(8) << right << total << endl;
	
	return 0;
	
}
