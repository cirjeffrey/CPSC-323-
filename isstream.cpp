#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void isReservedWord(string word);
void programState();
void writeToFile(string str);

enum {program = 0};
string temp = "";

int main() {
	char ch, buffer[15];
	int j = 0;
	bool comment = false;
	remove("output.txt");
	ifstream inFile("text.txt");

	if (!inFile.is_open()) {
		cout << "ERROR OPENING FILE";
	}

	while (!inFile.eof()) {
		getline(inFile, temp);
		istringstream iss(temp);
		cout << "TEMP: " << temp << endl;

		while (iss)
		{
			string tok;
			iss >> tok;
			if (tok == "/*") {
				comment = true;
			}
			else if (tok == "*/") {
				comment = false;
				break;
			}
		
			if (!comment) {
			cout << "token: " << tok << endl;
			if (tok == "") {
				writeToFile("\n");
			}
			writeToFile(tok);
			}	
		}
	
	}

	system("pause");
	return 0;
}

void isReservedWord(string word) {
	
	if (word == "program") {
		writeToFile(word);
	}
}


void writeToFile(string str) {
	ofstream outFile;
	outFile.open("output.txt", ios_base::app);

	if (str != "") {
		cout << "STRING ADDING " << str << endl;
		outFile << str << " ";
		outFile.close();
	}
}
