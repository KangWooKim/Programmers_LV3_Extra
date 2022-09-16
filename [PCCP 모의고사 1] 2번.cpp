// https://school.programmers.co.kr/learn/courses/15008/lessons/121684

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> ability) {
    int answer = 0;
    vector<int> list;
    for(int i = 0 ; i < ability.size() ; i++)
        list.push_back(i);
    
    do{
        vector<int> v(list.begin(), list.begin() + ability[0].size());
        int res = 0;
        for(int i = 0 ; i < v.size() ; i++){
            res += ability[v[i]][i];
        }
        answer = max(answer, res);
    }while(next_permutation(list.begin(), list.end()));
    
    return answer;
}
