// Question 6

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int s;								// shirt
	double p = 12, t;					// price, total
	cout << setprecision(2) << fixed;	// output in 2 d.p.
	
	// infinite loop while s < 0
	do{
		cout << "How many shirts would you like?" << endl;
		cin >> s;
		
		if(s < 0)
		cout << "Invalid Input: Please enter a nonnegative integer.\n" << endl;
	}
	while(s < 0);
	
	// determine discount
	if(s > 30)
		p = p * 0.75;
	else if(s > 21)
		p = p * 0.80;
	else if(s > 11)
		p = p * 0.85;
	else if(s > 4)
		p = p * 0.90;
	else
		p = p * 1.00;
	
	t = s * p;			// calc total
	
	cout << "The cost per shirt is $" << p << " and the total cost is $" << t << endl;
	
	return 0;
	
}
