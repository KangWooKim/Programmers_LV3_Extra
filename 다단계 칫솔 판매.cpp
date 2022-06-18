// https://programmers.co.kr/learn/courses/30/lessons/77486

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, int> money;
    for(int i = 0 ; i < enroll.size() ; i++){
        money[enroll[i]] = 0;
    }
    map<string, string> parents;
    for(int i = 0 ; i < enroll.size() ; i++){
        parents[enroll[i]] = referral[i];
    }
    for(int i = 0 ; i < seller.size() ; i++){
        money[seller[i]] += amount[i] * 100 * 0.9;
        string child = seller[i];
        int k = amount[i] * 100 * 0.1;
        while(true){
            string parent = parents[child];
            if(parent == "-"){
                break;
            }
            if(k < 10){
                money[parent] += k;
                break;
            }
            
            money[parent] += k - k / 10;
            
            child = parents[child];
            k /= 10;
        }
    }
    for(int i = 0 ; i < enroll.size() ; i++){
        answer.push_back(money[enroll[i]]);
    }
    return answer;
}
