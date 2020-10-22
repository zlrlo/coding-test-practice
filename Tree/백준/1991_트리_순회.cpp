#include <iostream>
#include <vector>
using namespace std;

char tree[30][2];
vector<char> preorder;
vector<char> postorder;
vector<char> inorder;

void Order(int level) {
	if (tree[level][0] >= 'A' && tree[level][0] <= 'Z') {
		preorder.push_back(tree[level][0]);
		Order(tree[level][0] - 'A');
		postorder.push_back(tree[level][0]);
	}

	inorder.push_back(level + 'A');

	if (tree[level][1] >= 'A' && tree[level][1] <= 'Z') {
		preorder.push_back(tree[level][1]);
		Order(tree[level][1] - 'A');
		postorder.push_back(tree[level][1]);
	}
}

void Print() {
	for (auto i : preorder) {
		cout << i;
	}
	cout << endl;
	for (auto i : inorder) {
		cout << i;
	}
	cout << endl;
	for (auto i : postorder) {
		cout << i;
	}
}

int main() {
	//freopen("text.txt", "r", stdin); 

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char root, left, right;
		cin >> root >> left >> right;

		tree[root - 'A'][0] = left;
		tree[root - 'A'][1] = right;
	}

	preorder.push_back('A');
	Order(0);
	postorder.push_back('A');

	Print();

	return 0;
}