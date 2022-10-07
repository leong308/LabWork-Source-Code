// Question 5

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int bp = 1500;	// basic pay
	int r, l, rb, lb, gp;	// declare recruite, leave, recruite bonus, leave bonus and gross pay
	unsigned int padding;	// for table spacing

	// infinite loop while recruit < 0
	do{
		cout << "How many students did you recruited in this month?" << endl;
		cin >> r;
		
		if(r < 0)
			cout << "Invalid number of student. Please try again." << endl;
	}
	while(r < 0);

	// infinite loop while leave < 0
	do{
		cout << "How many students leave the college within a month?" << endl;
		cin >> l;
		
		if(l < 0)
			cout << "Invalid number of student. Please try again." << endl;
	}
	while(l < 0);
	
	// reward 60 per student after 5 students
	if(r > 5)
		rb = 60 * (r - 5);
	else
		rb = 0;

	// reward 100 if leaver < 2
	if(l < 2)
		lb = 100;
	else
		lb = 0;
		
	gp = bp + rb + lb;		// total up
	
	cout << endl << "----------- YOUR PAYMENT -----------" << endl;
	
	// output gross pay details
	cout << "__  __  __  __  __  __  __  __  __" << endl;
    cout << "|" << setw(padding = 14) << "Salary"         << setw(padding = 9) << "|" << setw(padding = 8) << "Amount" << setw(padding = 3) << "|" << endl;
    cout << "__  __  __  __  __  __  __  __  __" << endl;
	cout << "|" << setw(padding = 16) << "Basic Pay"      << setw(padding = 7) << "|" << setw(padding = 8) << bp       << setw(padding = 3) << "|" << endl;
	cout << "|" << setw(padding = 18) << "Recruite Bonus" << setw(padding = 5) << "|" << setw(padding = 8) << rb       << setw(padding = 3) << "|" << endl;
	cout << "|" << setw(padding = 17) << "Leaver Bonus"   << setw(padding = 6) << "|" << setw(padding = 8) << lb       << setw(padding = 3) << "|" << endl;
	cout << "__  __  __  __  __  __  __  __  __" << endl;	
	cout << "|" << setw(padding = 16) << "Gross Pay"      << setw(padding = 7) << "|" << setw(padding = 8) << gp       << setw(padding = 3) << "|" << endl;		

	return 0;
	
}
