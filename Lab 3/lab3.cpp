#include<iostream>
#include<cmath>
using namespace std;
int main () {

// calculate the minimum and maximum of two numbers using an if-else statement
cout << "Enter two numbers: " << endl;

int num1,num2;
cin >> num1 >> num2;

int max1,min1;

if (num1 > num2) {
	max1 = num1;
	min1 = num2;
	}
else {
	max1 = num2;
	min1 = num1;
	}
	
cout << "Minimum of " << num1 << " and " << num2 << " is " << min1 << endl;
cout << "Maximum of " << num1 << " and " << num2 << " is " << max1 << endl;


// calculate the minimum and maximum of two numbers using if statements
cout << "Enter two numbers: " << endl;

int num3,num4;
cin >> num3 >> num4;

int max2,min2;

if (num3 > num4) {
	max2 = num3;
	min2 = num4;
	}
if (num3 < num4) {
	max2 = num4;
	min2 = num3;
	}
	
cout << "Minimum of " << num3 << " and " << num4 << " is " << min2 << endl;
cout << "Maximum of " << num3 << " and " << num4 << " is " << max2 << endl;

// calculate minimum and maximum of three entered numbers
cout << "Enter three numbers: " << endl;

int numx,numy,numz;
cin >> numx >> numy >> numz;

int max3,min3;

if (numx<numy && numx<numz) {
	min3 = numx;
	if (numy<numz) {
		max3 = numz;
	}
	else {
		max3 = numy;
	}
}
else if (numy<numx && numy<numz) {
	min3 = numy;
	if (numx<numz) {
			max3 = numz;
	}
	else {
			max3 = numx;
	}
}	
else if (numz<numx && numz<numy) {
	min3 = numz;
	if (numx>numy) {
		max3 = numx;
	}
	else {
		max3 = numy;
	}
}

cout << "Minimum of " << numx << ", " << numy << ", and " << numz << " is " << min3 << endl;
cout << "Maximum of " << numx << ", " << numy << ", and " << numz << " is " << max3 << endl;

// check date to see if the month x day = year (i.e. magic date)
cout << "Enter a date in the format m/d/y: " << endl;

char slash;
int m,d,y;
cin >> m >> slash >> d >> slash >> y;

if (m*d == y) {
	cout << "The date " << m << "/" << d << "/" << y << " is a magic date." << endl;
}
else {
	cout << "The date " << m << "/" << d << "/" << y << " is NOT a magic date." << endl;
}

// convert number of seconds to either days, hours, or minutes
cout << "Enter the number of seconds: " << endl;
int sec;
cin >> sec;

cout << "Do you want this converted to (m)inutes, (h)ours, or (d)ays? " << endl;
char response;
cin >> response;

int days,hours,minutes,seconds;

if (response == 'm') {
        minutes = (sec-(sec%60))/60;
        seconds = sec%60;
        cout << minutes << " minutes, and " << seconds << " seconds." << endl;
}
else if (response == 'h') {
        hours = (sec-(sec%3600))/3600;
        minutes = (sec-(sec-(sec%3600))-(sec%60))/60;
        seconds = sec%60;
        cout << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << endl;
}
else if (response == 'd') {
        days = (sec-(sec%86400))/86400;
		hours = (sec-(sec-(sec%86400))-(sec%3600))/3600;
        minutes = (sec-(sec-(sec%3600))-(sec%60))/60;
        seconds = sec%60;
        cout << days << " days, " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << endl;
}

}