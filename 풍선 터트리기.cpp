// https://school.programmers.co.kr/learn/courses/30/lessons/68646

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> l = a; vector<int> r = a;
    for(int i = 1 ; i < a.size() - 1 ; i++){
        if(l[i] > l[i - 1]) l[i] = l[i - 1];
        if(r[a.size() - i - 1] > r[a.size() - i]) r[a.size() - i - 1] = r[a.size() - i];
    }
    
    for(int i = 1 ; i < a.size() - 1 ; i++){
        if(a[i] > l[i - 1] && a[i] > r[i + 1]) continue;
        answer++;
    }
    return answer + 2;
}
