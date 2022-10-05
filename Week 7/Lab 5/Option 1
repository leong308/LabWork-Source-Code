// Lab 4.4 Option 1
// LEONG ZI QI

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	
	double q1, q2, q3, q4, avg;
	cout << setprecision(2) << fixed;
	
	do 
	{
		cout << "Please input your water bill for quarter 1: " << endl;
		cin >> q1;
	if(q1 < 0) 
        cout << "\nPlease enter a valid water bill for quarter 1." << endl;
	}
	while(q1 < 0);
	
	do 
	{
		cout << "Please input your water bill for quarter 2: " << endl;
		cin >> q2;
	if(q2 < 0) 
        cout << "\nPlease enter a valid water bill for quarter 2." << endl;
	}
	while(q2 < 0);
	
	do 
	{
		cout << "Please input your water bill for quarter 3: " << endl;
		cin >> q3;
	if(q3 < 0) 
        cout << "\nPlease enter a valid water bill for quarter 3." << endl;
	}
	while(q3 < 0);
	
	do 
	{
		cout << "Please input your water bill for quarter 4: " << endl;
		cin >> q4;
	if(q4 < 0) 
        cout << "\nPlease enter a valid water bill for quarter 4." << endl;
	}
	while(q4 < 0);
		
	avg = (q1 + q2 + q3 + q4) / 12;
	
	cout << "Your average monthly bill is $" << avg << ". ";
	
	if (avg >= 75)
		cout << "You are using excessive amounts of water." << endl;
		
	else if (avg >= 25)
		cout << "You are using a typical amount of water." << endl;
		
	else
		cout << "Excellent! You did great in conserving water.";
		
	return 0;
	
}
