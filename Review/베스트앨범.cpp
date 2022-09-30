// https://school.programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    else
        return p1.first > p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> mp;
    unordered_map<string, vector<pair<int, int>>> mp1;
    for(int i = 0 ; i < genres.size() ; i++){
        mp[genres[i]] += plays[i];
        mp1[genres[i]].push_back(make_pair(plays[i], i));
    }
    auto iter = mp1.begin();
    while(iter != mp1.end()){
        sort(iter->second.begin(), iter->second.end(), cmp);
        ++iter;
    }
    auto iter1 = mp.begin();
    vector<pair<int, string>> v;
    while(iter1 != mp.end()){
        int a = iter1->second;
        string b = iter1->first;
        v.push_back(make_pair(a, b));
        ++iter1;
    }
    sort(v.begin(), v.end());
    
    for(int i = v.size() - 1 ; i > -1 ; i--){
        string g = v[i].second;
        answer.push_back(mp1[g][0].second);
        if(mp1[g].size() > 1) answer.push_back(mp1[g][1].second);
    }
    
    return answer;
}
