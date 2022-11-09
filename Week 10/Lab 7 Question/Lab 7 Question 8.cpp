// Lab 7 Question 8
// LEONG ZI QI

#include <iostream>
#include <algorithm>
using namespace std;

int getRange(int a[3]);

int main(){
	
	int a[3], diff;
	
	cout << "Please input 3 integer values.\n";
	cin >> a[0] >> a[1] >> a[2];
	diff = getRange(a);
	
	cout << "\n\nThe different between the lowest value and highest value is " << diff << endl;
	
	return 0;
	
}

int getRange(int a[3])
{
	int diff;
	// need to add {} to include all of the values that needed to be compare
	diff = max({a[0], a[1], a[2]}) - min({a[0], a[1], a[2]});
	
	return diff;
}
