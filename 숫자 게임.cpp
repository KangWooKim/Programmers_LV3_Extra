// https://school.programmers.co.kr/learn/courses/30/lessons/12987

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end()); sort(B.begin(), B.end());
    int index = 0;
    for(int i = 0 ; i < A.size() ; i++){
        for(int j = index ; j < B.size() ; j++){
            if(A[i] < B[j]){
                answer++;
                index = j + 1;
                break;
            }
        }
    }
    return answer;
}
