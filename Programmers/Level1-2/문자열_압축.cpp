#include <string>
#include <vector>
using namespace std;

void makeCompressedWord(string & compressedWord, int cnt, string target) {
	if (cnt == 1) {
		compressedWord += target; 
	}
	else {
		compressedWord += (to_string(cnt) + target); 
	}
}

string getCompressedWord(int unit, string s, int sLen) {
	string compressedWord = "";

	string target = s.substr(0, unit); 
	int cnt = 1;

	int startPoint = unit; 

	for (int i = startPoint; i < sLen; i++) {
		string splitWord = s.substr(i, unit); 
		
		if (splitWord == target) {
			cnt += 1; 
		}
		else {
			makeCompressedWord(compressedWord, cnt, target);
			target = splitWord; 
			cnt = 1; 
		}

		int nextIndex = i + unit; 

		if (nextIndex >= sLen) {
			makeCompressedWord(compressedWord, cnt, target);
		}

		i = i + unit - 1; 

	}

	return compressedWord; 

}

int main() {
//int solution(string s) {
	string s = "a";
	int answer = 1;

	int sLen = s.length(); 

	for (int i = 1; i <= sLen / 2; i++) {
		string word = getCompressedWord(i, s, sLen);

		int wLen = word.length(); 

		if (answer == 1 || answer > wLen) {
			answer = wLen; 
		}
	}

	int de = 1; 

	return 0; 
	//return answer;
}