// Question 11

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	// hours, basic charge, total
	double h, bc = 2, t;
	cout << setprecision(2) << fixed;
	
	// infinite loop while h < 0 or h > 24
	do{
		cout << "Total hours parked: ";
		cin >> h;
		h = ceil(h);				// round up (+1 hour if exceeds)
		
		if(h < 0 || h > 24)
			cout << "Invalid hour.\n" << endl;
	}
	while(h < 0 || h > 24);			// assume no h > 24
	
	// calculate parking charge
	if(h <= 3)
		t = bc;
	else
	{
		t = bc + (h - 3) * 0.5;
		// hard cap at 10
		if(t > 10)
			t = 10;
	}	
	
		cout << "The parking charges are RM" << t << endl;
	
	return 0;
	
}
