// https://school.programmers.co.kr/learn/courses/30/lessons/42861

#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0; vector<vector<int>> v = costs;
    sort(v.begin(), v.end(), compare);
    set<int> s; int idx = 0; s.insert(0);
    while(s.size() < n && v.size() > 0){
        if(s.count(v[idx][0]) == 1 && s.count(v[idx][1]) == 1){
            v.erase(v.begin() + idx);
        }
        else if(s.count(v[idx][0]) == 0 && s.count(v[idx][1]) == 1){
            answer += v[idx][2];
            s.insert(v[idx][0]);
            idx = 0;
        }
        else if(s.count(v[idx][0]) == 1 && s.count(v[idx][1]) == 0){
            answer += v[idx][2];
            s.insert(v[idx][1]);
            idx = 0;
        }
        else idx++;
    }
    return answer;
}
