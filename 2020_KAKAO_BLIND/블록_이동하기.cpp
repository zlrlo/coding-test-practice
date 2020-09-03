// 블록 이동하기

#include <string>
#include <vector>
#include <queue>
using namespace std;

enum { Garo, Sero };

struct Node
{
	int y1, x1, y2, x2; 
	int type; 
	int level; 
};

vector<vector<int>> map; 
int n; 

queue<Node> q; 

bool via[110][110][110][110]; 

bool checkRange(int y1, int x1, int y2, int x2) {
	if (y1 < 0 || y1 >= n || x1 < 0 || x1 >= n) return false; 
	if (y2 < 0 || y2 >= n || x2 < 0 || x2 >= n) return false;
	if (map[y1][x1] == 1) return false; 
	if (map[y2][x2] == 1) return false; 
	return true; 
}

void Move(Node cur) {
	int direct[4][2] = {
		0, 1,
		0, -1,
		1, 0,
		-1, 0
	};

	int dy1, dx1, dy2, dx2; 

	for (int i = 0; i < 4; i++) {
		dy1 = cur.y1 + direct[i][0]; 
		dx1 = cur.x1 + direct[i][1]; 
		dy2 = cur.y2 + direct[i][0]; 
		dx2 = cur.x2 + direct[i][1]; 

		if (!checkRange(dy1, dx1, dy2, dx2)) continue; 
		if (via[dy1][dx1][dy2][dx2] == 1) continue;

		via[dy1][dx1][dy2][dx2] = 1; 
		q.push({ dy1, dx1, dy2, dx2, cur.type, cur.level + 1 }); 
	}
}

void Rot(int y1, int x1, int y2, int x2, int level, int type) {
	int direct[4][2] = {
		1, 0,
		-1, 0,
		0, 1,
		0, -1
	};

	int dy1, dx1, dy2, dx2;

	if (type == Garo) {
		for (int i = 0; i < 2; i++) {
			dy1 = y1 + direct[i][0];
			dx1 = x1 + direct[i][1];
			dy2 = y2 + direct[i][0];
			dx2 = x2 + direct[i][1];

			if (!checkRange(dy1, dx1, dy2, dx2)) continue;

			dy2 = dy1;
			dx2 = dx1;

			if (i == 0) {
				// 아래
				if (via[y1][x1][dy2][dx2] == 1) continue;
				via[y1][x1][dy2][dx2] = 1;
				q.push({ y1, x1, dy2, dx2, Sero, level + 1 });
			}
			else {
				// 위
				if (via[dy2][dx2][y1][x1] == 1) continue;
				via[dy2][dx2][y1][x1] = 1;
				q.push({ dy2, dx2, y1, x1, Sero, level + 1 });

			}
		}
	}
	else {
		for (int i = 2; i < 4; i++) {
			dy1 = y1 + direct[i][0];
			dx1 = x1 + direct[i][1];
			dy2 = y2 + direct[i][0];
			dx2 = x2 + direct[i][1];

			if (!checkRange(dy1, dx1, dy2, dx2)) continue;

			dy2 = dy1;
			dx2 = dx1;

			if (i == 2) {
				// 오른쪽
				if (via[y1][x1][dy2][dx2] == 1) continue;
				via[y1][x1][dy2][dx2] = 1;
				q.push({ y1, x1, dy2, dx2, Garo, level + 1 });

			}
			else {
				// 왼쪽
				if (via[dy2][dx2][y1][x1] == 1) continue;
				via[dy2][dx2][y1][x1] = 1;
				q.push({ dy2, dx2, y1, x1, Garo, level + 1 });

			}
		}
	}	
}

int Bfs() {
	q.push({ 0, 0, 0, 1, Garo, 0 }); 
	via[0][0][0][1] = true; 

	Node cur; 

	while (!q.empty()) {
		cur = q.front(); 
		q.pop(); 

		if (cur.y1 == n - 1 && cur.x1 == n - 1) {
			return cur.level; 
		}

		if (cur.y2 == n - 1 && cur.x2 == n - 1) {
			return cur.level; 
		}

		Move(cur); 
		Rot(cur.y1, cur.x1, cur.y2, cur.x2, cur.level, cur.type);
		Rot(cur.y2, cur.x2, cur.y1, cur.x1, cur.level, cur.type);
	}
}

int main() {
//int solution(vector<vector<int>> board) {
	vector<vector<int>> board = { {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} }; 
	int answer = 0;

	map = board; 
	n = board.size(); 

	answer = Bfs(); 

	//return answer;
	return 0; 
}