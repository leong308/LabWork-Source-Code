// Lab 7 Question 2
// LEONG ZI QI

#include <iostream>
#include <cmath>
using namespace std;

double calcVolume(double, double);

int main(){
	
	double radius, height;
	double volume;
	
	cout << "Please input the radius of the cylinder.\n";
	cin >> radius;
	cout << "Please input the height of the cylinder.\n";
	cin >> height;
	
	volume = calcVolume(radius, height);
	
	cout << "\nThe volume of the cylinder is " << volume << " litre.\n";
	
	return 0;
	
}

double calcVolume(double radius,  double height)
{
	double volume;
	const double PI = 3.14;
	
	volume = PI * pow(radius, 2) * height;
	
	return volume;
}
