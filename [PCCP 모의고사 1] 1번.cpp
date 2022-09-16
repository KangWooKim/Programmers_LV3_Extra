// https://school.programmers.co.kr/learn/courses/15008/lessons/121683

#include <bits/stdc++.h>

using namespace std;

string solution(string input_string) {
    string answer = "";
    unordered_map<char, vector<int>> mp;
    
    for(int i = 0 ; i < input_string.length() ; i++){
        mp[input_string[i]].push_back(i);
    }
    
    auto iter = mp.begin();
    while(iter != mp.end()){
        vector<int> v = iter->second;
        if(v.size() == 1){++iter; continue;}
        for(int i = 1 ; i < v.size() ; i++){
            if(v[i] != v[i - 1] + 1){answer.push_back(iter->first); break;}
        }
        iter++;
    }
    if(answer == "") return "N";
    sort(answer.begin(), answer.end());
    return answer;
}
