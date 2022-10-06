// C++ Challenge Question 1

#include <iostream>
using namespace std;

int main ()
{
	
	int cYear, bYear, age;
	
	cout << "Please input current year and your year of birth:" << endl;
	cin >> cYear >> bYear;
	
	age = cYear - bYear;			// calc age
	
	if (age >= 18 && age <= 28)
		cout << "You are eligible." << endl;
	
	else if (age < 0)
		cout << "Please input the correct current year and your year of birth." << endl;
		
	else 
		cout << "You are not eligible." << endl;
	
	return 0;
	
}
