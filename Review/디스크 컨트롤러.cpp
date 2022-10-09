// https://school.programmers.co.kr/learn/courses/30/lessons/42627

#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    if(a[0] == b[0]) return a[1] < b[1];
    else return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0; int work = jobs.size(); int time = 0;
    sort(jobs.begin(), jobs.end(), compare);
    while(jobs.size() != 0){
        int len = 1001; int n = 0; int idx = 0;
        if(jobs[0][0] > time){time++; continue;}
        while(true){
            if(idx > jobs.size() - 1 || jobs[idx][0] > time){
                break;
            }
            if(len > jobs[idx][1]){
                len = jobs[idx][1];
                n = idx;
            }
            idx++;
        }
        time = time + jobs[n][1];
        answer = answer + time - jobs[n][0];
        jobs.erase(jobs.begin() + n);
    }

    return answer / work;
}
