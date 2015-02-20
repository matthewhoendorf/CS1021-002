#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

const int SIZE = 8;
const int DELAY = 10000;
void displayBoard(int b[SIZE][SIZE]);
void startPoint(int&, int&);
void validMove(const int, const int, const int[], const int[], const int[][SIZE], bool[]);
int bestMove(const bool[], const int, const int, const int[], const int[], const int[][SIZE]);
void modAccess(const int, const bool[], const int, const int, const int[], const int[], int[][SIZE]);

int main(){
	srand((unsigned)time(NULL));
	cout << "\nPRESS ANY KEY AND HIT ENTER TO BEGIN\n"; int x; cin >> x;
	int board[8][8];
	const int horizontal[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	const int vertical[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	bool valid[8] = { false };
	int startRow = 0, startColumn = 0, full_tour = 0, closed_tour = 0, currentRow, currentColumn, best, move;

	for (int i = 1; i <= 64; i++){
		int access[SIZE][SIZE] = { { 2, 3, 4, 4, 4, 4, 3, 2 },
		{ 3, 4, 6, 6, 6, 6, 4, 3 },
		{ 4, 6, 8, 8, 8, 8, 6, 4 },
		{ 4, 6, 8, 8, 8, 8, 6, 4 },
		{ 4, 6, 8, 8, 8, 8, 6, 4 },
		{ 4, 6, 8, 8, 8, 8, 6, 4 },
		{ 3, 4, 6, 6, 6, 6, 4, 3 },
		{ 2, 3, 4, 4, 4, 4, 3, 2 } };

		currentRow = startRow; currentColumn = startColumn;

		for (int r = 0; r < 8; r++){
			for (int c = 0; c < 8; c++){
				board[r][c] = 0;
			}
		}

		board[currentRow][currentColumn] = 1;

		for (move = 2; move <= 64; move++){
			validMove(currentRow, currentColumn, vertical, horizontal, board, valid);
			best = bestMove(valid, currentRow, currentColumn, vertical, horizontal, access);
			if (best == -1){
				break;
			}
			modAccess(best, valid, currentRow, currentColumn, vertical, horizontal, access);
			currentRow += vertical[best];
			currentColumn += horizontal[best];
			board[currentRow][currentColumn] = move;
		}

		displayBoard(board);

	    if (move == 65){
            full_tour++;
            cout << "\nFULL TOUR" << endl;
            validMove(currentRow, currentColumn, vertical, horizontal, board, valid);
            for (int i = 0; i < 8; i++){
				if (valid[i] == true){
                    if(board[currentRow+=vertical[i]][currentColumn+=horizontal[i]] == 1){
                        cout << "CLOSED TOUR" << endl;
                        closed_tour++;
                    }
                }
            }
        }
		startPoint(startRow, startColumn);
	}
	cout << "\nNUMBER OF FULL TOURS: " << full_tour << endl;
	cout << "NUMBER OF CLOSED TOURS: " << closed_tour << endl << endl;
	return 0;
}

void displayBoard(int cboard[SIZE][SIZE]){
	//a hacked function to display chess board with labels on columns and rows
	cout << "\n     ";    //start table by skipping line and aligning column label
	for (int i = 0; i < SIZE; ++i) cout << i << "   ";    cout << endl; //display column labels
	for (int crow = 0; crow < SIZE; ++crow) { //display current row
		for (int i = 0; i < SIZE*4.5; ++i) cout << "-";
		cout << endl;    //next line for start of table values
		for (int j = 0; j <= SIZE; ++j) cout << "   |"; cout << endl;
		cout << crow;
		if (crow <10) cout << "  |"; else cout << " |";    //display row labels
		for (int ccol = 0; ccol < SIZE; ++ccol) {
			if (cboard[crow][ccol] == 0) cout << "  ";
			else cout << " " << cboard[crow][ccol];
			//output table values
			if (cboard[crow][ccol] > 9)
				cout << "|";
			else cout << " |";
		}//end for data
		cout << endl;
		for (int j = 0; j <= SIZE; ++j) cout << "   |"; cout << endl;
	}// end for crow    
	for (int l = 0; l < SIZE*4.5; ++l) cout << "-";    cout << endl;
	for (int k = 0; k<DELAY; k++) for (int j = 0; j<DELAY; j++); //wait 
}//END displayBoard function

void startPoint(int& r, int& c){
	c++;
	if (c >= 8){
		c = 0;
		r++;
	}
}

void validMove(const int cRow, const int cColumn, const int vert[], const int horiz[], const int board[][SIZE], bool valid[]){
	int moveNumber = 0;
	while (moveNumber < 8){
		int tempR = cRow + vert[moveNumber];
		int tempC = cColumn + horiz[moveNumber];

		if (tempR >= 0 && tempR <= 7 && tempC >= 0 && tempC <= 7){
			if (board[tempR][tempC] == 0){
				valid[moveNumber] = true;
			}
			else{
				valid[moveNumber] = false;
			}
		}
		else{
			valid[moveNumber] = false;
		}
		moveNumber++;
	}
}

int bestMove(const bool valid[], const int cRow, const int cColumn, const int vert[], const int horiz[], const int access[][SIZE])
{
	int minAccess = 8;
	int best = -1;
	for (int moveNumber = 0; moveNumber < 8; moveNumber++)
	{
		if (valid[moveNumber] == false)
		{
			continue;
		}
		int tempR = cRow + vert[moveNumber];
		int tempC = cColumn + horiz[moveNumber];

		if (access[tempR][tempC] <= minAccess)
		{
			minAccess = access[tempR][tempC];
			best = moveNumber;
		}
	}

	return best;
}

void modAccess(const int bestMove, const bool valid[], const int cRow, const int cColumn, const int vert[], const int horiz[], int access[][SIZE])
{
	for (int moveNumber = bestMove + 1; moveNumber < 8; moveNumber++)
	{
		if (valid[moveNumber] == false)
		{
			continue;
		}

		int tempR = cRow + vert[moveNumber];
		int tempC = cColumn + horiz[moveNumber];

		access[tempR][tempC]--;
	}
}