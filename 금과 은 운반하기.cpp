// https://school.programmers.co.kr/learn/courses/30/lessons/86053?language=cpp

#include <bits/stdc++.h>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    
    long long max_time = 1e5 * 2 * 1e9 * 2; long long min_time = 0; long long max_res = a + b;
    long long time_res = 0;
    long long answer = max_time;
    
    
    while(min_time + 1 < max_time){
        long long mid_time = (min_time + max_time) / 2;
        long long res = 0; long long gold = 0; long long silver = 0;
        for(int i = 0 ; i < w.size() ; i++){
            long long cnt = mid_time / (2 * t[i]);
            if(mid_time % (2 * t[i]) >= t[i]) cnt++;
            res += min((long long)g[i] + s[i], cnt * w[i]);
            gold += min((long long)g[i], cnt * w[i]);
            silver += min((long long)s[i], cnt * w[i]);
        }
        if(res < max_res || gold < a || silver < b){
            min_time = mid_time; continue;
        }
        else if(res >= max_res && gold >= a && silver >= b){
            max_time = mid_time; 
            answer = min(answer, mid_time); continue;
        }
    }
    
    return max_time;
}
