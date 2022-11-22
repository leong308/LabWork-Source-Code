// Lab 8 Question 9
// LEONG ZI QI

#include <iostream>
using namespace std;

int reverseArray(int x[]);

int main(){
	
	int i, x[10];
	
	cout << "Enter 10 integer values:\n";
	for(i = 0; i < 10; i++)
		cin >> x[i];
	
	x[10] = reverseArray(x);
	
	cout << "Reversed array:\n";
	for(i = 0; i < 10; i++)
		cout << x[i] << " ";
	
	return 0;
}

int reverseArray(int x[])
{
	int temp;
	for(int i = 9; i > 4; i--){
		temp = x[i];
		x[i] = x[9 - i];
		x[9 - i] = temp;
	}
	return x[10];
}
