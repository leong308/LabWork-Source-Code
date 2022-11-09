// Week 11 C++ Challenge Question
// LEONG ZI QI

#include <iostream>
#include <algorithm>
using namespace std;

int getNumAccidents(string);
void findLowest(int accidents[5], string region[5]);

int main(){
	
	string region[5] = {"north", "south", "east", "west", "central"};
	int accidents[5] = {0};
	
	// call function to fill up accident[i] arrays for 5 times
	for(int i = 0; i < 5; i++)
		accidents[i] = getNumAccidents(region[i]);
	
	// bring in array values
	findLowest(accidents, region);
	
	return 0;
	
}

int getNumAccidents(string region)
{
	int accidents;
	
	do{
		cout << "Please enter the number of automobile accidents reported in the " << region << " region during the last year\n";
		cin >> accidents;
		
		if(accidents < 0)
			cout << "Invalid Input. Please try again.\n";
	}
	while(accidents < 0);
	
	cout << endl;
	return accidents;
	
}

void findLowest(int accidents[5], string region[5])
{
	int least;
	
	// store into least var to shorten cout length
	least = min({accidents[0], accidents[1], accidents[2], accidents[3], accidents[4]});
	
	for(int i = 0; i < 5; i++)
		if(accidents[i] == least)
			cout << "The " << region[i] << " region had the fewest reported automobile accidents which is " << least << " during the last year.\n";
}
