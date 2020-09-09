#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int stage; 
	double rate; 
};

void getCount(vector<int>& stages, int &parent, int& childe, int stage) {
	for (auto i : stages) {
		if (i >= stage) {
			if (i == stage) childe += 1;
			parent += 1; 
		}
	}
}

bool compare(Node& b, Node& a) {
	if (b.rate > a.rate) return true; 
	if (b.rate == a.rate) {
		if (b.stage < a.stage) return true;
		return false; 
	}
	return false; 
}

int main() {
	//vector<int> solution(int N, vector<int> stages) {
	int N = 4;
	vector<int> stages = {4, 4, 4, 4, 4};
	vector<int> answer;

	vector<Node> vect; 

	for (int stage = 1; stage <= N; stage++) {
		int parent = 0, childe = 0; 
		getCount(stages, parent, childe, stage);

		if(childe == 0) vect.push_back({ stage, 0 });
		else {
			double rate = (double)childe / parent;
			vect.push_back({ stage, rate });
		}
	}

	sort(vect.begin(), vect.end(), compare); 

	for (auto i : vect) {
		answer.push_back(i.stage);
	}

	//return answer;
	return 0; 
}