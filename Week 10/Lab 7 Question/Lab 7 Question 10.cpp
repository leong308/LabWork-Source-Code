// Lab 7 Question 10
// LEONG ZI QI

#include <iostream>
using namespace std;

void showChoice();
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);

int main(){
	
	int select;
	double num1, num2, result;
	
	showChoice();
	do{
		cin >> select;
		
		if(select < 1 || select > 4)
			cout << "Invalid Input. Please try again.\n";
	}
	while(select < 1 || select > 4);
	
	cout << "Please input two numbers to perform the operation.\n";
	cin >> num1 >> num2;
	cout << endl;
	
	switch(select){
		case  1:	result = add(num1, num2);
					break;
		case  2:	result = subtract(num1, num2);
					break;
		case  3:	result = multiply(num1, num2);
					break;
		case  4:	result = divide(num1, num2);
					break;
	}
	
	cout << "The result of the two numbers after performing the operation is " << result << endl;
	
	return 0;
	
}

void showChoice()
{
	cout << "Please select an operation.\n";
	cout << "Enter 1 for addition (+)\n";
	cout << "Enter 2 for subtraction (-)\n";
	cout << "Enter 3 for multiplication (*)\n";
	cout << "Enter 4 for division (/)\n";
}

double add(double num1, double num2)
{
	double result;
	
	result = num1 + num2;
	
	return result;
}

double subtract(double num1, double num2)
{
	double result;
	
	result = num1 - num2;
	
	return result;
}

double multiply(double num1, double num2)
{
	double result;
	
	result = num1 * num2;
	
	return result;
}

double divide(double num1, double num2)
{
	double result;
	
	result = num1 / num2;
	
	return result;
}
