#include <string>
#include <vector>

using namespace std;

void findFriend(int me, int bucket[33], int n) {
	if (me != 1 && bucket[me - 1] >= 2) {
		bucket[me - 1] -= 1; 
		bucket[me] += 1;
		return; 
	}

	if (me != n && bucket[me + 1] >= 2) {
		bucket[me + 1] -= 1; 
		bucket[me] += 1; 
		return; 
	}
}

int main() {
//int solution(int n, vector<int> lost, vector<int> reserve) {
	int n = 3;
	vector<int> lost = { 3 };
	vector<int> reserve = { 1 };
	int answer = 0;

	int bucket[33] = { 0 }; 

	for (int i = 1; i <= n; i++) {
		bucket[i] += 1; 
	}

	for (auto i : lost) {
		bucket[i] -= 1; 
	}

	for (auto i : reserve) {
		bucket[i] += 1; 
	}

	for (int i = 1; i <= n; i++) {
		if(bucket[i] == 0) {
			findFriend(i, bucket, n); 
		}
	}

	for (int i = 1; i <= n; i++) {
		if (bucket[i] != 0) answer += 1; 
	}

	return 0; 
	//return answer;
}