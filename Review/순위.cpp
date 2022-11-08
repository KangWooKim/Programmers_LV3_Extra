// https://school.programmers.co.kr/learn/courses/30/lessons/49191

#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    
    for(auto v : results){
        arr[v[0]][v[1]] = 1;
        arr[v[1]][v[0]] = -1;
    }
    for(int i = 1 ; i < n + 1 ; i++){
        vector<int> win,lose;
        for(int j = 1 ; j < n + 1 ; j++){
            if(arr[i][j] == -1) win.push_back(j);
            else if(arr[i][j] == 1) lose.push_back(j);
        }
        for(int a = 0 ; a < win.size() ; a++){
            for(int b = 0 ; b < lose.size() ; b++){
                arr[win[a]][lose[b]] = 1;
                arr[lose[b]][win[a]] = -1;
            }
        }
    }
    for(int i = 1 ; i < arr.size() ; i++){
        int cnt = 0;
        for(auto q : arr[i]){
            if(q == 0) cnt++;
            if(cnt == 3) {answer--; break;}
        }
        answer++;
    }
    return answer;
}
