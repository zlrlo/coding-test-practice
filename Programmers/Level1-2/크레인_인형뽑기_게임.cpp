#include <string>
#include <vector>
#include <iostream>

using namespace std;

void startGame(vector<int> &bucket, vector<int> vect[35], vector<int> moves) {
    for(auto i : moves){
        if(!vect[i - 1].empty()) {
            int doll = vect[i- 1].back(); 
            vect[i- 1].pop_back(); 
            bucket.push_back(doll);
        }

    }
}

int getPopCount(vector<int> bucket) {
    int cnt = 0; 

    for(auto i : bucket){
        cout << i << endl; 
    }

    vector<int> stack; 

    for(auto i : bucket) {
        if(stack.empty()) {
            stack.push_back(i);
        }
        else {
            if(stack.back() == i) {
                cnt += 2; 
                stack.pop_back(); 
            }
            else stack.push_back(i);
        }
    }   

    return cnt; 
}

int solution(vector<vector<int>> board, vector<int> moves) {
     int answer = 0;

    int boardY = board.size(); 
    int boardX = board[0].size(); 

    vector<int> vect[35];

    for(int x = 0; x < boardX; x++) {
        for(int y = boardY - 1; y >=0; y--) {
            if(board[y][x] == 0) continue; 
            vect[x].push_back(board[y][x]);
        }
    }

    vector<int> bucket; 

    startGame(bucket, vect, moves); 

    answer = getPopCount(bucket); 

    return answer;
}
