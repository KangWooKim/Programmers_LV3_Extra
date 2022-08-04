// https://school.programmers.co.kr/learn/courses/30/lessons/42579#

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

bool cmp1(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> mp;
    map<string, vector<pair<int, int>>> list;
    for(int i = 0 ; i < genres.size() ; i++){
        mp[genres[i]] += plays[i];
        list[genres[i]].push_back({i, plays[i]});
    }
    vector<pair<string, int>> v1(mp.begin(), mp.end());
    sort(v1.begin(), v1.end(), cmp);
    for(int i = 0 ; i < v1.size() ; i++){
        vector<pair<int, int>> v2 = list[v1[i].first];
        sort(v2.begin(), v2.end(), cmp1);
        int idx = 0;
        for(int k = 0 ; k < v2.size() ; k++){
            answer.push_back(v2[k].first);
            idx++;
            if(idx == 2) break;
        }
    }
    
    return answer;
}
