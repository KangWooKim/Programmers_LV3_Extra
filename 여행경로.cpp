// https://school.programmers.co.kr/learn/courses/30/lessons/43164

#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end(), greater<vector<string>>());
    unordered_map<string, vector<string>> ump;
    for(int i = 0 ; i < tickets.size() ; i++){
        ump[tickets[i][0]].push_back(tickets[i][1]);
    }
    
    vector<string> vec = {"ICN"};
    
    while(!vec.empty()){
        string s = vec.back();
        if(ump.find(s) == ump.end() || ump[s].empty()){
            answer.push_back(s);
            vec.pop_back();
        }
        else{
            vec.push_back(ump[s].back());
            ump[s].pop_back();
        }
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}
