// LEONG ZI QI

#include <iostream>
using namespace std;

int main()
{
	char letter = 'a';

    do
	{
        cout << "Please enter a letter." << endl;
        cout << "Only letter 'x' can terminate the program." << endl;
        cin >> letter;
        
        cout << "\nThe letter you entered is " << letter << "\n" << endl;
    }
    while (letter != 'x');
	
	cout << "Program is terminated." << endl;
	
    return 0;	
}
