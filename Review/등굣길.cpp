#include <string>
#include <vector>
#include <bits/stdc++.h>



using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> map(n,vector<int>(m,1));
    for(int i=0;i<puddles.size();i++){
        map[puddles[i][1]-1][puddles[i][0]-1]=0;
        
        if(puddles[i][1]==1){
            for(int j=puddles[i][0];j<m;j++){
                map[0][j]=0;
            }
        }
        if(puddles[i][0]==1){
            for(int k=puddles[i][1];k<n;k++){
                map[k][0]=0;
            }
        }
    }
    
    for(int p=1;p<n;p++){
        for(int q=1;q<m;q++){
            if(map[p][q]==0)
                continue;
            map[p][q]=(map[p-1][q]+map[p][q-1])%1000000007;
        }
    }
    answer = map[n-1][m-1]%1000000007;
    return answer;
}
