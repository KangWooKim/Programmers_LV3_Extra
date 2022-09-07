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

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    unordered_set<string> st(gems.begin(), gems.end());
    unordered_map<string, int> ump;
    int l = 0; int r = 0;
    for(auto g : gems){
        ump[g]++;
        if(ump.size() == st.size()) break;
        ++r;
    }
    int min_len = r - l;
    answer[0] = l + 1; answer[1] = r + 1;
    while(r < gems.size()){
        string s = gems[l];
        ump[gems[l]]--; l++;
        if(ump[s] == 0){
            ++r;
            for(;r < gems.size() ; r++){
                ump[gems[r]]++;
                if(gems[r] == s) break; 
            }
            if(r == gems.size()) break;
        }
        if(min_len > r - l){
            answer[0] = l + 1;
            answer[1] = r + 1;
            min_len = r - l;
        }
    }
    return answer;
}
