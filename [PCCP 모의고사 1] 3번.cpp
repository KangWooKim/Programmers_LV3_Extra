// https://school.programmers.co.kr/learn/courses/15008/lessons/121685

#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    for(auto& q : queries){
        int g = q[0]; int s = q[1] - 1;
        vector<pair<int, int>> info;
        info.push_back(make_pair(g, s));
        while(g != 1){
            s = s / 4;
            info.push_back(make_pair(--g, s));
        }
        
        string bean = "Rr";
        info.pop_back();
        reverse(info.begin(), info.end());
        for(auto& p : info){
            int s1 = p.second;
            if(bean == "RR") {bean = "RR";}
            else if(bean == "Rr" && s1 % 4 == 0) {bean = "RR";}
            else if(bean == "Rr"&& (s1 % 4 == 1 || s1 % 4 == 2)) {bean = "Rr";}
            else if(bean == "Rr" && s1 % 4 == 3) {bean = "rr";}
            else if(bean == "rr") {bean = "rr";}
            
        }
        answer.push_back(bean);
    }
    return answer;
}
