#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	
	double USD, EUR, JPY;
	cout << fixed << setprecision(2);
	
	cout << "Please input the US Dollar (USD) amount: ";
	cin >> USD;
	
	// Exchange rates
	JPY = 143.1 * USD;
	EUR = USD;
	
	cout << endl << "The amount of " << USD << " US Dollar (USD) is equals to " << JPY << " in Japanese Yen (JPY)";
	cout << endl << "The amount of " << USD << " US Dollar (USD) is equals to " << EUR << " in Euros (EUR)";
	
	return 0;
	
}
