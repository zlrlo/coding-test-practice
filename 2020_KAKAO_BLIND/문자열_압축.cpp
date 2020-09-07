#include <string>
#include <vector>

using namespace std;

int slen; 

int getZipLen(string s, int n) {
	string str = "";

	int eIndex = s.length(); 
	
	for (int i = 0; i < slen; i++) {
		string target = s.substr(i, n); 
		int cnt = 1; 

		int pointer = i; 
		while (1) {
			pointer = pointer + n;

			if (pointer >= eIndex) break; 

			string tmp = s.substr(pointer, n);

			if (tmp == target) {
				cnt += 1; 
			}
			else break; 
			
		}

		if (cnt == 1) str += target; 
		
		else str = str + to_string(cnt) + target; 
		
		i = i + (cnt * n) - 1; 
	}

	return str.length(); 
}

int main() {
//int solution(string s) {
	string s = "abcabcdede";
	
	slen = s.length();

	int answer = slen;

	for (int i = 1; i <= slen / 2; i++) {
		int len = getZipLen(s, i); 
		if (len < answer) answer = len; 
	}

	//return answer;
	return 0; 
}