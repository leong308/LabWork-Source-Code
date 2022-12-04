// Lab 9 Worksheet
// Option 1
// LEONG ZI QI

#include <iostream>
using namespace std;

struct Airport
{
	int mostPlanes, leastPlanes;
};

struct AirportData
{
	int planesLanded, planesDeparted;
	Airport data;
};

int main(){
	
	int total = 0, avgLand = 0, avgDepart = 0, most, least;
	
	const int NUM_PLANES = 12;
	AirportData planes[NUM_PLANES];
	
	for(int count = 0; count < NUM_PLANES; count++){
		cout << "MONTH " << (count + 1) << endl << endl;
		
		cout << "Please enter the total number of planes that landed ";
		cout << "in month " << (count + 1) << ": ";
		cin >> planes[count].planesLanded;
		
		cout << "Please enter the total number of planes that departed ";
		cout << "in month " << (count + 1) << ": ";
		cin >> planes[count].planesDeparted;
		
		cout << "Please enter the most plane landed in a day of this month: ";
		cin >> planes[count].data.mostPlanes;
		
		cout << "Please enter the least plane landed in a day of this month: ";
		cin >> planes[count].data.leastPlanes;
		
		cout << endl << endl;
	}
	
	for(int count = 0; count < NUM_PLANES; count++){
		avgLand += planes[count].planesLanded;
		avgDepart += planes[count].planesDeparted;
		total += planes[count].planesLanded + planes[count].planesDeparted;
	}
	
	avgLand /= 12;
	avgDepart /= 12;
	
	most = planes[0].data.mostPlanes;
	least = planes[0].data.leastPlanes;
	
	for(int count = 0; count < NUM_PLANES; count++){
		if(planes[count].data.mostPlanes > most)
			most = planes[count].data.mostPlanes;
		
		if(planes[count].data.leastPlanes < least)
			least = planes[count].data.leastPlanes;
	}
	
	cout << "The average monthly number of landing planes: " << avgLand << endl;
	cout << "The average monthly number of departing planes: " << avgDepart << endl;
	cout << "The total number of landing and departing planes for the year: " << total << endl;
	cout << "The greatest number of planes that landed on any one day: " << most << endl;
	cout << "The least number of planes that landed on any one day: " << least << endl;
	
	return 0;
}
