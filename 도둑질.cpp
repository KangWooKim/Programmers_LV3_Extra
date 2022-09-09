// https://school.programmers.co.kr/learn/courses/30/lessons/42897

#include <bits/stdc++.h>

using namespace std;


int solution(vector<int> money) {
    vector<int> thief1(money.size(),0);
    vector<int> thief2(money.size(),0);
    int answer = 0;
    thief1[0]=money[0];
    thief1[1]=money[0];
    thief2[0]=0;
    thief2[1]=money[1];
    for(int i=2;i<money.size()-1;i++){
        thief1[i]=max(thief1[i-2]+money[i],thief1[i-1]);
    }
    for(int i=2;i<money.size();i++){
        thief2[i]=max(thief2[i-2]+money[i],thief2[i-1]);
    }
    answer = max(thief1[money.size()-2], thief2[money.size()-1]);
    return answer;
}
