// https://school.programmers.co.kr/learn/courses/30/lessons/67258

/* 
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_set<string> st;
    for(auto c : gems)
        st.insert(c);
    int l = st.size();
    for(int i = l ; i <= gems.size() ; i++){
        for(int k = 0 ; k <= gems.size() - i ; k++){
            unordered_set<string> s;
            for(int q = k ; q < k + i ; q++){
                s.insert(gems[q]);
            }
            if(s.size() == st.size()){
                return {k + 1, k + i};
            }
            s.clear();
        }
    }
    return answer;
}


 */
