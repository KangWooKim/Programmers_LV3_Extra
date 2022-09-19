// https://school.programmers.co.kr/learn/courses/15009/lessons/121689

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> menu, vector<int> order, int k) {
    int answer = 1;
    vector<int> time;
    for(int i = 0 ; i < order.size() ; i++){
        time.push_back(i * k);
    }
    int now = 0;
    reverse(order.begin(), order.end()); reverse(time.begin(), time.end());
    while(!order.empty()){
        if(now < time.back()){
            now = time.back() + menu[order.back()];
        }
        else
            now += menu[order.back()];
        int cnt = 0;
        for(auto& i : time){
            if(i < now) cnt++;
        }
        answer = max(cnt, answer);
        order.pop_back(); time.pop_back();
    }
    return answer;
}
