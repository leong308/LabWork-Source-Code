// This program will determine the batting average of a player. 
// The number of hits and at bats are set internally in the program.

// PLACE YOUR NAME HERE

#include <iostream>
#include <iomanip>
using namespace std;


const int AT_BAT = 421;
const int HITS = 123;

int main()
{
	double batAvg;
	
	batAvg = HITS / static_cast<double> (AT_BAT);		 	//an assignment statement
	cout << "The batting average is " << batAvg << endl;   			//output the result

	return 0;	
}

