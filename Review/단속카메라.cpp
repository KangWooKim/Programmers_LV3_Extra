// https://school.programmers.co.kr/learn/courses/30/lessons/42884

#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), compare);
    int loc = routes[0][1];
    for(int i = 1 ; i < routes.size() ; i++){
        if(loc >= routes[i][0] && loc <= routes[i][1]){
            continue;
        }
        else{
            loc = routes[i][1];
            answer++;
        }
    }
    return answer;
}
