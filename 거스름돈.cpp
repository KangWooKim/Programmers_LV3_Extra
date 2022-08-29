// https://school.programmers.co.kr/learn/courses/30/lessons/12907

#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    long long val[100001];
    val[0] = 1;
    for(int i = 1 ; i < 100001 ; i++) val[i] = 0;
    
    for(int i = 0 ; i < money.size() ; i++){
        if(n < money[i]) continue;
        for(int j = 1 ; j < n + 1 ; j++){
            if(j >= money[i]) val[j] = (val[j] + val[j - money[i]]) % 1000000007;
        }
    }
    
    answer = val[n];
    return answer;
}
