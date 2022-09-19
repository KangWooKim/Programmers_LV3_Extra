// https://school.programmers.co.kr/learn/courses/15009/lessons/121688

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> ability, int number) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto& a : ability)
        pq.push(a);
    for(int i = 0 ; i < number ; i++){
        int c1 = pq.top(); pq.pop();
        int c2 = pq.top(); pq.pop();
        for(int j = 0 ; j < 2 ; j++){
            pq.push(c1 + c2);
        }
    }
    while(!pq.empty()){
        answer += pq.top(); pq.pop();
    }
    return answer;
}
