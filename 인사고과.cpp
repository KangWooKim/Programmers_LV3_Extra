// https://school.programmers.co.kr/learn/courses/30/lessons/152995

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    if(v1[0] == v2[0]) return v1[1] <= v2[1];
    else return v1[0] >= v2[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    
    int s1 = scores[0][0]; int s2 = scores[0][1]; int res = s1 + s2;
    stable_sort(scores.begin(), scores.end(), cmp);
    int temp = 0;
    for(auto& s : scores){
        if(s[0] > s1 && s[1] > s2) return -1;
        int sum = s[1] + s[0];
        if(sum > res && temp <= s[1]){
            ++answer;
            temp = s[1];
        }
        
    }
    
    return answer;
}
