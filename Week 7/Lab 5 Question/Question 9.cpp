// Question 9

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int c;			// calls
	double bp = 50, p, b;	// base price, price, tel bill
	cout << setprecision(2) << fixed;
	
	// infinite loop while calls < 0
	do{
		cout << "Enter the total calls: ";
		cin >> c;
		
		if(c < 0)
			cout << "Invalid input\n" << endl;
	}
	while(c < 0);
	
	// calc tel bill
	if(c <= 100)
		b = bp;
	else if(c <= 150)
		b = bp + 0.6 * (c - 100);
	else if(c <= 180)
		b = bp + 0.6 * 50 + 0.5 * (c - 150);
	else
		b = bp + 0.6 * 50 + 0.5 * 30 + 0.4 * (c - 180);
		
	cout << "Your telephone bill is RM" << b << endl;
	
	return 0;
	
}
