// https://school.programmers.co.kr/learn/courses/30/lessons/64062

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int l = 0; int r = 2e9;
    while(l + 1 < r){
        int m = (l + r) / 2;
        int cnt = 0;
        for(auto i : stones){
            if(i < m) cnt++;
            if(cnt == k) break;
            if(i >= m) cnt = 0;
        }
        if(cnt == k){r = m; continue;}
        else {l = m; continue;}
    }
    
    return l;
}
