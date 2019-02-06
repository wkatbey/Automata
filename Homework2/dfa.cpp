#include <iostream>
#include <string>
using namespace std;

#define FINAL_STATE b

enum state {a, b, c, d};
 /* ** This table implements the state transition function and is indexed by** the current state and the current input letter. */

enum state transition_table[4][2]= { 
	{a, b},
	{c, d},
	{b, d},
	{d, d}
};

enum state delta(enum state s, char c) {
	
	int k = c - '0';
	cout << "C: " << k << endl;
	return transition_table[(int) s][k];
}

enum state delta_bar(enum state s, string str) {
	enum state t;
	t = s;

	for (int i = 0; i < str.length(); i++) {
		t = delta(t, str[i]);
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
		if (delta_bar(a, input[i]) == FINAL_STATE)
			cout << input[i] << "Accepted" << endl;
		else
			cout << input[i] << "Rejected" << endl;
	}



    	return 0;
}











