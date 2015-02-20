#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int SIZE = 25;
void shuffle (int[25]);
void playorder (const int [25], const char *[]);
void playlist_union (const char *[], const char *[]);
void intersection (const char *[], const char *[]);
void shuffletogether ( const int [25], const int [25], const char *[], const char *[]);

int main() {
	
	//create constant char arrays for my playlist and my friends playlist
	const char *mymp3list[25] = {"Freaking Out the Neighborhood","Strange Fires","Bicycle","Good Kids Make Bad Grown Ups","Changes","Strangers Are Strange","Ruthie Ruthie","Domino","Face It","Crystallized","Here Comes Summer Again","3AM Spiritual","How To Survive In","Wonder Years","Humdrum Blues","Summer is Over","My Kind of Woman","Bandit","Shuggie","In Vertigo","Evergreen","Advice on Bears","KV Crimes","Ode to Viceroy","Stars Keep On Calling My Name"};
	const char *myfriendsmp3list[25] = {"Stars Keep On Calling My Name","Epistrophy","Off Minor","How High is the Moon","The Aeons","Domino","Otis","Pennies from Heaven","Mood Returns","Witchcraft","Eleven Wives","Jung Parade","Jack's Blues","Rhythm-a-ning","Progression","Humdrum Blues","The Baddest Monk","Crystallized","Endangered Species","Bona","The Remedy","Jeru","Pinzin Kinzin","Onslaught","Bandit"};

	//output original playlist, shuffle it, and output the shuffled playlist
	int songorder1[25] = {0};
	int songorder2[25] = {0};
	srand(time(0));
	
	cout << "\nOriginal Song Order (My Playlist): " << endl;
	for(int i = 1; i <= SIZE; i++){
		cout << i << ". " << mymp3list[i-1] << "\n";
	}
	cout << "\n" << endl;
	cout << "Shuffled Order (My Playlist): " << endl;
	shuffle(songorder1);
	shuffle(songorder2);
	playorder(songorder1,mymp3list);
	playlist_union(mymp3list,myfriendsmp3list);
	intersection(mymp3list,myfriendsmp3list);
	shuffletogether(songorder1, songorder2, mymp3list,myfriendsmp3list);
	return 0;
}

void playorder(const int order[25], const char *songlist[]){

	for(int song = 1; song <= SIZE; song ++){
		for(int position = 0; position < SIZE; position++){
			if(order[position] == song){
				cout << song << ". " << songlist[position] << "\n";
			}
		}
	}
	cout << endl;
}

void shuffle(int order[25]){
	
	int position;
	int i;
	for(i = 1; i <= SIZE; i++){
		do {
			position = rand() % SIZE;
		} while(order[position] != 0);
		order[position] = i;
	}
}

void playlist_union(const char *mymp3list[], const char *myfriendsmp3list[]){
	int dupe, song = 1;
	
	cout << "\nUnion of Both Playlists (No Repeats):\n";
	for(int i = 0; i  < SIZE; i++){
		cout << song << ". " << mymp3list[i] << " \n";
		song++;
	}
	
	for(int i = 0; i < 25; i++){
		dupe = 0;
		for(int j = 0; j < 25; j++){
			if(strcmp(myfriendsmp3list[i],mymp3list[j])==0){
				dupe++;
			}
		}
		if(dupe==0){
			cout << song << ". " << myfriendsmp3list[i] << " \n";
			song++;
			dupe = 0;
		}
	}
	
	cout << endl;
}

void intersection(const char *mymp3list[], const char *myfriendsmp3list[]){
	int dupe, song = 1;
	
	cout << "\nSongs in Both Playlists:\n";
	for(int i = 0; i < 25; i++){
		dupe = 0;
		for(int j = 0; j < 25; j++){
			if(strcmp(mymp3list[i],myfriendsmp3list[j])==0){
				dupe++;
			}
		}
		if(dupe==1){
			cout << song << ". " << mymp3list[i] << " \n";
			song++;
			dupe = 0;
		}
	}
	
	cout << "\n" << endl;
}

void shuffletogether(const int first_order[25], const int second_order[25], const char *mymp3list[], const char *myfriendsmp3list[]){

	cout << "Both Playlists Shuffled Together:\n";
	for(int song = 1; song <= SIZE; song ++){
		for(int position = 0; position < SIZE; position++){
			if(first_order[position] == song){
				cout << song << ". " << mymp3list[position] << "\n";
			}
		}
	}
	for(int song =1; song <= SIZE; song ++){
		for(int position = 0; position <= SIZE; position++){
			if(second_order[position] == song){
				cout << song+SIZE << ". " << myfriendsmp3list[position] << "\n";
			}
		}
	}
	cout << "\n" << endl;
}