//In partnership with Umang Joshi, Shourat Sandhawalia, Amy Kelley, and Matt Miller

#include "HashTable.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;

int main(){
	// I think i did this right

	/* initialize random seed: */
	srand((unsigned int)time(0));//srand is one time and should be at top
	HashTable <int>HT;
	int numInserts = 0;

	while (numInserts < MAXHASH){
		int ranNum = rand() % 20000;
		bool flag = HT.insert(ranNum,ranNum);

		if(flag){
			numInserts++;
			// cout << HT << endl;

		}// end if statement

		// break; // i think I fix the infinite loop but I am also dumb

	}// end while loop

	//int ranNum = rand() % 1000;

	return 0;


};// end main
