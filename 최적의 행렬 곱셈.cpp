// https://school.programmers.co.kr/learn/courses/30/lessons/12942

#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> m;
int dp[201][201];

int dynamic(int l, int r){
    if(l == r) return 0;
    int& val = dp[l][r];
    if(val != -1) return val;
    val = 2e9;
    for(int k = l ; k < r ; k++){
        val = min(val, dynamic(l, k) + dynamic(k + 1, r) + m[l][0] * m[k][1] * m[r][1]);
    }
    return val;
}

int solution(vector<vector<int>> matrix_sizes) {
    m = matrix_sizes;
    for(int i = 0 ; i < 201 ; i++)
        for(int j = 0 ; j < 201 ; j++)
            dp[i][j] = -1;
    
    int answer = dynamic(0, m.size() - 1);
    return answer;
}
