#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void errorMsg(string name);
void programState(string);
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

	while (getline(inFile, line)) {

		istringstream iss(line);
		while (iss) {
			string tok;
			iss >> tok;
			cout << "TOK: " << tok << endl;
			if (tok == "/*") {
				comment = true;
			}
			if (tok == "*/") {
				comment = false;
				break;
			}

			parseToken(tok);

	

		}
	


	}
	system("pause");
}


void parseToken(string token) {
	for (int i = 0; i < token.length(); i++) {
		buffer[i] == token[i];
	  /*	if (token[i] == ';') {
			token.pop_back();
		}*/
		
	}

	if (token[0] == '/' && token[1] == '/') {
		cout << "SINGLE LINE COMMENT ";
		singleComment = true;
	}

	writeFile(token);

	if (token == "") {
		if (singleComment = true)
			singleComment = false;
		writeFile("\n");
	}

	if (token == "var " || token == "begin")
		cout << "TOKEN:" << token << endl;
}

void writeFile(string token) {
	if (comment != true && singleComment != true) {
		ofstream outFile;
		outFile.open("output.txt", ::ios_base::app);
		outFile << " " << token;
		outFile.close();
	}

}

void programState(string str) {
	if (str == "program") {

	}
}


void errorMsg(string name) {

	cout << name << " is expected" << endl;

}