// https://school.programmers.co.kr/learn/courses/30/lessons/138475

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<int> table(e + 1, 1);
    for(int i = 2 ; i <= e ; i++){
        int res = 1;
        while(i * res <= e){
            table[i * res]++;
            res++;
        }
    }
    vector<int> table1(e + 1, 0); table1[e] = e;
    for(int i = e - 1 ; i > -1 ; i--){
        if(table[table1[i + 1]] <= table[i]) table1[i] = i;
        else table1[i] = table1[i + 1];
    }
    for(auto& s : starts){
        answer.push_back(table1[s]);
    }
    return answer;
}
