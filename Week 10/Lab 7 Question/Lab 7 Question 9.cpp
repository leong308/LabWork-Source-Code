// Lab 7 Question 9
// LEONG ZI QI

#include <iostream>
#include <algorithm>
using namespace std;

void zero_small(int&, int&);

int main(){
	
	int a, b;
	
	cout << "Please input 2 integer values.\n";
	cin >> a >> b;
	
	// won't enter function if both the same
	if(a != b)
		zero_small(a, b);
	
	cout << "\nAfter comparison, the smaller number had set to 0.\n";
	cout << "The 2 numbers are " << a << " and " << b << endl;
	
	return 0;
	
}

void zero_small(int& a, int& b)
{
	if(a == min(a, b))
		a = 0;
	else
		b = 0;
}
