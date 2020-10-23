#include <iostream>
#include <vector>
#include <cstring>
using namespace std; 

struct Node
{
	int name; 
	int dist; 
};

int n; 
vector<Node> tree[10010]; 
bool exitFlag; 

void Input() {
	cin >> n; 
	if (n == 1) {
		exitFlag = true; 
		return; 
	}
	
	int parent, child, dist; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> parent >> child >> dist; 
			tree[parent].push_back({ child, dist }); 
			tree[child].push_back({ parent, dist });
		}
	}
}


bool via[10010]; 
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
	//freopen("Text.txt", "r", stdin); 

	Input(); 

	if (exitFlag) {
		cout << 0; 
		return 0; 
	}

	Run(1, 0); 

	memset(via, 0, n + 1); 
	Run(maxIndex, 0); 

	cout << maxValue; 
	return 0; 
}