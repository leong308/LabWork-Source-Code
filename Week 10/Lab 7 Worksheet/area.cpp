#include <iostream>
#include <iomanip>
using namespace std;

// LEONG ZI QI
// LAB 7 WORKSHEET 6.3

// prototype of the function calcArea
float calcArea(float, float);

int main()

{
  float width, length, area;
  
  
  cout << setprecision(2) << fixed << showpoint;

  cout << "Enter width and length of a rectangle :" ;
  cin >> width >> length;
  
  area = calcArea(width, length);
  cout << "The area of a rectangle is  " << area << endl;
  
  return 0;
}

// This function takes in width and length of a retangle and calculate the area of the rectangle
float calcArea(float width, float length) // fill in the return type for calcArea
{
    float area;
	area = width * length;
	
	return area;
}
	
