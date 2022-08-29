// https://school.programmers.co.kr/learn/courses/30/lessons/77886

#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(auto& c : s){
        int cnt = 0; string m = "";
        for(int i = 0 ; i < c.length() ; i++){
            if(m.length() == 3) m = m.substr(1, 2);
            m += c[i];
            if(m == "110"){
                c = c.replace(i - 2 , 3 , "");
                ++cnt;
                i = i - 5; if(i - 5 < -1) i = -1;
            }
        }
        
        int i;
        
        for(i = c.length() - 1 ; i > -1 ; i--){
            if(c[i] == '0') break;
        }
        
        string q = "";
        
        for(int i = 0 ; i < cnt ; i++)
            q.append("110");
        c = c.replace(i + 1, 0, q);
        answer.push_back(c);
    }
    
    return answer;
}
