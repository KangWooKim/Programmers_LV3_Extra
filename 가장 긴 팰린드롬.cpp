// https://school.programmers.co.kr/learn/courses/30/lessons/12904#

#include <bits/stdc++.h>
using namespace std;

int solution(std::vector<int> a) {
    int answer = -1;
    if(a.size() < 2) return 0;
    vector<int> count(a.size(), 0);
    for(auto i : a)
        count[i]++;
    
    for(int i = 0 ; i < count.size() ; i++){
        if(count[i] == 0) continue;
        if(count[i] <= answer) continue;
        int cnt = 0;
        for(int j = 0 ; j < a.size() - 1 ; j++){
            if(a[j] != i && a[j + 1] != i) continue;
            if(a[j] == a[j + 1]) continue;
            cnt++; j++;
        }
        answer = max(cnt, answer);
    }
    
    
    return answer * 2;
}
