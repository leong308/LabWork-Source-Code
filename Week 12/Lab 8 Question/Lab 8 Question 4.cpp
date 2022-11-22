// Lab 8 Question 4
// LEONG ZI QI

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	string months[12] = {"January", "February", "March", "April", "May", "June",
						 "July", "August", "September", "October", "November", "December"};
	int i, j, quantity;
	int quarterQty[4] = {0};
	double price = 5.5;
	
	cout << setprecision(2) << fixed;
	
	for(i = 0; i < 12; i++){
		cout << "Enter quantity sold for " << months[i] << " : ";
		cin >> quantity;
		
		for(j = 0; j < 4; j++)
			if((i + 1) <= ((j + 1) * 3)){
				quarterQty[j] += quantity;
				j = 4;
			}
	}	
	
	cout << "\nQuarterly Sales: \n";
	for(i = 0; i < 4; i++)
		cout << "Quarter " << i + 1 << " : " << quarterQty[i] * price << endl;
	
	
	return 0;
}
