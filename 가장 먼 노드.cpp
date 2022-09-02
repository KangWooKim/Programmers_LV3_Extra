// https://school.programmers.co.kr/learn/courses/30/lessons/49189

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[20001];
vector<int> d(20001, 654321);

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now] < dist) continue;
        for(int i = 0 ; i < graph[now].size() ; i++){
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(auto v : edge){
        graph[v[0]].push_back({v[1], 1});
        graph[v[1]].push_back({v[0], 1});
    }
    
    
    dijkstra(1);
    int maxx = *max_element(d.begin() + 1, d.begin() + n);
    for(int i = 2 ; i < d.size() ; i++){
        if(d[i] == maxx) answer++;
    }
    
    return answer;
}
