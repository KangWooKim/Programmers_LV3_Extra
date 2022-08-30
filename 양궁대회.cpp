// https://school.programmers.co.kr/learn/courses/30/lessons/92342

#include <bits/stdc++.h>

using namespace std;

int score_check(vector<int> v1, vector<int> v2){
    int score = 10; int s1 = 0; int s2 = 0;
    for(int i = 0 ; i < v1.size() ; i++){
        if(v1[i] >= v2[i] && v1[i] != 0){s1 = s1 + score; score--; continue;}
        else if(v2[i] != 0 && v1[i] < v2[i]){s2 = s2 + score; score--; continue;}
        score--;
    }
    return s2 - s1;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> vec;
    for(auto c : info){
        vec.push_back(c + 1);
    }
    vector<int> v;
    int val = 0;
    
    for(int a = 0 ; a < (1 << 11) ; a++){
        int idx = -1;
        for(int b = 1 ; b < (1 << 11) ; b = b * 2){
            ++idx;
            if(b & a) v.push_back(vec[idx]);
            else v.push_back(0);
        }
        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum <= n && score_check(info, v) > val){val = score_check(info, v); answer = v;}
        if(answer.size() != 0 && sum <= n && score_check(info, v) == val){
            bool l = false;
            for(int p = 10 ; p >= 0 ; p--){
                if(v[p] != 0 && v[p] > answer[p]){l = true; break;}
                else if(answer[p] != 0 && v[p] <= answer[p]){break;}
            }
            if(l) answer = v;
        }
        v.clear();
    }
    if(answer.size() == 0) {answer.push_back(-1); return answer;}
    int sum = accumulate(answer.begin(), answer.end(), 0);
    if(sum < n){
        answer[10] += n - sum;
    }
    return answer;
}
