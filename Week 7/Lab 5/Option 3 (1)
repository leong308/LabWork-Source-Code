// Lab 4.4 Option 3 (1)
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

	do 		// infinite loop if user doesn't input "I" or "O"
	{
	cout << "Please input \"I\" if you are in-state or \"O\" if you are out-of-state:" << endl;
	cin >> x;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	// fetch first char only
		
	if(x == 'I') 
        total = total + ist;
    else if (x == 'O')
		total = total + ost;
	else
		cout << "Invalid Input.\n" << endl;
	}
	while(x != 'I' && x != 'O');
	
	do 		// infinite loop if user doesn't input "Y" or "N"
	{
	cout << "Please input \"Y\" if you are in-state or \"N\" if you are out-of-state:" << endl;
	cin >> y;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	// fetch first char only
		
	if(x == 'I', y == 'Y') 		
        total = total + isrb;
    else if (x == 'O', y == 'Y')
		total = total + osrb;
	else if (y == 'N')
		total = total;
	else
		cout << "Invalid Input.\n" << endl;
	}
	while(y != 'Y' && y != 'N');
	
	cout << "\nYour bill for this semester is $" << total << endl;
	
	return 0;
	
}
