// https://school.programmers.co.kr/learn/courses/30/lessons/43236

#include <bits/stdc++.h>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(0); rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    int l = 0; int r = distance;
    while(l + 1 < r){
        int m = (l + r) / 2;
        vector<int> vec = rocks;
        int cnt = 0;
        for(int i = 0 ; i < vec.size() - 1 ; i++){
            if(vec[i + 1] - vec[i] < m){
                ++cnt;
                vec.erase(vec.begin() + i + 1);
                i--;
            }
        }
        if(cnt <= n){l = m; continue;}
        else{r = m; continue;}
    }
    return l;
}
