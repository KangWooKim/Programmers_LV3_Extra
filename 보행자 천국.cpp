// https://school.programmers.co.kr/learn/courses/30/lessons/1832

#include <bits/stdc++.h>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<pair<int, int>>> r(m, vector<pair<int,int>>(n, make_pair(0, 0)));
    int res = 1;
    for(int i = 1 ; i < m ; i++){
        if(city_map[i][0] == 1) {res = 0; r[i][0] = {res, 0};}
        else
            r[i][0] = {res, 0};
    }
    
    res = 1;
    for(int i = 1 ; i < n ; i++){
        if(city_map[0][i] == 1) {res = 0; r[0][i] = {0, res};}
        else 
            r[0][i] = {0, res};
    }
    
    for(int y = 1 ; y < m ; y++){
        for(int x = 1 ; x < n ; x++){
            int r1; int r2;
            
            if(city_map[y][x - 1] == 0) r1 = (r[y][x - 1].first + r[y][x - 1].second) % MOD;
            else if(city_map[y][x - 1] == 1) r1 = 0;
            else if(city_map[y][x - 1] == 2) r1 = r[y][x - 1].second % MOD;
            
            if(city_map[y - 1][x] == 0) r2 = (r[y - 1][x].first + r[y- 1][x].second) % MOD;
            else if(city_map[y - 1][x] == 1) r2 = 0;
            else if(city_map[y - 1][x] == 2) r2 = r[y - 1][x].first % MOD;
            
            r[y][x] = {r2, r1};
        }
    }
    answer = (r[m - 1][n - 1].first + r[m - 1][n - 1].second) % MOD;
    return answer;
}
