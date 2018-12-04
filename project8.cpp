#include <iostream>
#include <string>
#include <stack>

using namespace std;
void showStack(stack<string> s); //show the contents of the stack
int getRow(string c); //get the row number
int getCol(char c);// get the column number
bool isAccepted(string s);//functions as a tracing system returns true if word is accepted or false if word is rejected
void showStack(stack<string> s) {
	for (std::stack<string> dump = s; !dump.empty(); dump.pop())
		std::cout << dump.top() << " ";

}
int main() {
	//if word is accepted then print out accepted
	if (isAccepted("(i+i)*i$")) {
		cout << "(i+i)*i$ is Accepted" << endl;

	}
	else
		cout << "(i+i)*i$ is REJECTED" << endl;
	if (isAccepted("(i*)$")) {
		cout << "(i*)$ is Accepted" << endl;

	}
	else
		cout << "(i*)$ is rejected" << endl;
	system("pause");
	return 0;
}
bool isAccepted(string s) {
	string rules[8] = { "E->E+T","E->E-T","E->T","T->T*F","T->T/F","T->F",
		"F->(E)","F->i" };
	string table[16][11] = { "S5"," "," "," "," ","S4"," "," ","1","2","3",
		" ","S6","S7"," "," "," "," ","acc"," "," "," ",
		" ","R3","R3","S8","S9"," ","R3","R3"," "," "," ",
		" ","R6","R6","R6","R6"," ","R6","R6"," "," "," ",
		"S5"," "," "," "," ","S4"," "," ","10","2","3",
		" ","R8","R8","R8","R8"," ","R8","R8"," "," "," ",
		"S5"," "," "," "," ","S4"," "," "," ","11","3",
		"S5"," "," "," "," ","S4"," "," "," ","12","3",
		"S5"," "," "," "," ","S4"," "," "," "," ","13",
		"S5"," "," "," "," ","S4"," "," "," "," ","14" ,
		" ","S6","S7"," "," "," ","S15"," "," "," "," ",
		" ","R1","R1","S8","S9"," ","R1","R1"," "," "," ",
		" ","R2","R2","S8","S9"," ","R2","R2"," "," "," ",
		" ","R4","R4","R4","R4"," ","R4","R4"," "," "," ",
		" ","R5","R5","R5","R5"," ","R5","R5"," "," "," ",
		" ","R7","R7","R7","R7"," ","R7","R7"," "," "," ",
	};
	unsigned int i = 0; //for reading each terminal
	stack<string> stck;
	stck.push("0");
	string pc; //popped string from the stack
	pc = stck.top();
	stck.pop();
	string e;
	while (i < s.length()) {

		int r = getRow(pc);
		int c = getCol(s[i]);
		e = table[r][c];
		
		if (e == "acc") {
			return true;
		}
		if (e == " ") {
			return false;
		}
		else if (e[0] == 'S') {
			stck.push(pc);
			string terminal(1, s[i]); //convert char to string
			string e_2 = e.substr(1, string::npos); //get the second char and convert to string
			stck.push(terminal);
			stck.push(e_2);
			showStack(stck);// show stack before we iterate to next i
			cout << endl;
			pc = stck.top();
			stck.pop();
			i++;


		}
		else if (e[0] == 'R') {

			stck.push(pc);
			//parse the chosen rule into two tokens, one for the table and the other for determine the pop_count 
			string delim = "->";
			int rule_num = e[1] - '0';
			string left_side = rules[rule_num - 1].substr(0, rules[rule_num - 1].find(delim));
			string right_side = rules[rule_num - 1].substr(rules[rule_num - 1].find(delim) + delim.length(), string::npos);
			int pop_count = 2 * right_side.length();
			for (int j = 0; j < pop_count; j++) {
				stck.pop();
			}

			pc = stck.top();
			stck.pop();
			r = getRow(pc);
			c = getCol(left_side[0]);
			e = table[r][c];
			stck.push(pc);
			stck.push(left_side);
			stck.push(e);
			pc = stck.top();
			stck.pop();
		}
	}
}

int getRow(string c) {
	int i = stoi(c);
	return i;
}
int getCol(char c){
	int y = 0;
	switch (c) {
	case 'T':
		y = 9;
		break;
	case 'F':
		y = 10;
		break;
	case 'E':
		y = 8;
		break;
	case '(':
		y = 5;
		break;
	case ')':
		y = 6;
		break;
	case 'i':
		y = 0;
		break;
	case '+':
		y = 1;
		break;
	case '-':
		y = 2;
		break;
	case '*':
		y = 3;
		break;
	case '/':
		y = 4;
		break;
	case '$':
		y = 7;
	default:
		break;
	}
	return y;
}