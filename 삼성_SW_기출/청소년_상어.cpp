#include <iostream>
#include <cstring>
using namespace std; 

enum { U, UL, L, DL, D, DR, R, UR };

struct Fish
{
	int y, x; 
	int dir; 
};

struct Shark
{
	int y, x; 
	int dir; 
	int eat;
};

int arr[4][4];

bool die[17]; 

Shark shark; 
 
int direct[8][2] = {
	-1, 0,
	-1, -1,
	0, -1,
	1, -1,
	1, 0,
	1, 1,
	0, 1,
	-1, 1
};

void Init(Fish fish[17]) {
	int name; 
	int dir; 

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> name >> dir; 
			arr[y][x] = name; 
			fish[name] = { y, x, dir - 1 };

			if (y == 0 && x == 0) {
				die[name] = true;
				arr[y][x] = 0; 
				shark = { 0, 0, dir - 1, name }; 
			}
		}
	}

}

void moveFish(int shark_y, int shark_x, int sea[4][4], Fish fish[17]) {
	for (int i = 1; i <= 16; i++) {
		if (die[i]) continue; 

		int cur_name = i; 
		int cur_dir = fish[i].dir; 
		int cur_y = fish[i].y; 
		int cur_x = fish[i].x; 

		for (int j = 0; j < 8; j++) {
			int dir = (cur_dir + j) % 8;

			int dy = cur_y + direct[dir][0]; 
			int dx = cur_x + direct[dir][1];
			if (dy < 0 || dy >= 4 || dx < 0 || dx >= 4) continue; 
			if (dy == shark_y && dx == shark_x) continue;

			if (sea[dy][dx] == 0) {
				sea[dy][dx] = cur_name; 
				sea[cur_y][cur_x] = 0; 
				fish[cur_name] = { dy, dx, dir }; 
			}
			else {
				int next_name = sea[dy][dx];
				int next_dir = fish[next_name].dir; 

				swap(sea[dy][dx], sea[cur_y][cur_x]); 

				fish[next_name] = { cur_y, cur_x, next_dir }; 
				fish[cur_name] = { dy, dx, dir }; 
			}

			break; 
		}
	}
}

int maxValue = 0; 

void Run(int level, Shark shark, int c_sea[4][4], Fish c_fish[17]) {
	if (shark.eat > maxValue) maxValue = shark.eat;
	
	// 물고기 이동
	Fish fish[17]; 
	memcpy(fish, c_fish, 12 * 17); 

	int sea[4][4]; 
	memcpy(sea, c_sea, 4 * 4 * 4); 

	moveFish(shark.y, shark.x, sea, fish);

	// 상어 이동
	for (int i = 1; i <= 4; i++) { 
		int dy = shark.y + (direct[shark.dir][0] * i); 
		int dx = shark.x + (direct[shark.dir][1] * i); 

		if (dy < 0 || dy >= 4 || dx < 0 || dx >= 4) continue;		
		if (sea[dy][dx] == 0) continue;

		// 이동
		int name = sea[dy][dx]; 
		int fish_dir = fish[name].dir; 
		die[name] = true;

		Shark n_shark = { dy, dx, fish_dir, shark.eat + name }; 
		
		int n_sea[4][4];
		memcpy(n_sea, sea, 4 * 4 * 4);
		n_sea[dy][dx] = 0; 

		Run(level + 1, n_shark, n_sea, fish);
		die[name] = false;
	}

	return; 
}

int main() {
	freopen("Text.txt", "r", stdin); 

	Fish fish[17] = { 0 };

	Init(fish); 

	Run(0, shark, arr, fish);

	return 0; 
}