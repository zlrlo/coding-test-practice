#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int y, x; 
	int level; 
};

void bfs(int m, int n, int startY, int startX, vector<vector<int>> &picture, bool via[110][110], int &number_of_area, int &max_size_of_one_area) {
	queue<Node> q; 
	q.push({ startY, startX, 0 });

	via[startY][startX] = true; 
	int name_of_area = picture[startY][startX];
	int cnt = 1; 

	int direct[4][2] = {
		0, 1,
		0, -1,
		1, 0,
		-1, 0
	};
	int dy, dx; 

	Node cur; 

	while (!q.empty()) {
		cur = q.front(); 
		q.pop(); 

		for (int i = 0; i < 4; i++) {
			dy = cur.y + direct[i][0]; 
			dx = cur.x + direct[i][1]; 

			if (dy < 0 || dy >= m || dx < 0 || dx >= n) continue; 
			if (picture[dy][dx] != name_of_area) continue; 
			if (picture[dy][dx] == 0) continue; 
			if (via[dy][dx]) continue; 

			via[dy][dx] = true;
			cnt += 1; 
			q.push({ dy, dx, cur.level + 1 }); 
		}
	}

	if (max_size_of_one_area < cnt) max_size_of_one_area = cnt; 
	number_of_area += 1; 
}

int main() {
//vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int m = 6; 
	int n = 4;
	vector<vector<int>> picture = { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} };
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	

	bool via[110][110] = { 0 }; 

	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (picture[y][x] == 0) continue; 
			if (via[y][x]) continue; 

			bfs(m, n, y, x, picture, via, number_of_area, max_size_of_one_area);
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	//return answer;
	return 0; 
}