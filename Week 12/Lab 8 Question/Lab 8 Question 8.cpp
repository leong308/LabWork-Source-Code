// Lab 8 Question 8
// LEONG ZI QI

#include <iostream>
using namespace std;

int main(){
	
	int i, j, readNum[20];
	bool repeat = false; 
	
	cout << "You are required to enter 20 numbers within 10 and 100 without repeating them.\n";
	// fill in array spaces and validations on data
	for(i = 0; i < 20; i++){
		do{
			cout << "\nPlease enter number " << i + 1 << ": ";
			cin >> readNum[i];
			
			if(readNum[i] < 10 || readNum[i] > 100){
				cout << "Please enter a number between 10 and 100 only. Please try again.\n";
				repeat = true;
			}
			else{
				for(j = i; j >= 0; j--){
					if(readNum[i] == readNum[j] && i != j){
						cout << "Value cannot be repeated. Please try again.\n";
						repeat = true;
						readNum[i] = -777;
					}
				}
				if(readNum[i] != -777)
					repeat = false;
			}	
		}
		while(repeat == true);
	}
	// print array values
	cout << "The unique numbers list\n";
	for(i = 0; i < 20; i++)
		cout << i + 1 << ". " << readNum[i] << endl;
	
	return 0;
}
