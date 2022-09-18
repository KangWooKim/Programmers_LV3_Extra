// https://school.programmers.co.kr/learn/courses/30/lessons/17678

#include <bits/stdc++.h>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> v;
    for(auto& time : timetable){
        string hour = time.substr(0, 2);
        string minute = time.substr(3, 2);
        int a = stoi(hour) * 60 + stoi(minute);
        v.push_back(a);
    }
    stable_sort(v.rbegin(), v.rend());
    
    int start = 540; int next = t; int now = start;
    int last = start + (n - 1) * t;
    while(now < last){
        int cnt = 0;
        while(!v.empty() && v.back() <= now && cnt < m){
            v.pop_back();
            ++cnt;
        }
        now += next;
    }
    string h = to_string(last / 60);
    if(h.length() == 1) h = "0" + h;
    string mi = to_string(last % 60);
    if(mi.length() == 1) mi = "0" + mi;
    if(v.size() == 0 || (!v.empty() && v.back() > last)) return h + ":" + mi;
    int cnt = 0; int con;
    while(cnt < m){
        if(v.empty()) break;
        if(!v.empty() && v.back() <= last){
            con = v.back() - 1;
            v.pop_back();
            ++cnt;
        }
    }

    if(cnt < m && v.empty()) return h + ":" + mi;

    h = to_string(con / 60);
    if(h.length() == 1) h = "0" + h;
    mi = to_string(con % 60);
    if(mi.length() == 1) mi = "0" + mi;
    answer = h + ":" + mi;
    return answer;
}
