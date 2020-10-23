#include <iostream>
#include <vector>
using namespace std; 

const int MAX = 100010; 

vector<int> graph[MAX];

int parentInfo[MAX]; 
bool via[MAX]; 

void Run(int now) {
	via[now] = true; 

	for (auto i : graph[now]) {
		if (via[i]) continue; 
		parentInfo[i] = now; 
		Run(i); 
	}
}

int main() {
	freopen("Text.txt", "r", stdin); 

	int n; 
	cin >> n; 

	for (int i = 0; i < n - 1; i++) {
		int a, b; 
		cin >> a >> b; 

		graph[a].push_back(b); 
		graph[b].push_back(a); 
	}

	Run(1); 

	for (int i = 2; i <= n; i++) {
		cout << parentInfo[i] << "\n";
	}

	return 0; 
}