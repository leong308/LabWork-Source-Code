// Lab 7 Question 6
// LEONG ZI QI

#include <iostream>
#include <iomanip>
using namespace std;

double totalPrice(double, int);
double DiscountPrice(double, double&);

int main(){
	
	int qty;
	double price, total, discountRate = 0.9, discp;
	
	cout << setprecision(2) << fixed;
	
	cout << "Please enter the unit price and quantity of the item.\n";
	cin >> price >> qty;
	
	total = totalPrice(price, qty);
	cout << "\nThe total price before discount is RM" << total << endl;
	
	discp = DiscountPrice(total, discountRate);
	cout << "The discounted price is RM" << discp << endl;
	
	return 0;
}

double totalPrice(double price, int qty)
{
	double total;
	total = price * qty;
	return total;
}

double DiscountPrice(double total, double& discountRate)
{
	double discp;
	discp = total * discountRate;
	
	return discp;
}


