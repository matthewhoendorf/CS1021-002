#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

int rolldie(){
	int die = 1+rand()%6;
	return die;
}

int playOneGame(){
	int roll, point;
	cout << "Please pick a number from 1 to 6, and call this number your point." << endl;
	cin >> point;
	roll = rolldie();

	if(roll==point){
		return 1;
	}

	else {
		return -1;
	}
}

int main() {

	cout << setprecision(2) << fixed;

	double bank = 100, wager;
	int winCount = 0, lossCount = 0;
	char play = 'Y';

	cout << "Play a game of chance!" << endl;

	do {
		cout << "What will you wager?" << endl;
		cin >> wager;

		while(wager>bank) {
			cout << "Your wager is greater than your bank, try again." << endl;
			cin >> wager;
		}
		
		int result =  playOneGame();

		if(result==1) {
			winCount++;
			bank+=wager;
			cout << "You won!" << endl;
			cout << "Your bank balance: $" << bank << endl;
		}

		else {
			lossCount++;
			bank-=wager;
			cout << "You lost." << endl;
			cout << "Your bank balance: $" << bank << endl;
		}
		
		if(bank!=0){
		cout << "Play again? (Y/N)" << endl;
		cin >> play;
		}
		else{
		play = 'N';
		}
		
	} while(play=='Y');

	cout << "You won " << winCount << " games and lost " << lossCount << " games."<< endl;
	cout << "Goodbye!" << endl;
}