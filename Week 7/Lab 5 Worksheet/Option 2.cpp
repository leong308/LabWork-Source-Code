// Lab 4.4 Option 2
// LEONG ZI QI

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	
	int num;
	double price = 12, total;
	cout << setprecision(2) << fixed;
	
	cout << "How many shirts would you like?" << endl;
	cin >> num;
	
	if (num > 30)							// ignore negative input here
		price = price * 0.75;
		
	else if (num > 20 && num <=30)
		price = price * 0.80;
		
	else if (num > 10 && num <=20)
		price = price * 0.85;
		
	else if (num >= 5 && num <= 10)
		price = price * 0.90;
		
	else
		price = price;
		
	total = price * num;					// negative input will reflects to a negative total
	
	if (total >= 0)							// reject negative input here
		cout << "The cost per shirt is $" << price << " and the total cost is $" << total << endl;
		
	else
		cout << "Invalid Input: Please enter nonnegative integer" << endl;
 	
	return 0;
	
}
