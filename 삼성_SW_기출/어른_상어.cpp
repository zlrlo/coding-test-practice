#include <iostream>
#include <cstring>
using namespace std; 

enum { Up, Down, Left, Right };

struct Pos
{
	int y, x; 
};

struct Shark
{
	Pos pos; 
	int dir; 
	bool die;
	int order[4][4]; 
};

struct Smell
{
	int name; 
	int count; 
};

int n, m, k; 
int sharkMap[25][25]; 
Shark shark[450]; 
Smell smellMap[25][25];

void Init() {
	cin >> n >> m >> k;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> sharkMap[y][x];
			if (sharkMap[y][x] == 0) continue; 
			int name = sharkMap[y][x]; 
			shark[name].pos = { y, x }; 
			shark[name].die = false; 
			smellMap[y][x] = { sharkMap[y][x], k }; 
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> shark[i].dir;
		shark[i].dir -= 1; 
	}

	for (int i = 1; i <= m; i++) {
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				cin >> shark[i].order[y][x]; 
				shark[i].order[y][x] -= 1; 
			}
		}
	}

}

int Fight(int name1, int name2) {
	if (name1 < name2) {
		shark[name2].die = true;
		return name1; 
	}
	else {
		shark[name1].die = true;
		return name2; 
	}
}

void makeDirect(int direct[4][2], int curDir, int name) {
	for (int i = 0; i < 4; i++) {
		if (shark[name].order[curDir][i] == Up) {
			direct[i][0] = -1;
			direct[i][1] = 0;
		}
		else if (shark[name].order[curDir][i] == Down) {
			direct[i][0] = 1;
			direct[i][1] = 0;
		}
		else if (shark[name].order[curDir][i] == Left) {
			direct[i][0] = 0;
			direct[i][1] = -1;
		}
		else if (shark[name].order[curDir][i] == Right) {
			direct[i][0] = 0;
			direct[i][1] = 1;
		}
	}

}

bool checkSmell(int name, Shark curShark, int newSharkMap[25][25], int type) {
	int direct[4][2];
	makeDirect(direct, curShark.dir, name); 
	
	for (int i = 0; i < 4; i++) {
		int dy = curShark.pos.y + direct[i][0];
		int dx = curShark.pos.x + direct[i][1];
		if (dy < 0 || dy >= n || dx < 0 || dx >= n) continue;

		if ((type == 1 && smellMap[dy][dx].count == 0) || (type == 2 && smellMap[dy][dx].name == name)) {
			shark[name].pos = { dy, dx };

			int dir = shark[name].dir;
			shark[name].dir = shark[name].order[dir][i];

			if (newSharkMap[dy][dx] == 0) newSharkMap[dy][dx] = name;
			else {
				int competitor = newSharkMap[dy][dx];
				int winner = Fight(name, competitor); 
				newSharkMap[dy][dx] = winner; 
			}

			return true; 
		}
	}
	return false; 
}

void MoveShark() {
	int newSharkMap[25][25] = { 0 };
	 
	for (int i = 1; i <= m; i++) {
		bool findFlag = false;
		if (shark[i].die) continue; 
		findFlag = checkSmell(i, shark[i], newSharkMap, 1);
		if (findFlag) continue; 

		findFlag = checkSmell(i, shark[i], newSharkMap, 2);
	}

	memcpy(sharkMap, newSharkMap, 25 * 25 * 4); 
}

void removeSmell() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (smellMap[y][x].count == 0) continue; 
			smellMap[y][x].count -= 1; 
			if (smellMap[y][x].count == 0) smellMap[y][x].name = 0; 
		}
	}
}

void addSmell() {
	for (int i = 1; i <= m; i++) {
		if (shark[i].die) continue; 
		Pos pos = shark[i].pos; 
		smellMap[pos.y][pos.x] = { i, k }; 
	}
}

bool checkExit() {
	for (int i = 2; i <= m; i++) {
		if (shark[i].die == false) return false; 
	}

	return true; 
}

int main() {
	freopen("Text.txt", "r", stdin); 

	Init();

	int sec = 0; 
	bool overFlag = false;
	while (1) {
		sec += 1;
		MoveShark();
		removeSmell();
		addSmell(); 
		if (checkExit()) break; 
		if (sec >= 1000) {
			overFlag = true;
			break; 
		}
	}

	if (overFlag) cout << -1;
	else cout << sec; 

	return 0; 
}