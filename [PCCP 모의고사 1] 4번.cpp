// https://school.programmers.co.kr/learn/courses/15008/lessons/121686

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    return p1.first > p2.first;
}

vector<long long> solution(vector<vector<int>> program) {
    vector<long long> answer(11, 0);
    map<long long, vector<pair<long long, long long>>> mp;
    for(auto& i : program){
        mp[i[0]].push_back(make_pair(i[1], i[2]));
    }
    auto iter = mp.begin();
    while(iter != mp.end()){
        if(mp[iter->first].size() == 0){++iter; continue;}
        sort(mp[iter->first].begin(), mp[iter->first].end(), cmp);
        ++iter;
    }
    int cnt = 0; long long time = 0;
    while(cnt != program.size()){
        int priority = 1; bool f = false;
        for(int i = priority ; i <= 10 ; i++){
            if(mp[i].size() == 0) continue;
            if(mp[i].back().first <= time){priority = i; f = true; break;}
        }
        if(!f){
            long long m = 10000001;
            for(int i = 1 ; i < 11 ; i++){
                if(mp[i].size() == 0) continue;
                if(m > mp[i].back().first){priority = i; m = (long long)mp[i].back().first;}
            }
            time = (long long)mp[priority].back().first;
        }
        answer[priority] += (time - (long long)mp[priority].back().first);
        time += (long long)mp[priority].back().second;
        mp[priority].pop_back();
        ++cnt;
    }
    answer[0] = time;
    return answer;
}
