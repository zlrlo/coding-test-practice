#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> table;
int column, row; 

unordered_map<string, bool> via; 

bool isPossible(string key) {
	unordered_map<string, bool> bucket; 

	for (int i = 0; i < row; i++) {
		string b_key = ""; 
		for (auto j : key) {
			int index = j - '0'; 
			b_key += table[i][index];
		}

		if (bucket.count(b_key) == 0) bucket[b_key] = true;
		else return false; 
	}

	return true; 
}

void Run(int level, int num, string key, int sindex) {
	if (level == num) {
		bool ret = isPossible(key);
		if (ret) {
			via[key] = true; 
		}
		return; 
	}

	for (int i = sindex; i < column; i++) {
		string str = key; 
		str += to_string(i); 
		if (via.count(str) == 0) {
			Run(level + 1, num, str, i + 1); 
		}
	}
}

bool isExist(string a, string b) {
	int bucket[10] = { 0 };

	for (auto i : b) {
		bucket[i - '0'] = 1; 
	}

	for (auto i : a) {
		if (bucket[i - '0'] != 1) return false; 
	}

	return true; 
}

bool compare(string b, string a) {
	if (b.length() < a.length()) return true; 
	return false; 
}

int main() {
//int solution(vector<vector<string>> relation) {
	vector<vector<string>> relation = { {"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"} };
	table = relation; 

	int answer = 0;
	
	column = relation[0].size(); 
	row = relation.size(); 

	for (int i = 1; i <= column; i++) {
		Run(0, i, "", 0);
	}

	vector<string> vect; 
	for (auto i : via) {
		vect.push_back(i.first);
	}

	sort(vect.begin(), vect.end(), compare); 

	int vsize = vect.size(); 

	vector<bool> die; 
	die.assign(vsize, 0); 

	for (int i = 0; i < vsize; i++) {
		if (die[i]) continue; 
		for (int j = i + 1; j < vsize; j++) {
			bool ret = isExist(vect[i], vect[j]); 
			if (!ret) continue;
			else die[j] = true; 
		}
	}

	for (auto i : die) {
		if (i == false) answer += 1; 
	}
 
	//return answer;
	return 0; 
}