// https://school.programmers.co.kr/learn/courses/30/lessons/42627

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    if(v1[0] == v2[0]) return v1[1] > v2[1];
    return v1[0] < v2[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0; int j = jobs.size();
    stable_sort(jobs.begin(), jobs.end(), cmp);
    int time = 0;
    while(!jobs.empty()){
        int idx = 0; int m = 1001;
        if(time < jobs[idx][0]) time = jobs[idx][0];
        for(int i = 0 ; i < jobs.size() ; i++){
            if(time < jobs[i][0]) break;
            if(time >= jobs[i][0] && m > jobs[i][1]){idx = i; m = jobs[i][1];}
        }
        time += jobs[idx][1];
        answer += (time - jobs[idx][0]);
        jobs.erase(jobs.begin() + idx);
    }
    return answer / j;
}
