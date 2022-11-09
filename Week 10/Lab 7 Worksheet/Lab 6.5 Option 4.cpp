// LAB 7 WORKSHEET 6.5 - OPTION 4
// LEONG ZI QI

#include <iostream>
using namespace std;

int converter(int, double&, double&);

int main(){
	
	int select;
	double convert, convert2;	
	
	cout << "Please input\n";
	cout << "1 Convert miles to kilometers\n";
	cout << "2 Convert kilometers to miles\n";
	cout << "3 Quit\n";
	cin >> select;
	
	if(select == 1 || select == 2)
		converter(select, convert, convert2);

	switch(select){
		case  1:	cout << convert << " miles = " << convert2 << " kilometers\n\n";
					break;
		case  2:	cout << convert << " kilometers = " << convert2 << " miles\n\n";
					break;
		case  3:	return 0;
					break;
	}
	
	main();	
}

int converter(int select, double& convert, double& convert2)
{
	int selection[2] = {1, 2};
	string unit[2] = {"miles", "kilometers"};
	
	for(int i = 0; i < 2; i++)
		if(select == selection[i]){
			do{
				cout << "\nPlease input the " << unit[i] << " to be converted\n";
				cin >> convert;
			}
			while(convert < 0);
			
			if(select == 1){
				convert2 = convert * 1.61;
			}
			else if(select == 2){
				convert2 = convert * 0.621;
			}
		}
}
