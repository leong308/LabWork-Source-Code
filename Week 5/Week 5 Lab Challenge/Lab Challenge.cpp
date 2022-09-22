#include <iostream>
#include <iomanip>
using namespace std;

const double tax = 0.07;


int main()
{
	double price1 = 15.95;
	double price2 = 24.95;
	double price3 = 6.95;
	double price4 = 12.95;
	double price5 = 3.95;
	double subtotal;
	double salestax;
	double total;
	
	cout << "Item 1 = $" << price1 << endl;
	cout << "Item 2 = $" << price2 << endl;
	cout << "Item 3 = $" << price3 << endl;
	cout << "Item 4 = $" << price4 << endl;
	cout << "Item 5 = $" << price5 << endl;
	
	subtotal = price1 + price2 + price3 + price4 + price5;
	
	cout << endl << "Subtotal of the sale = $" << subtotal << endl;
	
	salestax = subtotal * tax;
	
	cout << "Amount of sales tax = $" << setprecision(2) << fixed << salestax << endl;
	
	total = subtotal + salestax;
	
	cout << "Total = $" << total << endl;
	
	return 0;
}
