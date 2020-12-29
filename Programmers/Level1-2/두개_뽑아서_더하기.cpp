#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> bucket; 

int main() {
//vector<int> solution(vector<int> numbers) {
	vector<int> numbers = { 5, 0, 2, 7 };
	vector<int> answer;

	int len = numbers.size(); 

	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			bucket.insert(numbers[i] + numbers[j]);
		}
	}

	answer.assign(bucket.begin(), bucket.end()); 

	//return answer;
	return 0; 
}