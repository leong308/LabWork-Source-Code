// Lab 6 Worksheet Option 2
// LEONG ZI QI

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	
	int time, i;				// time, time counter
	double d[50] = {0}, h;		// distance data set, height
	const double g = 9.8;		// gravity
	
	do{
		cout << "Please input the time of fall in seconds:" << endl;
		cin >> time;
		
		// prevent infinite loop if char entered 
		if(cin.fail()){
			time = -1;					// declare false value to force whole do while to loop again
			cin.clear();				// clear input buffer
			cin.ignore(INT_MAX, '\n'); 	// ignore last input
		}
		else if(time >= 0){
			do{
				cout << "Please input the height of the bridge in meters:" << endl;
				cin >> h;
				
				// prevent infinite loop if char entered 
				if(cin.fail()){
					time = -1;					// declare false value to force whole do while to loop again
					cin.clear();				// clear input buffer
					cin.ignore(INT_MAX, '\n'); 	// ignore last input
				}
				else if(h >= 0){
					cout << endl;
					
					// loop
					for(i = 0; i <= time; i++){
						d[i] = 0.5 * g * pow(i, 2);
						cout << i << " " << d[i] << endl;
					}
				}
				else
					cout << "Invalid Input. Please try again.\n" << endl;
			}
			while(h < 0);
			
			// loop thru whole array set
			for(i = 0; i < 50; i++){
				
				// compare during every loop
				// if d[0] < than value in the middle
				// replace larger value into d[0]
				if(d[0] < d[i])
					d[0] = d[i];
			}
			
			// if d[0] larger than height
			if(d[0] > h)
				cout << "Warning-Bad Data: The distance fallen exceeds the height of the bridge." << endl;
		}
		else
			cout << "Invalid Input. Please try again.\n" << endl;
	}
	while(time < 0);
	
	return 0;
	
}
