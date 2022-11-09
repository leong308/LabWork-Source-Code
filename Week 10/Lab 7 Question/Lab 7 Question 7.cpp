// Lab 7 Question 7
// LEONG ZI QI

#include <iostream>
using namespace std;

void checkCharRange(char);

int main(){
	
	char ch;
	
	cout << "Please enter a character in capital letter.\n";
	cin >> ch;
	checkCharRange(ch);
	
	return 0;
	
}

void checkCharRange(char ch)
{
	// cannot put into for loop
	// will keep looping causing multiple outputs
	if(ch < 'A' || ch > 'Z')
		cout << "Invalid Range!\n";
	else
		for(char check = 'A'; check <= 'Z'; ++check)
			if(check == ch && check <= 'M')
				cout << "First Half!\n";
			else if(check == ch && check <= 'Z')
				cout << "Second Half!\n";
	
}
