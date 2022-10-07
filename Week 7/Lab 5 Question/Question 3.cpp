// Question 3

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int q;		// quantity
	double p;	// price
	cout << setprecision(2) << fixed;
	
	// infinite loop while quantity less than 0
	// or price is 0 or lesser
	do{
		cout << "Enter the quantity and price of the item: ";
		cin >> q >> p;
		
		if(q < 0)
			cout << "\nInvalid quantity." << endl;
		else if(p <= 0)
			cout << "\nInvalid price." << endl;
	}
	while(q < 0 || p <= 0);
	
	p = p * q;			// calc price
	
	// discount 10% for price => 50
	if(p >= 50)
		p = p * 0.9;
	
	cout << "The total expenses is RM" << p;
	
	return 0;
	
}
