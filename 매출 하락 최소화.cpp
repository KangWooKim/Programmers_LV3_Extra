#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int solution(vector<int> sales, vector<vector<int>> links) {
    int n = sales.size();
    
    // 트리 구조 생성
    vector<vector<int>> tree(n);
    for (const auto& link : links) {
        int parent = link[0] - 1; // 0-indexed로 변환
        int child = link[1] - 1;  // 0-indexed로 변환
        tree[parent].push_back(child);
    }
    
    // DP 테이블: dp[node][state]
    // state = 0: 해당 노드가 워크샵에 참여하지 않는 경우
    // state = 1: 해당 노드가 워크샵에 참여하는 경우
    vector<vector<int>> dp(n, vector<int>(2, -1));
    
    // DP 함수
    function<int(int, int)> dfs = [&](int node, int state) {
        // 이미 계산된 값이 있으면 반환
        if (dp[node][state] != -1) return dp[node][state];
        
        // 현재 노드가 워크샵에 참여하는 경우
        if (state == 1) {
            int cost = sales[node]; // 참여 비용
            
            // 모든 부하 직원에 대해 최소 비용 계산
            for (int child : tree[node]) {
                cost += min(dfs(child, 0), dfs(child, 1));
            }
            
            return dp[node][state] = cost;
        }
        // 현재 노드가 워크샵에 참여하지 않는 경우
        else {
            int cost = 0;
            int minExtra = numeric_limits<int>::max();
            bool hasAttend = false;
            
            // 모든 부하 직원에 대해 처리
            for (int child : tree[node]) {
                int notAttendCost = dfs(child, 0); // 부하가 참여 안함
                int attendCost = dfs(child, 1);    // 부하가 참여함
                
                // 부하가 참여하는 것이 더 저렴하거나 같으면 참여시킴
                if (attendCost <= notAttendCost) {
                    cost += attendCost;
                    hasAttend = true;
                } else {
                    cost += notAttendCost;
                    // 나중에 필요하면 참여시킬 수 있도록 추가 비용 저장
                    minExtra = min(minExtra, attendCost - notAttendCost);
                }
            }
            
            // 부하 중 아무도 참여하지 않았다면, 가장 저렴한 부하를 참여시킴
            if (!hasAttend && !tree[node].empty()) {
                cost += minExtra;
            }
            
            return dp[node][state] = cost;
        }
    };
    
    // CEO(0번 인덱스)에서 시작하여 최소 비용 계산
    return min(dfs(0, 0), dfs(0, 1));
}