// https://programmers.co.kr/learn/courses/30/lessons/43105

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> route(500);

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    route[0].push_back(triangle[0][0]);
    
    for(int i=1;i<triangle.size();i++){
        
            
        for(int j=0;j<triangle[i].size();j++){
            if(j==0){
                route[i].push_back(route[i-1][0]+triangle[i][j]);
                continue;
            }
            if(j==triangle[i].size()-1){
                route[i].push_back(route[i-1][j-1]+triangle[i][j]);
                break;
            }
            
            route[i].push_back(max(route[i-1][j-1]+triangle[i][j], route[i-1][j]+triangle[i][j]));
                
            
        }
    }
    
    answer = *max_element(route[triangle.size()-1].begin(), route[triangle.size()-1].end());
    return answer;
}
