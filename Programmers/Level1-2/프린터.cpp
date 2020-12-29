#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Document
{
	int priority; 
	int location; 
};

bool compare(int b, int a) {
	if (b > a) return true;
	else return false; 
}

int main() {
//int solution(vector<int> priorities, int location) {
	vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
	int location = 0; 
	int answer = 0; 

	queue<Document> documents; 

	int index = 0; 
	for (auto i : priorities) {
		documents.push({ i, index++ }); 
	}

	sort(priorities.begin(), priorities.end(), compare); 

	int currentIndex = 0; 

	while (1) {
		if (documents.empty()) break; 

		Document cur = documents.front(); 
		documents.pop();
		if (cur.priority == priorities[currentIndex]) {
			if (cur.location == location) {
				answer = currentIndex + 1; 
				break; 
			}
			else {
				currentIndex += 1; 
			}
		}
		else {
			documents.push(cur); 
		}
	}

	return answer;
	return 0; 
}