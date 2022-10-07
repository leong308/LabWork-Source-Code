// Question 10

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// counter
	int y;
	// spending, voucher requirement, total value of voucher
	double s, x = 200, z;
	cout << setprecision(2) << fixed;
	
	// infinite loop while s < 0
	do{
		cout << "How much is your spending?" << endl;
		cin >> s;
		
		if(s < 0)
			cout << "Invalid amount.\n" << endl;
	}
	while(s < 0);
	
	// add 1 voucher for every RM200
	do{
		if(s >= x)
		{
			y = y + 1;
			x = x + 200;
		}
	}
	while(s >= x);
	
	// additional 1 voucher for s >= 600
	if(s >= 600)
		y = y + 1;
	
	// total value of voucher	
	z = y * 25;
		
	cout << "\nYou will be given " << y << " RM25 vouchers (total value of RM" << z << ")"<< endl;
	
	return 0;
	
}
