// https://school.programmers.co.kr/learn/courses/30/lessons/43236

#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());

    long long left = 1;
    long long right = distance;
    long long answer = 0;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long prev = 0;
        int remove_rocks = 0;
        
        for (int i = 0; i < rocks.size(); ++i) {
            if (rocks[i] - prev < mid) {  // 현재 바위와 이전 바위 사이의 거리가 mid보다 작으면 바위를 제거
                ++remove_rocks;
            } else {  // 그렇지 않으면 현재 바위를 이전 바위로 설정
                prev = rocks[i];
            }
        }
        
        if (distance - prev < mid) {  // 마지막 바위와 도착점 사이의 거리가 mid보다 작으면 바위를 제거
            ++remove_rocks;
        }
        
        if (remove_rocks <= n) {  // 제거한 바위의 개수가 n 이하이면 mid 값을 최솟값으로 가능
            answer = max(answer, mid);
            left = mid + 1;
        } else {  // 그렇지 않으면 mid 값을 줄여서 다시 시도
            right = mid - 1;
        }
    }
    
    return answer;
}
