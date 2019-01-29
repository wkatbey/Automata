#include <iostream>
#include <fstream>
using namespace std;

bool isStringAccepted(string);

int main() {

    string tempBitString;
    string input[6];

    ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        int i = 0;
        while (getline(myfile, tempBitString)) {
            input[i++] = tempBitString;
        }
        inputFile.close();
    }

    /*string input[] = {
                    "1000000",
                    "1000000000000",
                    "1000",
                    "1111101",
                    "100100",
                    "1010001"
                    };*/


    //Run through each index in 'input'
    for (int i = 0; i < sizeof(input); i++) {
        if (isStringAccepted(input[i])) {
            cout << input[i] << ": Accepted" << endl;
        }
        else {
            cout << input[i] << ": Rejected" << endl;
        }
    }

    return 0;
}

bool isStringAccepted(string bitString) {

    bool isAccepted = false;
    bool isPreceedingValueZero = false;

    for (int i = 0; i < bitString.length(); i++) {


        if (isAccepted) { //The string's first '1' appeared
            if (bitString[i] == '1') //Reject if another '1' appears
                return false;

            if (isPreceedingValueZero && bitString[i] == '0') {
                //This indicates an even number of zeros
                isAccepted = true;
                isPreceedingValueZero = false;
            }
            else if (!isPreceedingValueZero && bitString[i] == '0') {
                //If this branch is taken, we have an odd number of zeros
                isPreceedingValueZero = true;
            } 
        }
        else {
           if (bitString[i] == '1') //The string's first '1' is read
                isAccepted = true;
        }
    }

    //If the first '1' was present (without any other '1's)
    //and we have an even number of zeros, return true.
    //Otherwise return false
    if (isAccepted && !isPreceedingValueZero)
        return true;
    else 
        return false;

}