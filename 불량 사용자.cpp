// https://school.programmers.co.kr/learn/courses/30/lessons/64064

#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<string>> list;
    sort(user_id.begin(), user_id.end());
    do{
        bool b = true;
        for(int i = 0 ; i < banned_id.size() ; i++){
            for(int idx = 0 ; idx < banned_id[i].length() ; idx++){
                if(banned_id[i].length() != user_id[i].length()){b = false; break;}
                else if(banned_id[i][idx] == '*') continue;
                else if(banned_id[i][idx] == user_id[i][idx]) continue;
                else if(banned_id[i][idx] != user_id[i][idx]){b = false; break;}
            }
            if(!b) break;
        }
        if(b){
            vector<string> v(user_id.begin(), user_id.begin() + banned_id.size());
            sort(v.begin(), v.end());
            if(find(list.begin(), list.end(), v) == list.end()) list.push_back(v);
        }
    }while(next_permutation(user_id.begin(), user_id.end()));
    
    return list.size();
}
