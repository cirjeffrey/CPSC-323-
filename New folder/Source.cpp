#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


void writeFile(string);

bool comment = false;
bool singleComment = false;
void parseToken(string);
char buffer[100];

int main() {
	string state, line;
	ifstream inFile;
	inFile.open("input.txt");					
	remove("output.txt");

	while (getline(inFile, line)) {			// reads each line

		istringstream iss(line);		// converts into tokens
		while (iss) {
			string tok;
			iss >> tok;			// pushes token into tok variable
			cout << "TOK: " << tok << endl;
			
			if (tok == "/*") {			// checks for multi line comment
				comment = true;			// if bool comment== true, writeFile() does not write to file
			}
			if (tok == "*/") {
				comment = false;
				break;
			}

			parseToken(tok);		// analyze token
		}

	}
	system("pause");
}


void parseToken(string token) {
	for (int i = 0; i < token.length(); i++) {
		buffer[i] == token[i];				// pushes each char into a buffer char array	
	}							// allows code to check if some tokens contain comments or symbols
								// ex: "//describe" is one token and so we need to separete the word
	if (token[0] == '/' && token[1] == '/') {
		singleComment = true;
	}

	writeFile(token);

	if (token == "") {					// conditional check to see if at end of line
		if (singleComment == true)			// checks singleComment bool. if true and eol, set to false 
			singleComment = false;			
		writeFile("\n");
	}
}

void writeFile(string token) {					// write to file if not in comment/singleComment state
	if (comment != true && singleComment != true) {
		ofstream outFile;
		outFile.open("output.txt", ::ios_base::app);
		outFile << " " << token;
		outFile.close();
	}

}
