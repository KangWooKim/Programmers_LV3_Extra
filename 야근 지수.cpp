// https://school.programmers.co.kr/learn/courses/30/lessons/12927

#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    for(int i = 0 ; i < works.size() ; i++){
        pq.push(works[i]);
    }
    for(int i = 0 ; i < n ; i++){
        int val = pq.top();
        if(val <= 0) return 0;
        pq.pop();
        pq.push(val - 1);
    }
    for(int i = 0 ; i < works.size() ; i++){
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}
