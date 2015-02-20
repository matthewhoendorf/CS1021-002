#include<iostream>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<fstream>
#include<vector>
using namespace std;

bool isNotEven(int num){
	bool result = (num%2 == 1);
	return result;
}

bool isNotDiv2or3(int num){
	bool result = (num%2 == 1) && (num%3 != 0);
	return result;
}

bool isPrime(int num){
	for(int d = 2; d <= sqrt(num); d++){
		if (num%d == 0){
			return false;
		}
	}
	return true;
}

void updateTopk(int topk[], int k, int x){
	if(x < topk[0]){}
	else{
		int i = 0;
		while(x > topk[i] && i < k){
			topk[i] = topk[i+1];
			i++;
		}
		topk[i-1] = x;
	}
}

int main(){

    int number, count = 0, odd = 0, notdiv2or3 = 0, prime = 0, k = 10;
    int topk[10];
	for(int i = 0; i < k; i++){
		topk[i] = 0;
	}
	int topkprime[10];
	for(int i = 0; i < k; i++){
		topkprime[i] = 0;
	}
	ifstream infile;
    ofstream outfile;
    infile.open("input.txt");
    if (!infile){
        cout << "File open failure!" << endl;
    }

    while(infile >> number && number!=-1){
        count++;
		if(isNotEven(number) == true){
			odd++;
		}
		if(isNotDiv2or3(number) == true){
			notdiv2or3++;
		}
		if(isPrime(number) == true){
			prime++;
			updateTopk(topkprime,k,number);
		}
		
		updateTopk(topk,k,number);
    }
    infile.close();

    cout << "Numbers read in: " << count << endl;
	cout << "Odd numbers: " << odd << endl;
	cout << "Not divisble by 2 or 3 numbers: " << notdiv2or3 << endl;
	cout << "Prime numbers: " << prime << endl;
	cout << "Top k = " << k << " numbers: " << endl;
	for (int i = 0; i < k; i++){
		cout << topk[i] << " ";
    }
	cout << endl << "Top k = " << k << " prime numbers: " << endl;
	for (int i = 0; i < k; i++){
		cout << topkprime[i] << " ";
    }
}