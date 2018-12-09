#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;
void showStack(stack<string> s);
int getRow(string r);
int getCol(string c);
// "program B ; var F begin J end"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ",
bool isAccepted(vector<string> w, size_t length, stack<string>s) {
	string table[22][32] = {
		//	P	V	B	EN	I	S	A	B	C	D	E	0	1	2	3	4	5	6	7	8	9	+	-	*	/	(	)	=	$	:	;	,
		"program B ; var F begin J end","", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", //A
		"", "", "", "", "", "", "C D", "C D", "C D", "C D", "C D", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", //B
		"", "", "", "", "", "", "a", "b", "c", "d", "e", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",//C
		"", "", "", "", "", "", "C D", "C D", "C D", "C D", "C D", "E D", "E D", "E D", "E D", "E D", "E D", "E D", "E D", "E D", "E D", "L", "L", "L", "L", "", "L", "L", "", "L", "L", "L",//D
		"", "", "", "", "", "", "", "", "", "", "", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "", "", "", "", "", "", "", "", "", "", "",//E
		"", "", "", "", "", "", "G : I ;", "G : I ;", "G : I ;", "G : I ;", "G : I ;", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",//F
		"", "", "", "", "", "", "B , H", "B , H", "B , H", "B , H", "B , H", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",//G
		"", "", "", "", "", "", "G", "G", "G", "G", "G", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",//H
		"", "", "", "", "integer", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",//I
		"", "", "", "", "", "K W", "K W", "K W", "K W", "K W", "K W", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",//J
		"", "", "", "", "", "M", "N", "N", "N", "N", "N", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",//K
		"", "", "", "", "", "J", "J", "J", "J", "J", "J", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",//L
		"", "", "", "", "", "show", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",//M
		"", "", "", "", "", "", "B = O ;", "B = O ;", "B = O ;", "B = O ;", "B = O ;", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",//N
		"", "", "", "", "", "", "P Q", "P Q", "P Q", "P Q", "P Q", "P Q", "P Q", "P Q", "P Q", "P Q", "P Q", "P Q", "P Q", "P Q", "P Q", "P Q", "P Q", "", "", "P Q", "L", "", "", "", "L", "",//O
		"", "", "", "", "", "", "S R", "S R", "S R", "S R", "S R", "S R", "S R", "S R", "S R", "S R", "S R", "S R", "S R", "S R", "S R", "L", "L", "", "", "", "L", "", "", "", "L", "",//P
		"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "+ P Q", "- P Q", "", "", "", "", "", "", "", "", "",//Q
		"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "L", "L", "* S R", "* S R", "", "L", "", "", "", "L", "",//R
		"", "", "", "", "", "", "B", "B", "B", "B", "B", "T", "T", "T", "T", "T", "T", "T", "T", "T", "T", "", "", "", "", "( O )", "", "", "", "", "", "",//S
		"", "", "", "", "", "", "", "", "", "", "", "V E U", "V E U", "V E U", "V E U", "V E U", "V E U", "V E U", "V E U", "V E U", "V E U", "V E U", "V E U", "", "", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "", "", "", "", "", "E U", "E U", "E U", "E U", "E U", "E U", "E U", "E U", "E U", "E U", "L", "L", "L", "L", "", "", "", "", "", "L", "",//U
		"", "", "", "", "", "", "", "", "", "", "", "L", "L", "L", "L", "L", "L", "L", "L", "L", "L", "+", "-", "", "", "", "", "", "", "", "", "", };//V
	//int i = 0; //index for iterating through the word
	string t; //the popped char
	int r; //the row number
	int c; // the column number
	string e; //the string in specified index from table
	vector<string> reserved_words = { "program","var","begin","show","end","integer" };
	string h;
	bool is_reserved;
	s.push("$");
	s.push("A");
	t = s.top();
	s.pop();
	//this while loop will never finish because the function returns true or false
	//once it matches $ or " " during each iteration
	int num_of_commas = 0;
	int curr_comma = 1;
	for (int k = 0; k < w.size(); k++) {
		if (w[k] == ",")
			num_of_commas++;
	}
	for (int j = 0; j < length; j++) {
		int i = 0;
		int token_size = w[j].size();
		
		for (int z = 0; z < reserved_words.size(); z++) {
			if (w[j] == reserved_words[z]) {
				cout << "RESERVED WORDsubstr: " << w[j].substr(i, w[j].size());
				token_size = 1;
				
			}
		}
		while (i < token_size) {
			int r = getRow(t);
			int c = getCol(w[j].substr(i, token_size));
			e = table[r][c];
			if (t == ",") {
				
				curr_comma++;
				cout << "curr_comma " << curr_comma << endl;
			}
			if (t == "H") {
				cout << "change G to B" << endl;
				if (curr_comma == num_of_commas) {
					e = "B";
				}
			}
			if (t == "$") {
				return true;
			}
			else if (t == w[j].substr(i, token_size)) {
				cout << "stack before popping after match" << endl;
				showStack(s);
				t = s.top();
				s.pop();
				i++;
			}
			else if (e == "") { //rejected
				return false;
			}
			else if (e == "L")
			{
				cout << "lambda at row " << r << "col " << c << endl;
				t = s.top();
				s.pop();
			}
			else {
				cout << "pushing at row " << r << "col " << c << endl;
				std::string str = e;
				std::istringstream buf(str);
				std::istream_iterator<std::string> beg(buf), end;

				std::vector<std::string> tokens(beg, end); // done!

				for (auto& s : tokens)
					std::cout << '"' << s << '"' << '\n';
				for (int j = tokens.size() - 1; j >= 0; j--) {
					s.push(tokens[j]);
				}
				cout << "stack after pushing e" << endl;
				showStack(s);
				t = s.top();
				s.pop();


			}
		}
	}

}



void showStack(stack<string> s) {
	for (std::stack<string> dump = s; !dump.empty(); dump.pop())
		std::cout << dump.top() << " ";

}
int main() {
	vector<string> arr = { "program", "a2018",";", "var", "ab1" ,",", "cd" ,",", "e33a", "," ,"d18", ":", "integer", ";", "begin",
		"abl","=","33",";","cd","-","41","e33a","=","5",";","show","(","ab1", ")",";","end" };
	stack<string> s;
	vector<string> reserved_words = { "program","var","begin","show","end","integer" };
	int i = 0;
	int token_size = arr[i].size();
	cout << token_size << "tokensize" << endl;
	for (int z = 0; z < reserved_words.size(); z++) {
		if (arr[i] == reserved_words[z]) {
			cout << "RESERVED WORDsubstr: " << arr[i].substr(i, arr[i].size());
			token_size = 1;

		}
	}
	//isAccepted(arr, arr.size(), s);
	system("pause");
	return 0;
}
int getRow(string r) { //get row number associated with non-terminal
	int x = 0;
	if (r == "A") { x = 0; }
	else if (r == "B") { x = 1; }
	else if (r == "C") { x = 2; }
	else if (r == "D") { x = 3; }
	else if (r == "E") { x = 4; }
	else if (r == "F") { x = 5; }
	else if (r == "G") { x = 6; }
	else if (r == "H") { x = 7; }
	else if (r == "I") { x = 8; }
	else if (r == "J") { x = 9; }
	else if (r == "K") { x = 10; }
	else if (r == "W") { x = 11; }
	else if (r == "M") { x = 12; }
	else if (r == "N") { x = 13; }
	else if (r == "O") { x = 14; }
	else if (r == "P") { x = 15; }
	else if (r == "Q") { x = 16; }
	else if (r == "R") { x = 17; }
	else if (r == "S") { x = 18; }
	else if (r == "T") { x = 19; }
	else if (r == "U") { x = 20; }
	else if (r == "V") { x = 21; }

	return x;
}
int getCol(string c) { //get the column number associated with terminal
	int y = 0;
	if (c == "program") { y = 0; }
	if (c == "var") { y = 1; }
	if (c == "begin") { y = 2; }
	if (c == "end") { y = 3; }
	if (c == "integer") { y = 4; }
	if (c == "show") { y = 5; }
	if (c == "a") { y = 6; }
	if (c == "b") { y = 7; }
	if (c == "c") { y = 8; }
	if (c == "d") { y = 9; }
	if (c == "e") { y = 10; }
	if (c == "0") { y = 11; }
	if (c == "1") { y = 12; }
	if (c == "2") { y = 13; }
	if (c == "3") { y = 14; }
	if (c == "4") { y = 15; }
	if (c == "5") { y = 16; }
	if (c == "6") { y = 17; }
	if (c == "7") { y = 18; }
	if (c == "8") { y = 19; }
	if (c == "9") { y = 20; }
	if (c == "+") { y = 21; }
	if (c == "-") { y = 22; }
	if (c == "*") { y = 23; }
	if (c == "/") { y = 24; }
	if (c == "(") { y = 25; }
	if (c == ")") { y = 26; }
	if (c == "=") { y = 27; }
	if (c == "$") { y = 28; }
	if (c == ":") { y = 29; }
	if (c == ";") { y = 30; }
	if (c == ",") { y = 31; }
	return y;
}
