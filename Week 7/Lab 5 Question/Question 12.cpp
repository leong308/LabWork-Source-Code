// Question 12

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a, b, x, y;
	
	srand(time(0));
	a = (rand() % 12) + 1;
	b = (rand() % 12) + 1;
	x = a * b;
	
	cout << "How much is " << a << " times " << b << " ? ";
	cin >> y;

	if(y == x)
		cout << "Very Good." << endl;
	else
	{
		cout << "Sorry, incorrect answer." << endl;
		cout << a << " x " << b << " = " << x;
	}

	return 0;
	
}
