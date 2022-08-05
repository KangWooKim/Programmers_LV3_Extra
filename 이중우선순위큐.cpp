// https://school.programmers.co.kr/learn/courses/30/lessons/42628

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int, vector<int>, less<int>> max;
    unordered_map<int, int> mp;
    int val = 0;
    for(auto iter : operations){
        string op, number;
        stringstream in(iter);
        in >> op >> number;
        if(op =="I"){
            min.push(stoi(number));
            max.push(stoi(number));
            mp[stoi(number)]++;
            val++;
        }
        else if(val != 0 && op == "D"){
            if(number == "1"){
                mp[max.top()]--;
                max.pop();
                val--;
            }
            else if(number == "-1"){
                mp[min.top()]--;
                min.pop();
                val--;
            }
        }
    }
    if(val == 0) return {0, 0};
    else if(val == 1){
        answer.push_back(max.top()); answer.push_back(max.top());
    }
    else{
        while(mp[min.top()] == 0) min.pop();
        while(mp[max.top()] == 0) max.pop();
        answer.push_back(max.top()); answer.push_back(min.top());
    }
    return answer;
}
