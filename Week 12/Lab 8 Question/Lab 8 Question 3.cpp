// Lab 8 Question 3
// LEONG ZI QI

#include <iostream>
using namespace std;

int main(){
	
	int array_A[10], array_B[10], product[10];
	int i;
	
	cout << "Set 1\n";
	for(i = 0; i < 10; i++){
		cout << "Please input an integer value into array_A[" << i << "] : ";
		cin >> array_A[i];
	}
		
	cout << "\nSet 2\n";
	for(i = 0; i < 10; i++){
		cout << "Please input an integer value into array_B[" << i << "] : ";
		cin >> array_B[i];
	}
	cout << endl;
		
	for(i = 0; i < 10; i++){
		product[i] = array_A[i] * array_B[i];
		cout << product[i] << " = " << array_A[i] << " * " << array_B[i] << endl;
	}
		
	return 0;
}
