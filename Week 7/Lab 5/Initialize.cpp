// This program tests whether or not an initialized value
// is equal to a value input by the user 

// PLACE YOUR NAME HERE

#include <iostream>
using namespace std;

int main( )
{
 	int num1,				// num1 is not initialized
		num2 = 5;           // num2 has been initialized to 5

    cout << "Please enter an integer" << endl;
	cin >> num1;


	cout << "num1 = " << num1 << " and num2 = " << num2 << endl;

    if (num1 == num2) 
	{
		cout << "\nThe values are the same." << endl;
		cout << "Hey, that's  a coincidence!" << endl; 
	}
	else													// else cannot have a statement
		cout << "The values are not the same" << endl;
			
    return 0;	
    
}
