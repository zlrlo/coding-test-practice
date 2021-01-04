#include <string>
#include <vector>
#include <iostream>

using namespace std;

int direct[4][2] = {
    0, 1,
    0, -1,
    1, 0,
    -1, 0
};

bool via[30][30];

int minMoney = 21e8; 

int minValue;

int minMap[30][30];

void Run(int y, int x, int level, vector<vector<int>> board, int boardSize, int dir, int money) {
    if(minMap[y][x] == 0){
        minMap[y][x] = money;
    }
    else {
        if(minMap[y][x] < money) return; 
        else minMap[y][x] = money;
    }

    if(y == boardSize - 1 && x == boardSize - 1) {
        if(money < minMoney) minMoney = money; 
        return;
    }

    if(money >= minMoney) return; 

    if(minMoney == minValue) return; 

     int minMoney = 21e8; 

    for(int i = 0; i < 4; i++) {
        int dy = y + direct[i][0];
        int dx = x + direct[i][1];
        if(dy < 0 || dy >= boardSize || dx < 0 || dx >= boardSize) continue;
        if(via[dy][dx]) continue; 
        if(board[dy][dx]) continue;

        via[dy][dx] = true; 

        int nextMoney = money; 

        if(level == 0) nextMoney += 100; 
        else {
            if(dir == i) nextMoney += 100; 
            else nextMoney += 600; 
        }


        Run(dy, dx, level + 1, board, boardSize, i, nextMoney);

        via[dy][dx] = false; 
    }

}

int solution(vector<vector<int>> board) {
    int answer = 0;

    int boardSize = board.size(); 

    minValue = (((boardSize - 1) * 2) * 100) + 500;

    via[0][0] = true;
    Run(0, 0, 0, board, boardSize, 0, 0); 

    answer = minMoney;
    return answer;
}