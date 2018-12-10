#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void writeFile(string);
bool comment = false;
bool singleComment = false;
void parseToken(string);

int main() {
	string line;
	ifstream inFile;
	inFile.open("input.txt");
	remove("output.txt");				// clears file during each run

	while (getline(inFile, line)) {			// while there are lines to get from file

		istringstream iss(line);		// convert line into separate tokens
	
		if (line != "" && line[1] != '/') { 	// check if line is empty or single line comment only
			while (iss) {				

				string tok;
				iss >> tok;			// converts tokens to strings to be analyzed
			
				if (tok == "/*") {		// checks for multi line comment
					comment = true;
				}
				if (tok== "*/") {
					comment = false;
					break;
				}
					parseToken(tok);
			}
		}
	}

	system("pause");
}

// function parses each individual token. 
void parseToken(string token) {
	if (token[0] == '/' && token[1] == '/') {	// checks for mid line comment
		singleComment = true;
	}

	writeFile(token);							

	if (token == "" ) {				// checks for end of line and pushes a newline 
		if (singleComment) {			// checks for end of line for single line comments
			singleComment = false;
		}
	writeFile("\n");
	}
}


// opens and appends to file if not in comment state
void writeFile(string token) {
	if (comment != true && singleComment != true) {
		ofstream outFile;
		outFile.open("output.txt", ::ios_base::app);
		outFile << " " << token;
		outFile.close();
	}
}
