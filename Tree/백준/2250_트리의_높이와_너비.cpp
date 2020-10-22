#include <iostream>
#include <map>
using namespace std;

struct Node
{
	int minWidth;
	int maxWidth;
};

struct Ans
{
	int name;
	int value;
};

int tree[10010][2];
int bucket[10010];
map<int, Node> levelMap;

int findRoot(int n) {
	for (int i = 0; i < n; i++) {
		if (bucket[i] == 1) {
			return i;
		}
	}
}

int index = 1;

void Order(int now, int level) {
	if (now < 0) return;

	Order(tree[now][0], level + 1);

	if (levelMap.count(level)) {
		levelMap[level].maxWidth = index++;
	}
	else {
		levelMap[level].minWidth = index++;
	}

	Order(tree[now][1], level + 1);
}

int main() {
	//freopen("text.txt", "r", stdin); 

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int root, left, right;
		cin >> root >> left >> right;

		bucket[root] += 1;
		bucket[left] += 1;
		bucket[right] += 1;

		tree[root][0] = left;
		tree[root][1] = right;
	}

	int root = findRoot(n);

	Order(root, 1);

	levelMap[root].maxWidth = levelMap[root].minWidth;

	Ans answer = { -1, -1 };
	for (auto i : levelMap) {
		int value = i.second.maxWidth - i.second.minWidth + 1;
		if (answer.name == -1) {
			answer.name = i.first;
			answer.value = value;
		}
		else {
			if (answer.value < value) {
				answer.name = i.first;
				answer.value = value;
			}
		}
	}

	cout << answer.name << " " << answer.value;

	return 0;
}