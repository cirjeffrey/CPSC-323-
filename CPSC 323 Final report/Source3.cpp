#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
	vector<string> v;
	ifstream f;
	string s;
	f.open("finalp2.txt");
	remove("finalp3.txt");
	if (!f.is_open()) {
		cout << "error cant open file" << endl;

	}
	while (!f.eof()) {
		getline(f, s);
		istringstream iss(s);
		while (iss) {
			string tok;
			iss >> tok;
			v.push_back(tok);
		}
	}
	f.close();
	ofstream a;
	a.open("finalp3.cpp");
	a << "#include <iostream>";
	a << endl;
	a << "using namespace std;";
	a << endl;
	a << "int main()\n";

	a << "{\n";
	/*for (string s : v) {
		cout << s << endl;
	}*/
	vector<string>::iterator start;
	vector<string>::iterator end;
	vector<string> variables;
	int index2 = 0;
	start = find(v.begin(), v.end(), "var");
	
	end = find(v.begin(), v.end(), ":");
	a << "int ";
	for (start; start != end; start++) {
		if(*start != "var")
		a << *start;
		if (*start == ";")
			
			a << endl;
	}
	a << ";\n";
	start = find(v.begin(), v.end(), "begin");
	end = find(v.begin(), v.end(), "end");
	bool isShow = false;
	for (start + 1; start != end; start++) {
		if (*start == "begin") {}
		else if (isShow && *start == "(" || isShow && *start == ")") {

		}

		
		else if (*start == "show") {
			
			a << "\ncout << ";
			isShow = true;
			
			
		}
		else if (*start == ";")
		{
			a << *start;
			a << endl;
			isShow = false;
		}
		else
			a << *start;
	}
	a << "return 0;\n";
	a << "}";
	system("pause");
	return 0;
}