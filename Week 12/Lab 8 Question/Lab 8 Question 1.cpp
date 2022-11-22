// Lab 8 Question 1
// LEONG ZI QI

#include <iostream>
using namespace std;

int modifyArray();
int sumFLarray(int myArray[10]);
void sumAvgArray(int myArray[10], int&, double&);

int main(){
	
	int myArray[10] = {62, 73, 158, 170, 180, 156, 177, 155, 180, 165};
	int x, sum = 0;
	double avg;
	
	// modify forth element
	myArray[3] = modifyArray();
	
	// sum of first and last array element
	x = sumFLarray(myArray);
	cout << "\nThe sum of first and last array element is " << x << endl;
	
	sumAvgArray(myArray, sum, avg);
	cout << "\nThe sum and average of all values in the array is " << sum << " and " << avg << endl;
	
	return 0;
}

int modifyArray()
{
	int y;
	cout << "Please modify the forth element of the array: ";
	cin >> y;
	
	return y;
}
