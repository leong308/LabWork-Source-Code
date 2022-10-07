// Question 8

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int x;
	double celcius, fahrenheit;
	cout << setprecision(2) << fixed;
	
	cout << "Conversion Program" << endl;
	cout << "1. Convert Celcius to Fahrenheit" << endl;
	cout << "2. Convert Fahrenheit to Celcius" << endl;
	
	// infinite loop while x is not 1 or 2
	do{
		cout << "\nPlease enter an option: ";
		cin >> x;
		
		if(x != 1 && x!= 2)
			cout << "Invalid option" << endl;
	}
	while(x != 1 && x!= 2);
	
	// execution of selection
	if(x == 1)
	{
		cout << "\nEnter the temperature in Celcius: ";
		cin >> celcius;
		
		fahrenheit = (9.0 / 5) * celcius + 32;
		
		cout << celcius << " Celcius is " << fahrenheit << " Fahrenheit" << endl;
	}
	else
	{
		cout << "\nEnter the temperature in Fahrenheit: ";
		cin >> fahrenheit;
		
		celcius = (fahrenheit - 32) / (9.0 / 5);
		
		cout << fahrenheit << " Fahrenheit is " << celcius << " celcius" << endl;		
	}
	
	return 0;
	
}
