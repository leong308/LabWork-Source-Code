// Lab 8 Question 2
// LEONG ZI QI

#include <iostream>
using namespace std;

void filterNum(int array[10], int&, int&);

int main(){
	
	int array[10] = {0}, filter = 0, sum = 0;
	
	for(int i = 0; i < 10; i++){
		cout << "Enter number " << i + 1 << " : ";
		cin >> array[i];
	}
	
	filterNum(array, filter, sum);
	
	cout << "\nThere are " << filter << " numbers more than 100 and their total values is " << sum << endl;
	
	return 0;
}

void filterNum(int array[10], int& filter100, int& sumFilter)
{
	for(int i = 0; i < 10; i++)
		if(array[i] > 100){
			filter100++;
			sumFilter += array[i];
		}
}
