#include <string>
#include <vector>

using namespace std;

void getDays(vector<int> &days, vector<int> &progresses, vector<int> &speeds) {
	int size = progresses.size(); 
	
	for (int i = 0; i < size; i++) {
		int value = ((100 - progresses[i] - 1) / speeds[i]) + 1;
		days.push_back(value); 
	}
}

int main() {
	//vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
	vector<int> speeds = { 1, 1, 1, 1, 1, 1 };

	vector<int> answer;
	
	vector<int> days; 
	getDays(days, progresses, speeds); 

	int target = days[0];
	int cnt = 1; 
	int size = days.size(); 

	for (int i = 1; i < size; i++) {
		if (days[i] <= target) {
			cnt += 1; 
		}
		else {
			answer.push_back(cnt); 
			cnt = 1; 
			target = days[i]; 
		}

		if (i == size - 1) answer.push_back(cnt); 
	}

	//return answer;
	return 0; 
}