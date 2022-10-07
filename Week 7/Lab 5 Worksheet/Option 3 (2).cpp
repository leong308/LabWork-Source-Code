// Lab 4.4 Option 3 (2)
// LEONG ZI QI

#include <iostream>
#include <limits>	// get numeric limits
#include <ios>		// get stream size
using namespace std;

int main()
{
	
	double ist = 3000;
	double ost = 4500;
	double isrb = 2500;
	double osrb = 3500;
	double total;
	char x, y;
	
	cout << "Please input \"I\" if you are in-state or \"O\" if you are out-of-state:" << endl;
	cin >> x;
	
	cout << "\nPlease input \"Y\" if you require room and board and \"N\" if you do not:" << endl;
	cin >> y;
	
	switch (y)
	{
		case 'Y':	
		
		switch (x)
		{
		case 'I':   total = total + ist + isrb;
					break;			
		case 'O':   total = total + ost + osrb;
					break;
		}
		break;
		
		case 'N':
		
		switch (x)
		{
		case 'I':   total = total + ist; 
					break;
		case 'O':   total = total + ost;
					break;
		}
	}
	
		cout << "\nYour bill for this semester is $" << total << endl;
	
	return 0;
	
}
