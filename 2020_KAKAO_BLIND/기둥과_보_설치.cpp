#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	int x, y, type;
};

bool map[110][110][2]; 

bool Install(int x, int y, int type, int n) {
	if (type == 0) {
		// 기둥
		if (y == 0) {
			// 바닥 위
			return true; 
		}

		if (map[y][x][1] == 1 || (x - 1 >= 0 && map[y][x - 1][1] == 1)) {
			// 보의 한쪽 끝
			return true; 
		}

		if (map[y - 1][x][0] == 1) {
			// 기둥 위
			return true;
		}
	
	}
	else {
		// 보
		if ((y - 1 >= 0 && map[y - 1][x][0] == 1) || (y - 1 >= 0 && x + 1 <= n &&  map[y - 1][x + 1][0] == 1)) {
			// 한쪽 끝이 기둥 위 
			return true; 
		}

		if ((x - 1 >= 0 && map[y][x - 1][1] == 1) && (x + 1 <= n) && map[y][x + 1][1] == 1) {
			// 양쪽 끝 다른 보 동시 연결
			return true; 
		}
	}

	return false; 
}

bool Uninstall(int x, int y, int type, int n, vector<Node> &install_list) {
	// 일단 삭제
	map[y][x][type] = 0;

	bool isPossible = true; 

	for (auto i = install_list.begin(); i != install_list.end(); ++i) {
		if (map[i->y][i->x][i->type] == 0) continue; 

		map[i->y][i->x][i->type] = 0; 

		bool ret = Install(i->x, i->y, i->type, n);

		map[i->y][i->x][i->type] = 1;

		if (!ret) {
			isPossible = false;
			break; 
		}
	}

	if (!isPossible) map[y][x][type] = 1; 
	return isPossible; 
}

bool compare(Node b, Node a) {
	if (b.x < a.x) return true; 
	if (b.x == a.x && b.y < a.y) return true; 
	if (b.x == a.x && b.y == a.y && b.type < a.type) return true; 
	return false; 
}

int main() {
//vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	int n = 5; 
	vector<vector<int>> build_frame = { {1, 0, 0, 1},{1, 1, 1, 1},{2, 1, 0, 1},{2, 2, 1, 1},{5, 0, 0, 1},{5, 1, 0, 1},{4, 2, 1, 1},{3, 2, 1, 1} };
	vector<vector<int>> answer;
	
	int x, y, a, b; 
	vector<Node> install_list; 

	for (auto i : build_frame) {
		x = i[0]; 
		y = i[1];
		a = i[2];
		b = i[3];

		if (b == 1) {
			if (Install(x, y, a, n)) {
				map[y][x][a] = 1; 
				install_list.push_back({x, y, a});
			}
		}
		else {
			if (Uninstall(x, y, a, n, install_list)) {
				for (auto i = install_list.begin(); i != install_list.end(); ++i) {
					if (i->x == x && i->y == y && i->type == a) {
						install_list.erase(i);
						break;
					}
				}
			}
		}
	}

	sort(install_list.begin(), install_list.end(), compare);

	for (auto i : install_list) {
		vector<int> tmp; 
		tmp.push_back(i.x); 
		tmp.push_back(i.y); 
		tmp.push_back(i.type); 

		answer.push_back(tmp); 
	}
	
	//return answer;

	return 0; 
}