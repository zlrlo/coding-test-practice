#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int y, x; 
};

int triangle[1100][1100];
int num = 1; 

Pos Move(int n, Pos spoint) {
	Pos epoint; 

	int direct[3][2] = {
		1, 0,
		0, 1,
		-1, -1
	};
 
	triangle[spoint.y][spoint.x] = num; 

	int cy = spoint.y, cx = spoint.x;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; ; i++) {
			int dy = cy + direct[j][0];
			int dx = cx + direct[j][1];
			if (dy < 0 || dy >= n || dx < 0 || dx >= n) break;
			if (triangle[dy][dx] != 0) break; 
			cy = dy;
			cx = dx;
			triangle[cy][cx] = num += 1;
		}
	}

	return { cy, cx }; 
}

int main() {
//vector<int> solution(int n) {
	int n = 2;
	vector<int> answer;

	if (n == 1) {
		answer.push_back(1); 
		return 0; 
	}
	else if (n == 2) {
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(3);
		return 0; 
	}

	Pos spoint = { 0, 0 }; 
	while (1) {
		spoint = Move(n, spoint); 
		if (triangle[spoint.y + 1][spoint.x] != 0) break; 
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (triangle[y][x] == 0) continue; 
			answer.push_back(triangle[y][x]);
		}
	}

	//return answer;
	return 0; 
}