#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getNum(int sindex, vector<int> weak_clock, int wn, vector<int> dist) {
	int hour = weak_clock[sindex]; 
	
	int friends = dist.size();
	int eindex = sindex + wn - 1;

	int cindex = sindex; 

	for (int i = 0; i < friends; i++) {
		hour = hour + dist[i]; 

		int j; 
		for (j = cindex + 1; j <= eindex; j++) {
			if (hour < weak_clock[j]) {
				cindex = j; 
				hour = weak_clock[cindex]; 
				break; 
			}
		}

		if (j > eindex) return i + 1; 
		else if (i == friends - 1 && j <= eindex) return 0; 
	}
}

int main() {
	//int solution(int n, vector<int> weak, vector<int> dist) {
	int n = 12;
	vector<int> weak = { 1, 3, 4, 9, 10 };
	vector<int> dist = { 3, 5, 7 };

	int answer = -1;

	vector<int> weak_clock = weak;

	for (auto i : weak) {
		weak_clock.push_back(i + n); 
	}

	int wn = weak.size(); 
	for (int i = 0; i < wn; i++) {
		do {

			if (i == 1) {
				int de = 1; 
			}
			int num = getNum(i, weak_clock, wn, dist); 
			if(num != 0) if (answer < 0 || num < answer) answer = num; 

		} while (next_permutation(dist.begin(), dist.end())); 
	}

	return 0; 
	//return answer;
}