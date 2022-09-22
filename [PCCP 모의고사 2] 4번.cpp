// https://school.programmers.co.kr/learn/courses/15009/lessons/121690

#include <bits/stdc++.h>

using namespace std;

vector<int> mx = {1, -1, 0, 0};
vector<int> my = {0, 0, 1, -1};

vector<int> jumpx = {2, -2, 0, 0};
vector<int> jumpy = {0, 0, 2, -2};

int a; int b;

bool range_over(int& x, int& y){
    if(x <= 0 || y <= 0 || x > a || y > b) return true;
    return false;
}

int solution(int n, int m, vector<vector<int>> hole) {
    int answer = 987654321; a = n; b = m;
    queue<vector<int>> q;
    vector<vector<vector<int>>> v(m + 1, vector<vector<int>>(n + 1, {0, 0, 987654321, 987654321}));
    v[1][1][2] = 0; v[1][1][3] = 0;
    q.push({1, 1, 0, 0});
    
    for(auto& h : hole){
        v[h[1]][h[0]] = {-1, -1, 0, 0};
    }
    
    while(!q.empty()){
        auto now = q.front(); q.pop();
        int now_x = now[0]; int now_y = now[1]; int dis = now[2]; int is_jump = now[3];
        
        
        for(int i = 0 ; i < mx.size() ; i++){
            int next_x = now_x + mx[i]; int next_y = now_y + my[i]; int next_dis = dis + 1;
            if(range_over(next_x, next_y)) continue;
            if(v[next_y][next_x][0] != -1){
                if(is_jump == 1 && v[next_y][next_x][3] > next_dis){
                    v[next_y][next_x][3] = next_dis;
                    q.push({next_x, next_y, next_dis, 1});
                }
                if(is_jump == 0 && v[next_y][next_x][2] > next_dis){
                    v[next_y][next_x][2] = next_dis;
                    q.push({next_x, next_y, next_dis, 0});
                }
            }
        }
        
        if(is_jump == 0){
            for(int i = 0 ; i < jumpx.size() ; i++){
                int next_x = now_x + jumpx[i]; int next_y = now_y + jumpy[i]; int next_dis = dis + 1;
                if(range_over(next_x, next_y)) continue;
                if(v[next_y][next_x][1] != -1){
                    if(v[next_y][next_x][3] > next_dis){
                        v[next_y][next_x][3] = next_dis;
                        q.push({next_x, next_y, next_dis, 1});
                    }
                }
            }
        }
    }
    answer = min(v[m][n][2], v[m][n][3]);
    if(answer == 987654321) answer = -1;
    return answer;
}
