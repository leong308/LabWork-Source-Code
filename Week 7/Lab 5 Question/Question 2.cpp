// Question 2

#include <iostream>
using namespace std;

int main()
{	
	int aS, aR;
	
	// infinite loop while age is wrong
	do{
		cout << "Enter the age of Sam and Ryan: ";
		cin >> aS >> aR;
		
		if(aS < 0 || aS > 150 || aR < 0 || aR > 150)
		cout << "Invalid age.\n" << endl;
	}
	while(aS < 0 || aS > 150 || aR < 0 || aR > 150);
	
	if(aS == aR)
		cout << "Sam and Ryan have same age." << endl;
	else if (aS > aR)
		cout << "Ryan is younger than Sam." << endl;
	else
		cout << "Sam is younger than Ryan" << endl;
	
	return 0;
	
}
