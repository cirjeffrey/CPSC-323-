#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
void showStack(stack<char> s);
int getRow(char r);
int getCol(char c);
bool isAccepted(string w, stack<char>s) {
	string table[6][9] = { "a=E"," "," ", " "," "," "," "," "," ",
		"TQ", " "," "," "," ","TQ"," "," "," "
		," ","+TQ","-TQ"," "," "," ","lambda"," "," ",
		"FR"," "," "," "," ","FR"," "," "," ",
		" ","lambda","lambda","*FR","/FR","","lambda"," "," ",
		"a"," "," "," "," ","(E)"," "," ","b" };

	int i = 0; //index for iterating through the word
	char t; //the popped char
	int r; //the row number
	int c; // the column number
	string e; //the string in specified index from table

	s.push('$');
	s.push('S');
	t = s.top();
	s.pop();
	//this while loop will never finish because the function returns true or false
	//once it matches $ or " " during each iteration
	while (i < w.length()) {

		int r = getRow(t);
		int c = getCol(w[i]);
		e = table[r][c];
		if (t == '$') //accepted
			return true;

		else if (t == w[i]) { //match
			showStack(s);
			cout << t << " == " << w[i] << "match" << endl;
			t = s.top();
			s.pop();
			i++;
		}
		else if (e == " ") { //rejected
			return false;
		}
		else if (e == "lambda")
		{
			t = s.top();
			s.pop();
		}

		else {

			for (int j = e.length() - 1; j >= 0; j--) {
				s.push(e[j]);

			}
			showStack(s);
			t = s.top();
			s.pop();


		}
	}



}





void showStack(stack<char> s) {
	for (std::stack<char> dump = s; !dump.empty(); dump.pop())
		std::cout << dump.top() << " ";

}
int main() {
	string arr[] = { "a=(a+a)*b$","a=a*(b-a)$" , "a=(a+a)b$" };


	/*for (int i = 0; i < 5; ++i)
	{
	for (int j = 0; j < 8 ; ++j)
	{
	std::cout << "row" << i <<"col"<<j<< table[i][j] << ' ';
	}
	std::cout << std::endl;
	}*/
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		stack<char> s;
		if (isAccepted(arr[i], s)) {
			cout << "--------------------------" << endl;
			cout << i + 1 << "." << arr[i];
			cout << "accepted" << endl;
			cout << "--------------------------" << endl;
		}
		else {
			cout << "--------------------------" << endl;
			cout << i + 1 << "." << arr[i];
			cout << "rejected" << endl;
			cout << "--------------------------" << endl;

		}

	}







	system("pause");
	return 0;
}
int getRow(char r) { //get row number associated with non-terminal
	int x = 0;
	switch (r) {
	case 'S':
		x = 0;
		break;
	case 'E':
		x = 1;
		break;
	case 'T':
		x = 3;
		break;
	case 'F':
		x = 5;
		break;
	case 'R':
		x = 4;
		break;
	case 'Q':
		x = 2;
	default:
		break;
	}
	return x;
}
int getCol(char c) { //get the column number associated with terminal
	int y = 0;
	switch (c) {
	case 'b':
		y = 8;
		break;
	case '(':
		y = 5;
		break;
	case ')':
		y = 6;
		break;
	case 'a':
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
