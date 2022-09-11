// https://school.programmers.co.kr/learn/courses/30/lessons/72413

#include <bits/stdc++.h>

int city;
int r[201][201];

using namespace std;

void floyd(vector<vector<int>>& fares){
    for(int i = 1 ; i <= city ; i++)
        for(int j = 1 ; j <= city ; j++)
            r[i][j] = 1e9;
    
    for(int i = 1 ; i <= city ; i++)
        r[i][i] = 0;
    
    for(auto& v : fares){
        r[v[0]][v[1]] = v[2];
        r[v[1]][v[0]] = v[2];
    }
    
    for(int k = 1 ; k <= city ; k++){
        for(int a = 1 ; a <= city ; a++){
            for(int b = 1 ; b <= city ; b++){
                r[a][b] = min(r[a][b], r[a][k] + r[k][b]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    city = n;
    floyd(fares);
    
    for(int i = 1 ; i <= city ; i++){
        if(r[s][i] != 1e9 && r[i][a] != 1e9 && r[i][b] != 1e9){
            int fee = r[s][i] + r[i][a] + r[i][b];
            answer = min(answer, fee);
        }
        else continue;
    }
    return answer;
}
