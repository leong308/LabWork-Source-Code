// Lab 8 Question 6
// LEONG ZI QI

#include <iostream>
using namespace std;

int main(){
	
	int i, j, arrRating[10];
	
	// obtain 10 ratings
	for(i = 0; i < 10; i++){
		do{
			cout << "Please rate between 1 - 5 : ";
			cin >> arrRating[i];
			
			if(arrRating[i] < 1 || arrRating[i] > 5)
				cout << "Invalid Input. Please try again.\n";
		}
		while(arrRating[i] < 1 || arrRating[i] > 5);
	}
	
	cout << "\nThe Rating List:";
	
	for(i = 1; i <= 5; i++){
		cout << endl << i << " ";
		for(j = 0; j < 10; j++){
			if(arrRating[j] == i)
				cout << "*";
		}
	}
	
	return 0;
}
