// Lab 6 Question 6
// (b) Do - While loop
// LEONG ZI QI

#include <iostream>
using namespace std;

int main(){
	
	int i = 0, j = 0, num;
	bool terminate = false;
	
	do{
		cout << "To terminate program, please enter 0." << endl;
		cout << "Please enter a number:" << endl;
		cin >> num;
		cout << endl;
		
		if(num == 0)
			terminate = true;
		else if(num > 0)
			i++;
		else
			j++;
	}
	while(terminate == false);
	
	if(num == 0 && i == 0 && j == 0)
		cout << "No data available." << endl;
	else{
		cout << "Positive numbers entered: " << i << endl;
		cout << "Negatve numbers entered: "	 << j << endl;
	}
	
	return 0;
	
}
