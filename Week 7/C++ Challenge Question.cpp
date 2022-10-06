// Week 7 C++ Challenge Question
// LEONG ZI QI

#include <iostream>
#include <iomanip>
#include <limits>	// get numeric limits
#include <ios>		// get stream size
using namespace std;

int main()
{
	char s;
	const int x = 1100, y = 4900, z = 16400;				// x as air, y as water, z as steel
	double d, t;								// distance and time
	cout << setprecision(4) << fixed;					// setprecision for the t output
	
	cout << "The following table shows the approximate speed of sound in air, water, and steel.\n" << endl;
	
	unsigned int padding;							// table format
    
    	cout << setw(padding = 8) << "Medium" << setw(padding = 3) << "|" << setw(padding = 14) << "Speed" << setw(padding = 11) << "|\n" << endl;
	cout << setw(padding = 7) << "Air" << setw(padding = 4) << "|" << setw(padding = 6) << x << " feet per second" << setw(padding = 2) << "|" << endl;
	cout << setw(padding = 8) << "Water" << setw(padding = 3) << "|" << setw(padding = 6) << y << " feet per second" << setw(padding = 2) << "|" << endl;	
	cout << setw(padding = 8) << "Steel" << setw(padding = 3) << "|" << setw(padding = 6) << z << " feet per second" << setw(padding = 2) << "|" << endl;
	
	do													// User input medium
	{
		cout << "\nPlease select a medium - 'A', 'B', or 'C'" << endl;
		cin >> s;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');						// fetch first char only
	
	if (s != 'A' && s != 'B' && s != 'C')									// loop if input is not A,B or C
		cout <<	"Please enter either 'A', 'B' or 'C' only." << endl;
	}
	while (s != 'A' && s != 'B' && s != 'C');								

	do 																										
	{
		cout << "\nPlease enter the distance a sound wave will travel in " << s << " medium." << endl;	// user input distance	
		cin >> d;
		
	if(d < 0) 
        	cout << "Please enter a valid distance of the sound wave." << endl;				// loop if d < 0
	}
	while(d < 0);
	
	switch (s)
	{
		case 'A':   t = d / x;
			    break;
		case 'B':   t = d / y;
			    break;
		case 'C':   t = d / z;
			    break;
	}
	
	cout << "\nThe amount of time it will take to travel in " << s << " medium is " << t << " seconds."<< endl;

	return 0;
	
}
