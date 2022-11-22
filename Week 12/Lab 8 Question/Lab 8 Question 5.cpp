// Lab 8 Question 5
// LEONG ZI QI

#include <iostream>
using namespace std;

int main(){
	
	int getNum[10];
	int i, j, V;
	
	cout << "Enter 10 integer value :\n";
	for(i = 0; i < 10; i++){
		cout << "Array [" << i << "] = ";
		cin >> getNum[i];
	}
	
	cout << "\nEnter V value : ";
	cin >> V;
	cout << "Enter i value : ";
	cin >> i;
	
	for(j = 9; j >= 0; j--){
		if(i < j && i != j)
			getNum[j] = getNum[j - 1];
		else if(i == j)
			getNum[j] = V;
	}
	
	cout << "\nNew value in the array :";
	for(i = 0; i < 10; i++){
		cout << "\nArray [" << i << "] = " << getNum[i];
	}
	
	return 0;
}
