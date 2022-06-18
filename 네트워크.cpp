// https://programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>
#include <bits/stdc++.h>
#define MAX 200

using namespace std;
bool visited[MAX];

void bfs(vector<vector<int>> &computers, int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<computers.size();i++){
            if(computers[x][i]==1 && !visited[i] && x!=i){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < computers.size(); i++){
        if(!visited[i]){
            bfs(computers, i);
            answer++;
        }
    }
    return answer;
}
