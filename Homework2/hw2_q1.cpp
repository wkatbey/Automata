#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define ACCEPTED_STATE b

/*
	The following enum declaration, state, declares an enum that lists the states 
	in our DFA diagram.
*/
enum state {a, b, c, d};

/*
	The attribute transitionTable contains a 2-dimensional array representing the DFA's
	transition table. 
*/
enum state transitionTable[4][2] = { 
	{a, b},
	{c, d},
	{b, d},
	{d, d}
};

/*
	The method transitionStates will return a new state, given the current state and a letter
	of the accepted alphabet. (In our case: 0,1)
*/
enum state transitionStates(enum state s, char c) {
	
	int k = c - '0';
	return transitionTable[(int) s][k];
}

/*
	The method returnEndState will run through a given string, moving states with each of the 
	string's indices. 
*/
enum state returnEndState(enum state s, string str) {
	enum state t;
	t = s;

	for (int i = 0; i < str.length(); i++) {
		t = transitionStates(t, str[i]);
	}

	return t;
}

int main()
{
	
	string tempBitString;
	string input[6];

	ifstream inputFile("input.txt");
	if (inputFile.is_open()) {
		int i = 0;
		while (getline(inputFile, tempBitString)) {
	    		input[i++] = tempBitString;
		}
		inputFile.close();
	}

    	int inputSize = sizeof(input)/sizeof(input[0]);

	for (int i = 0; i < inputSize; i++) {
		if (returnEndState(a, input[i]) == ACCEPTED_STATE)
			cout << input[i] << ": Accepted" << endl;
		else
			cout << input[i] << ": Rejected" << endl;
	}



    	return 0;
}











