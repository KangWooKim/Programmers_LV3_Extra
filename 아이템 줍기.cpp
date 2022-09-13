//https://school.programmers.co.kr/learn/courses/30/lessons/87694

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> new_XY(110, vector<int>(110, 0));
    characterX *= 2; characterY *= 2; itemX *= 2; itemY *= 2;
    
    for(auto& r : rectangle){
        for(auto& i : r){
            i *= 2;
        }
        for(int i = r[0] ; i <= r[2] ; i++){
            new_XY[r[1]][i] = 1;
            new_XY[r[3]][i] = 1;
        }
        for(int i = r[1] ; i <= r[3] ; i++){
            new_XY[i][r[0]] = 1;
            new_XY[i][r[2]] = 1;
        }
    }
    
    for(auto& r : rectangle){
        for(int i = r[0] + 1 ; i < r[2] ; i++)
            for(int j = r[1] + 1 ; j < r[3] ; j++)
                new_XY[j][i] = 0;
    }
    
    queue<pair<int, int>> q;
    q.push({characterY, characterX});
    vector<int> dx = {-1, 1, 0, 0}; vector<int> dy = {0, 0, -1, 1};
    while(!q.empty()){
        int now_X = q.front().second;
        int now_Y = q.front().first;
        q.pop();
        
        if(now_X == itemX && now_Y == itemY) break;
        
        for(int i = 0 ; i < dx.size() ; i++){
            int next_X = now_X + dx[i];
            int next_Y = now_Y + dy[i];
            
            if(new_XY[next_Y][next_X] == 1){
                q.push(make_pair(next_Y, next_X));
                new_XY[next_Y][next_X] = new_XY[now_Y][now_X] + 1;
            }
        }
    }
    answer = new_XY[itemY][itemX] / 2;
    return answer;
}
