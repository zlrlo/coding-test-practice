#include <string>
#include <vector>

using namespace std;

string getU(string p) {
	int cnt = 0; 
	string str = ""; 

	for (auto i : p) {
		if (i == '(') {
			cnt += 1;
			str += '('; 
		}
		else if (i == ')') {
			cnt -= 1; 
			str += ')'; 
		}

		if (cnt == 0) return str; 
	}

}

bool checkCorrect(string u) {
	int cnt = 0; 

	for (auto i : u) {
		if (i == '(') cnt += 1;
		else if (i == ')') cnt -= 1; 

		if (cnt < 0) return false; 
	}

	if (cnt != 0) return false; 
	return true; 
}

string getReverse(string u) {
	string str = ""; 
	
	int len = u.length(); 
	for (int i = 1; i < len - 1; i++) {
		if (u[i] == '(') str += ')';
		else str += '('; 
	}

	return str; 
}

string Run(string p, int level) {
	if (p == "") return ""; 

	string u = getU(p);
	int vlen = p.length() - u.length();
	string v = p.substr(u.length(), vlen); 

	string ret = Run(v, level + 1);

	if (checkCorrect(u)) {
		return u + ret; 
	}
	else {
		u = getReverse(u);
		string tmp = "(" + ret + ")" + u; 
		return tmp; 
	}

}

int main() {
//string solution(string p) {
	string p = "()))((()";

	string answer = "";

	answer = Run(p, 0); 
	
	//return answer;
	return 0; 
}