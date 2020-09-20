#include <iostream>
#include <queue>
using namespace std; 

struct Pos
{
	int y, x; 
};

struct Taxi
{
	Pos pos; 
	long long fuel; 
};

struct Passenger
{
	Pos sPoint; 
	Pos ePoint; 
	int dist; 
	bool completion; 
};

struct Node
{
	Pos pos; 
	int level; 
};

int n, m; 
int taxiMap[25][25];
Taxi taxi;
Passenger passenger[450]; 

void Init() {
	cin >> n >> m >> taxi.fuel;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> taxiMap[y][x]; 
		}
	}

	cin >> taxi.pos.y >> taxi.pos.x; 
	taxi.pos.y -= 1;
	taxi.pos.x -= 1; 
	

	for (int i = 0; i < m; i++) {
		cin >> passenger[i].sPoint.y >> passenger[i].sPoint.x; 
		passenger[i].sPoint.y -= 1; 
		passenger[i].sPoint.x -= 1;
		cin >> passenger[i].ePoint.y >> passenger[i].ePoint.x;
		passenger[i].ePoint.y -= 1;
		passenger[i].ePoint.x -= 1;
	}
}

int getShortDist(Pos sPoint, Pos ePoint) {
	if (sPoint.y == ePoint.y && sPoint.x == ePoint.x) return 0;

	bool via[25][25] = { 0 }; 
	queue<Node> q; 
	via[sPoint.y][sPoint.x] = true; 
	q.push({ sPoint, 0 }); 
	
	int direct[4][2] = {
		0, 1,
		0, -1,
		1, 0,
		-1, 0
	};

	Node cur; 
	while (!q.empty()) {
		cur = q.front(); 
		q.pop(); 
		for (int i = 0; i < 4; i++) {
			int dy = cur.pos.y + direct[i][0]; 
			int dx = cur.pos.x + direct[i][1]; 
			if (dy < 0 || dy >= n || dx < 0 || dx >= n) continue; 
			if (via[dy][dx]) continue; 
			if (taxiMap[dy][dx] == 1) continue; 
			
			via[dy][dx] = 1; 
			if (dy == ePoint.y && dx == ePoint.x) {
				return cur.level + 1; 
			}
			else {
				q.push({ {dy, dx}, cur.level + 1 });
			}
		}

	}

	return -1; 
}

void setDist() {
	for (int i = 0; i < m; i++) {
		passenger[i].dist = getShortDist(passenger[i].sPoint, passenger[i].ePoint);
	}
}

bool compare(int& minDist, int& y, int& x, int dist, Pos pos) {
	if (minDist < 0 || dist < minDist) {
		minDist = dist;
		y = pos.y;
		x = pos.x;
		return true; 
	}

	if (minDist == dist) {
		if (pos.y < y) {
			minDist = dist;
			y = pos.y;
			x = pos.x;
			return true; 
		}

		if (pos.y == y && pos.x < x) {
			minDist = dist;
			y = pos.y;
			x = pos.x;
			return true; 
		}
	}

	return false; 
}

bool checkPassenger() {
	for (int i = 0; i < m; i++) {
		if (!passenger[i].completion) return false;
	}
	return true; 
}

int main() {
	freopen("Text.txt", "r", stdin); 

	Init(); 
	setDist(); 
	
	bool isPossible = false; 

	while (1) {
		int name = -1; 
		int minDist = -1; 
		int y, x; 
		for (int i = 0; i < m; i++) {
			if (passenger[i].completion) continue; 
			int dist = getShortDist(taxi.pos, passenger[i].sPoint);
			if (dist < 0) continue; 
			if (compare(minDist, y, x, dist, passenger[i].sPoint)) name = i; 
		}

		if (name < 0) break; 
		if (passenger[name].dist < 0) break; 
		taxi.fuel = taxi.fuel - minDist - passenger[name].dist;
		if (taxi.fuel < 0) break; 

		taxi.fuel += ((long long)passenger[name].dist * 2);
		taxi.pos = passenger[name].ePoint; 
		passenger[name].completion = true; 

		if (checkPassenger()) {
			isPossible = true; 
			break; 
		}
	}
	
	if (isPossible) cout << taxi.fuel;
	else cout << -1; 

	return 0; 
}