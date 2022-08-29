// https://school.programmers.co.kr/learn/courses/30/lessons/1833

#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    if(v1[0] == v2[0]) return v1[1] < v2[1];
    else return v1[0] < v2[0];
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    stable_sort(data.begin(), data.end(), cmp);
    
    
    for(int i = 0 ; i < data.size() ; i++){
        int x = data[i][0]; int y = data[i][1];
        
        for(int j = i + 1 ; j < data.size() ; j++){
            if(data[j][0] == x) continue;
            if(data[j][1] == y) continue;
            bool a = true;
            int min_x = min(x, data[j][0]); int max_x = max(x, data[j][0]); int min_y = min(y, data[j][1]); int max_y = max(y, data[j][1]);
            for(int k = i + 1 ; k < j ; k++){
                if(data[k][0] > min_x && data[k][0] < max_x && data[k][1] > min_y && data[k][1] < max_y){a = false; break;}
            }
            if(a) answer++;
        }
    }
    
    return answer;
}
