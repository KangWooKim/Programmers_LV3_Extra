// https://school.programmers.co.kr/learn/courses/30/lessons/1838

#include <bits/stdc++.h>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int dis(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

bool check_dis(vector<pair<int, int>> vec, pair<int, int> p, int i){
    for(auto v : vec){
        if(dis(v, p) < i) return false;
    }
    return true;
}


int solution(int n, int m, vector<vector<int>> timetable) {
    int answer = 0;
    vector<int> dup(1321, 0);
    for(int i = 600 ; i < dup.size() ; i++){
        for(int j = 0 ; j < timetable.size() ; j++){
            if(i >= timetable[j][0] && i <= timetable[j][1]){
                dup[i]++;
            }
        }
    }
    int maxx = *max_element(dup.begin(), dup.end());
    if(maxx == 1) return 0; int d = 1; vector<vector<int>> vec(n, vector<int>(n, 0));
    
    for(int d = 2 * (n - 1) ; d > 0 ; d--){
        for(int y = 0 ; y < n ; y++){
            for(int x = 0 ; x < n ; x++){
                vector<pair<int, int>> list;
                list.push_back({x, y});
            
                for(int y1 = y ; y1 < n ; y1++){
                    for(int x1 = 0 ; x1 < n ; x1++){
                        if(y1 == y && x1 <= x) continue;
                        if(check_dis(list, {x1, y1}, d)){
                            list.push_back(make_pair(x1, y1));
                        }
                        if(list.size() == maxx) return d;
                    }
                }
            }
        }
    }
    
    return answer;
}
