/*
*	File:			LabProblem13A.cpp
*	Author:			Ethan Burch
* 
*	Date:			11/30/2023
*	Description:	Gets the letter frequency from a file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

//prototypes
void pressEnterToContinue(void);
void letterFrequency(string filename, double chart[]);
void printOutFrequency(int characters, const double chart[]);

// constants
const int LETTERS = 26; // 26 letters in alphabet
const int CAP_A = 65;
const int CAP_Z = 90;
const int LOW_A = 97;
const int LOW_Z = 122;


int main(void) {
	double frequency[LETTERS];
	for (int i = 0; i < LETTERS; i++) 
		frequency[i] = 0;
	string datafile;
	cout << "Enter filename: ";
	getline(cin, datafile);
	
	letterFrequency(datafile, frequency);

	pressEnterToContinue();

}

void pressEnterToContinue(void) {
	char c;
	cout << "Press Enter to Continue...";
	cin.ignore(1024, '\n');

	do { cin.get(c); } while (c != '\n' && c != EOF);
	return;
}

void letterFrequency(string filename, double chart[]) {
	ifstream inFile;
	string input;
	string finalInput;
	int characters = 0;
	inFile.open(filename);
	
	if (inFile.fail()) {
		cout << "read error\n";
		return;
	}
	while (true) {
		inFile >> input;
		if (inFile.fail()) break;
		finalInput += input + ' ';
	}
	
	for (int i = 0; i < finalInput.length(); i++) {
		if (finalInput[i] >= CAP_A && finalInput[i] <= CAP_Z || finalInput[i] >= LOW_A && finalInput[i] <= LOW_Z) {
			characters++;
		}

		if (finalInput[i] >= CAP_A && finalInput[i] <= CAP_Z) {
			chart[finalInput[i] - CAP_A]++;
		}
		else if (finalInput[i] >= LOW_A && finalInput[i] <= LOW_Z) {
			chart[finalInput[i] - LOW_A]++;
		}
	}

	for (int i = 0; i < LETTERS; i++) {
		chart[i] = (chart[i] / characters) * 100;
	}

	printOutFrequency(characters, chart);
}

void printOutFrequency(int characters, const double chart[]) {
	char letter = CAP_A;
	cout << "Total number of letters: " << characters << endl;
	cout << "Frequency: \n";
	
	for (int i = 0; i < LETTERS; i++) {
		//cout << '\'' << letter << "':\t" << setprecision(3) << chart[i] << endl;
		printf("\'%c\':\t %4.3f \n", letter, chart[i]);
		letter++;
	}
}