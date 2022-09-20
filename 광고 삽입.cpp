// https://school.programmers.co.kr/learn/courses/30/lessons/72414

#include <bits/stdc++.h>

using namespace std;

long long convert_time(string& play_time){
    long long time = stoll(play_time.substr(0, 2)) * 3600 + stoll(play_time.substr(3, 2)) * 60 + stoll(play_time.substr(6, 2));
    return time;
}

string convert_string(long long& time){
    int h, m, sec;
    h = time / 3600; time %= 3600;
    m = time / 60; time %= 60;
    sec = time;
    string s = "";
    if(h < 10) s.push_back('0');
    s += to_string(h); s.push_back(':');
    if(m < 10) s.push_back('0');
    s += to_string(m);s.push_back(':');
    if(sec < 10) s.push_back('0');
    s += to_string(sec);
    return s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    long long max_time = convert_time(play_time);
    long long adv_timee = convert_time(adv_time);
    
    vector<long long> watch(max_time + 1, 0);
    for(auto& l : logs){
        string start = l.substr(0, 8);
        string end = l.substr(9, 8);
        watch[convert_time(start)]++;
        watch[convert_time(end)]--;
    }
    
    for(int i = 1 ; i < watch.size() ; i++)
        watch[i] += watch[i - 1];
    
    for(int i = 1 ; i < watch.size() ; i++)
        watch[i] += watch[i - 1];
    
    long long tot = 0;
    long long start = 0;
    for(int i = 0 ; i <= max_time - adv_timee ; i++){
        long long s = i; long long e = i + adv_timee;
        long long sum = watch[e - 1];
        if(s > 0) sum -= watch[s - 1];
        if(tot < sum){
            start = s;
            tot = sum;
        }
    }
    answer = convert_string(start);
    return answer;
}
