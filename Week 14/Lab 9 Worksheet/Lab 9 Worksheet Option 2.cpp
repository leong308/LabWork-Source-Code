// Lab 9 Worksheet
// Option 2
// LEONG ZI QI

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Circle{
	float centerX, centerY, radius, distance_From_Origin;
};

void closetToOrigin(Circle [], int);

int main(){
	
	const int NUM_CIRCLE = 6;
	Circle circle[NUM_CIRCLE];
	
	for(int count = 0; count < NUM_CIRCLE; count++){
		cout << "Please enter the radius of circle number " << (count + 1) << ": ";
		cin >> circle[count].radius;
		
		cout << "Please enter the x-coordinate of the center: ";
		cin >> circle[count].centerX;
		
		cout << "Please enter the y-coordinate of the center: ";
		cin >> circle[count].centerY;
		
		cout << endl;
		
		circle[count].distance_From_Origin = sqrt(pow(circle[count].centerX, 2) + pow(circle[count].centerY, 2));
	}
	
	closetToOrigin(circle, NUM_CIRCLE);
	
	return 0;
}

void closetToOrigin(Circle c[], int COUNT)
{
	float closest = c[0].distance_From_Origin;
	
	for(int count = 0; count < COUNT; count++)
		if(c[count].distance_From_Origin < closest)
			closest = c[count].distance_From_Origin;
			
	for(int count = 0; count < COUNT; count++)
		if(closest == c[count].distance_From_Origin){
			cout << fixed << setprecision(2);
			cout << "The closest circle to the origin is circle number " << (count + 1) << endl;
			cout << "The distance from the origin is " << closest << endl;
		}
}
