// Lab 8 Question 7
// LEONG ZI QI

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double tempAvg(double temp[], int);
double highestTemp(double temp[], int);
double lowestTemp(double temp[], int);

int main(){
	
	int i, numTemp;
	double avgTemp, maxTemp, minTemp;
	
	do{
		cout << "Please input the number of temperatures to be read.\n";
		cin >> numTemp;
		
		if(numTemp < 1)
			cout << "Invalid Input. Please try again.\n";
		else if(numTemp > 50)
			cout << "This program will only accepts less than 50 temperatures. Please try again.\n";
	}
	while(numTemp < 1 || numTemp > 50);
	// declare array
	double temp[numTemp] = {0};
	
	for(i = 0; i < numTemp; i++){
		cout << "Input temperature " << i + 1 << ":\n";
		cin >> temp[i];
	}
	
	avgTemp = tempAvg(temp, numTemp);
	maxTemp = highestTemp(temp, numTemp);
	minTemp = lowestTemp(temp, numTemp);
	
	cout << setprecision(2) << fixed;
	cout << "\nThe average temperature is " << avgTemp;
	cout << "\nThe highest temperature is " << maxTemp;
	cout << "\nThe lowest temperature is " << minTemp;
	
	return 0;
}

double tempAvg(double temp[], int tempCount)
{
	double sum, average;
	for(int i = 0; i < tempCount; i++)
		sum += temp[i];
	return average = sum / tempCount;
}

double highestTemp(double temp[], int tempCount)
{
	return *max_element(temp, temp+tempCount);
}

double lowestTemp(double temp[], int tempCount)
{
	return *min_element(temp, temp+tempCount);
}
