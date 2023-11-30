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

using namespace std;

void pressEnterToContinue(void);


int main(void) {
	string datafile;
	cout << "Enter filename: ";
	getline(cin, datafile);

}

void pressEnterToContinue(void) {
	char c;
	cout << "Press Enter to Continue...";
	cin.ignore(1024, '\n');

	do { cin.get(c); } while (c != '\n' && c != EOF);
	return;
}