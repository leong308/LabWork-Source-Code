// LAB 7 WORKSHEET 6.5 - OPTION 1
// LEONG ZI QI

#include <iostream>
using namespace std;

void swapNum(int&, int&);

int main(){
	
	int first, second;
	
	cout << "Enter the first number\n";
	cout << "Then hit enter\n";
	cin >> first;
	cout << "Enter the second number\n";
	cout << "Then hit enter\n";
	cin >> second;
	
	cout << "\nYou input the numbers as " << first << " and " << second << ".\n";
	swapNum(first, second);
	
	cout << "\nAfter swapping, the first number has the value of " << first << " which was the value of the second number\n";
	cout << "The second number has the value of " << second << " which was the value of the first number\n";
	
	return 0;
}

void swapNum(int& first, int& second)
{
	int temp;
	temp = first;
	first = second;
	second = temp;
}
