// https://school.programmers.co.kr/learn/courses/30/lessons/12984

#include<bits/stdc++.h>
using namespace std;

long long solution(vector<vector<int> > land, int P, int Q) {
    long long answer = 9223372036854775807;
    
    vector<long long> block; long long total = 0;
    for(auto& i : land){
        for(auto& j : i)
            {block.push_back(j);
            total += j;}
    }
    stable_sort(block.begin(), block.end()); 
    long long floor = -1; long long res = 0;
    for(int i = 0 ; i < block.size() ; i++){
        if(floor == block[i]) {res += block[i]; continue;}
        floor = block[i];
        long long plus = block[i] * i - res;
        long long minus = total - res - block[i] * (block.size() - i);
        long long cost = P * plus + Q * minus;
        answer = min(answer, cost);
        res += block[i];
    }
    
    return answer;
}
