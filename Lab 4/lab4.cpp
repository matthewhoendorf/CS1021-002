#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
//Program calculates a driver's gas mileage stats from an n number of fill-ups that they input

int main(){

std::cout << std::setprecision(2) << std::fixed;

cout << "* This program will compute an automobile's gas mileage statistics *" << endl << endl;
cout << "Enter initial odometer reading:";
int odom_init;
cin >> odom_init;

int gal=0,n=1,odom,total_miles=0,total_gal=0;
float price,ppg,total_mpg=0;

while(gal!=-1){

cout << endl << "Fill up #" << n << endl << "Enter gallons used (-1 to end):";
cin >> gal;

if(gal!=-1){
cout << "Enter price paid:$";
cin >> price;
cout << "Enter odometer reading:";
cin >> odom;
ppg = price/gal;
int miles = odom-odom_init;
total_miles+=miles;
total_gal+=gal;
odom_init = odom;
int mpg = miles/gal;
float mpd = miles/price;
total_mpg+=mpg;
cout << endl << "After Fill-up #" << n << ": Auto travel tested at" << endl;
cout << miles << " miles" << endl << mpg << " miles per gallon" << endl;
cout << "$" << ppg << " price per gallon" << endl << mpd << " miles per dollar" << endl;
n+=1;
}

else{}

}

float end_mpg = float(total_miles)/float(total_gal);
cout << endl << "Final Computation: After " << n-1 << " fill-ups the auto tested at" << endl;
cout << total_miles << " miles." << endl;
cout << total_gal << " gallons." << endl;
cout << end_mpg << " miles per gallon." << endl;
cout << endl << "Goodbye!" << endl;

}