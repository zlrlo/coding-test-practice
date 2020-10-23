#include <iostream>
#include <vector>
#include <cstring>
using namespace std; 

struct Node
{
	int name; 
	int dist; 
};

vector<Node> tree[100010]; 
int n; 

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int root;
		cin >> root;

		int name, dist;
		for (int j = 0; ; j++) {
			cin >> name;
			if (name < 0) break;
			cin >> dist;
			tree[root].push_back({ name, dist });
		}
	}
	
}

bool via[100010]; 
int maxValue; 
int maxIndex; 

void Run(int now, int sum) {
	via[now] = true; 
	if (sum > maxValue) {
		maxValue = sum;
		maxIndex = now; 
	}

	for (auto i : tree[now]) {
		if (via[i.name]) continue; 
		Run(i.name, sum + i.dist);
	}


}

int main() {
	freopen("Text.txt", "r", stdin); 

	Input(); 

	Run(1, 0);
	memset(via, 0, n + 1); 
	Run(maxIndex, 0); 
	

	cout << maxValue; 

	return 0; 
}