//*********************************************************
//
// Title: A riddle program for Lab 1
// Author: Matthew Hoendorf 
// CS1021-00X Date: January 13, 2014
// Laboratory: 1
// 
//*********************************************************
//
// Description: This program presents a riddle to the user with a series clues.
//
// Input: Only from user. 
//
// Output: Displays to the terminal a series of riddle clues and the answer.
//
// Procedure: Each riddle clue is displayed. There is a wait until user
// input is read to determine if next clue should be displayed. 
// Finally, when the user needs no more clues the riddle answer is displayed.
//
// Constraints: The riddle should have at least 2 clues and be G-rated. 
// 
// ********Begin Program************************************

#include<iostream>
using namespace std;

int main () {
 cout << "Welcome. Here is a riddle:\n"; 
 cout << "What gets wetter and wetter the more it dries?\n";
 cout <<  "Do you need another clue? (y/n)";
 char response;
 cin >> response;
 if (response == 'y') {
    cout << " OK.  Here is the next clue. \n";
    cout << " From South Park: Don't forget to bring one.\n";
 }
 cout <<  "Do you need another clue? (y/n)";
 char response;
 cin >> response;
 if (response == 'y') {
    cout << " OK.  Here is the next clue. \n";
    cout << " It rhymes with owl.\n";
 }
 cout << " Hit any key then enter to see answer";
 cin >> response;
 cout << "If you said \"a towel\", then you are correct.\n";
 return 0;
}
//********End of Program ***********
