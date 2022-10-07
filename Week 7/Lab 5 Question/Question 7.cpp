// Question 7

#include <iostream>
#include <iomanip>
#include <limits>	// get numeric limits
#include <ios>		// get stream size
using namespace std;

int main()
{
	char x;									// type of ticket
	int q;									// quantity
	double ec = 450, bc = 650, fc = 999, t;	// ec price, bc price, fc price
	cout << setprecision(2) << fixed;
	unsigned int padding;	// for table spacing
	
	// output ticket details
	cout << " _  __  __  __  __  __  __  __  __" << endl;
    cout << "|" << setw(padding = 16) << "Type of Ticket"     << setw(padding = 5)
		 << "|" << setw(padding = 11) << "Price (RM)" << setw(padding = 2) << "|" << endl;
    cout << " _  __  __  __  __  __  __  __  __" << endl;
	cout << "|" << setw(padding = 18) << "Ecomony Class (E)"  << setw(padding = 3) << "|" << setw(padding = 9) << ec << setw(padding = 4) << "|" << endl;
	cout << "|" << setw(padding = 19) << "Business Class (B)" << setw(padding = 2) << "|" << setw(padding = 9) << bc << setw(padding = 4) << "|" << endl;
	cout << "|" << setw(padding = 17) << "First Class (F)"    << setw(padding = 4) << "|" << setw(padding = 9) << fc << setw(padding = 4) << "|" << endl;
	
	// infinite loop while x is not E, B or F
	do{
		cout << "\nPlease choose a type of ticket: ";
		cin >> x;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');		// fetch first char only - prevent execute all
	
		if(x != 'E' && x != 'B' && x != 'F')
			cout << "Please choose either 'E', 'B' or 'F'." << endl;
	}
	while(x != 'E' && x != 'B' && x != 'F');
	
	// infinite loop while q < 0
	do{
		cout << "Please input the quantity of ticket: ";
		cin >> q;
		
		if(q < 0)
			cout << "Invalid quantity.\n" << endl;
	}
	while(q < 0);
	
	// calculate total price based on classes
	switch(x)
	{
		case 'E':	t = ec * q;
					break;
		case 'B':	t = bc * q;
					break;
		case 'F':	t = fc * q;
					break;	
	}
	
	cout << "\nYou need to pay $" << t << " for your " << x << " class ticket/s." << endl;
	
	return 0;
	
}
