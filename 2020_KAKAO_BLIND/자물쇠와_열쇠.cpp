// 자물쇠와 열쇠

#include <string>
#include <vector>
#include <cstring>
using namespace std;

int k, l;
int map[60][60];

void Rot(vector<vector<int>>& key) {
	vector<vector<int>> tmp(k, vector<int>(k, 0));

	for (int y = 0; y < k; y++) {
		for (int x = 0; x < k; x++) {
			tmp[x][k - 1 - y] = key[y][x];
		}
	}

	key = tmp;
}

int countHole(vector<vector<int>> lock) {
	int cnt = 0;

	for (int y = 0; y < l; y++) {
		for (int x = 0; x < l; x++) {
			if (lock[y][x] == 0) cnt += 1;
		}
	}

	return cnt;
}

void fillMap(vector<vector<int>> lock) {
	memset(map, -1, 60 * 60 * 4);

	for (int y = 0; y < l; y++) {
		for (int x = 0; x < l; x++) {
			map[y + (k - 1)][x + (k - 1)] = lock[y][x];
		}
	}
}

bool isOpen(int sy, int sx, int hole, vector<vector<int>> key) {
	int cnt = 0;

	for (int y = 0; y < k; y++) {
		for (int x = 0; x < k; x++) {
			if (map[sy + y][sx + x] == 0) {
				if (key[y][x] == 1) cnt += 1;
				else return false;
			}
			else if (map[sy + y][sx + x] == 1) {
				if (key[y][x] == 1) return false;
			}
		}
	}

	if (cnt == hole) return true;
	else return false;
}

int main() {
	//bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	vector<vector<int>> key = { {1, 0, 0},{1, 0, 0},{0, 0, 1} };
	vector<vector<int>> lock = { {1, 1, 1, 1, 1},{1, 1, 1, 0, 1},{1, 1, 1, 1, 1},{1, 0, 0, 1, 1},{1, 1, 1, 0, 0} };

	bool answer = false;

	k = key[0].size();
	l = lock[0].size();

	int hole = countHole(lock);

	fillMap(lock);

	for (int i = 0; i < 4; i++) {
		Rot(key);

		for (int y = 0; y < k + l - 1; y++) {
			for (int x = 0; x < k + l - 1; x++) {
				if (isOpen(y, x, hole, key)) {
					answer = true;
					//return answer; 
					return 0;

				}
			}
		}
	}

	//return answer;
	return 0;
}