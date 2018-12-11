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
	inFile.open("finalp1.txt");
	remove("finalp2.txt");

	while (getline(inFile, line)) {

		istringstream iss(line);
		if(line[0] == '/')
			cout << line << endl;

		if (line != "" && line[1] != '/') {
			while (iss) {

				string tok;
				iss >> tok;
				if (tok == "/*") {
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


void parseToken(string token) {
	if (token[0] == '/' && token[1] == '/') {
		singleComment = true;
	}

	writeFile(token);
	if (token == "" ) {
		if (singleComment) {
			singleComment = false;
		}
	writeFile("\n");
	}
}

void writeFile(string token) {
	if (comment != true && singleComment != true) {
		ofstream outFile;
		outFile.open("finalp2.txt", ::ios_base::app);
		outFile << " " << token;
	outFile.close();
	}
}
