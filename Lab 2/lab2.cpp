// Program outputs windchill using both new and old formulas in Centigrade
// and Fahrenheit after the user inputs a temp. (F) and wind speed (MPH).

#include <iostream>
#include <cmath>

using namespace std;

int main ()

{


	int T;
	int V;

	cout << "Please enter a temperature in degrees Fahrenheit: ";
	cin >> T;
	cout << "Please enter the wind speed in MPH: ";
	cin >> V;

	int T_c = round((T-32)*5/9);
	int OWC_F = round(.081*(3.71*sqrt(V)+5.81-0.25*V)*(T-91.4)+91.4);
	int NWC_F = round(35.74+(.6215*T)-(35.75*pow(V,.16))+((.4275*T)*pow(V,.16)));
	int OWC_C = round((OWC_F-32)*5/9);
	int NWC_C = round((NWC_F-32)*5/9);

	cout << "Temp: " << T << " degrees Fahrenheit:\n";
	cout << " new wind chill formula = " << NWC_F << "\n";
	cout << " old wind chill formula = " << OWC_F << "\n";
	cout << "Temp: " << T_c << " Centigrade:\n";
	cout << " new wind chill formula = " << NWC_C << "\n";
	cout << " old wind chill formula = " << OWC_C << "\n";

	return 0;

}
