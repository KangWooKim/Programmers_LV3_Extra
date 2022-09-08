// https://school.programmers.co.kr/learn/courses/30/lessons/1843

#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> arr)
{
    int len = (arr.size() + 1) / 2;
    int max_dp[len][len];
    int min_dp[len][len];
    
    for(int i = 0 ; i < len ; i++)
        for(int j = 0 ; j < len ; j++){
            if(i == j) {
                max_dp[i][j] = stoi(arr[2 * i]);
                min_dp[i][j] = stoi(arr[2 * i]);
                continue;
            }
            max_dp[i][j] = -2e9;
            min_dp[i][j] = 2e9;
            
        }
    
    for(int i = 1 ; i < len ; i++){
        for(int l = 0 ; l < len ; l++){
            int r = i + l;
            for(int k = l ; k <= r && k < len - 1 && r < len; k++){
                if(arr[2 * k + 1] == "+"){
                    max_dp[l][r] = max(max_dp[l][r], max_dp[l][k] + max_dp[k + 1][r]);
                    min_dp[l][r] = min(min_dp[l][r], min_dp[l][k] + min_dp[k + 1][r]);
                }
                else{
                    max_dp[l][r] = max(max_dp[l][r], max_dp[l][k] - min_dp[k + 1][r]);
                    min_dp[l][r] = min(min_dp[l][r], min_dp[l][k] - max_dp[k + 1][r]);
                }
            }
        }
    }
    return max_dp[0][len - 1];
}
