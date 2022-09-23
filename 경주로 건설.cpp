// https://school.programmers.co.kr/learn/courses/30/lessons/67259#

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int range;
vector<int> mx = {1, -1, 0, 0};
vector<int> my = {0, 0, 1, -1};

bool range_over(int& x, int& y){
    if(x < 0 || y < 0 || x > range || y > range) return true;
    return false;
}



int solution(vector<vector<int>> board) {
    int answer = 0; range = board.size() - 1;
    vector<vector<vector<int>>> v(board.size(), vector<vector<int>>(board.size(), {987654321, 0, 0}));
    for(int i = 0 ; i < board.size(); i++){
        for(int j = 0 ; j < board[i].size() ; j++){
            if(board[i][j] == 1){
                v[i][j][1] = -1;
            }
        }
    }
    queue<vector<int>> q;
    if(v[1][0][1] != -1) q.push({1, 0, 100, 0, 2});
    if(v[0][1][1] != -1) q.push({0, 1, 100, 0, 0});

    while(!q.empty()){
        int now_x = q.front()[1]; int now_y = q.front()[0];
        int now_cost = q.front()[2]; int now_dir = q.front()[4]; q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int next_x = now_x + mx[i]; int next_y = now_y + my[i];
            if(range_over(next_x, next_y) || v[next_y][next_x][1] == -1) continue;
            if((i == 0 || i == 1) && (now_dir == 0 || now_dir == 1)){
                int next_cost = now_cost + 100;
                if(next_cost <= v[next_y][next_x][0]) {v[next_y][next_x][0] = next_cost; q.push({next_y, next_x, next_cost, 0, i});}
                else if(next_cost <= v[next_y][next_x][0] + 500) {q.push({next_y, next_x, next_cost, 0, i});}
            }
            if((i == 2 || i == 3) && (now_dir == 2 || now_dir == 3)){
                int next_cost = now_cost + 100;
                if(next_cost <= v[next_y][next_x][0]) {v[next_y][next_x][0] = next_cost; q.push({next_y, next_x, next_cost, 0, i});}
                else if(next_cost <= v[next_y][next_x][0] + 500) {q.push({next_y, next_x, next_cost, 0, i});}
            }
            else{
                int next_cost = now_cost + 600;
                if(next_cost <= v[next_y][next_x][0]) {v[next_y][next_x][0] = next_cost; q.push({next_y, next_x, next_cost, 0, i});}
                else if(next_cost <= v[next_y][next_x][0] + 500) {q.push({next_y, next_x, next_cost, 0, i});}
            }
        }

    }

    return v[board.size() - 1][board.size() - 1][0];
}
