// LAB 7 WORKSHEET 6.5 - OPTION 2
// LEONG ZI QI

#include <iostream>
#include <iomanip>
using namespace std;

double calcSpeed(double, double);

int main(){
	
	double miles, hours, speed;
	cout << setprecision(2) << fixed;
	
	cout << "Please input the miles traveled\n";
	cin >> miles;
	cout << "Please input the hours traveled\n";
	cin >> hours;
	
	speed = calcSpeed(miles, hours);
	
	cout << "Your speed is " << speed << " miles per hour\n";
	
	return 0;
	
}

double calcSpeed(double miles, double hours)
{
	double speed = miles / hours;
	return speed;
}
