// https://school.programmers.co.kr/learn/courses/30/lessons/12938

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s){
        answer.push_back(-1);
        return answer;
    }
    if(s % n == 0){
        for(int i = 0 ; i < n ; i++){
            answer.push_back(s / n);
        }
    }
    else{
        int val = s % n;
        for(int i = 0 ; i < n - val ; i++){
            answer.push_back(s / n);
        }
        for(int i = 0 ; i < val ;i++){
            answer.push_back((s + n - 1) / n);
        }
    }
    return answer;
}
