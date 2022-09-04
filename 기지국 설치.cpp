// https://school.programmers.co.kr/learn/courses/30/lessons/12979

#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    vector<pair<int, int>> now_signal;
    for(int i = 0 ; i < stations.size() ; i++){
        int start = stations[i] - w; int end = stations[i] + w;
        if(start < 1) start = 1;
        if(end > n) end = n;
        if(!now_signal.empty()){
            int s = now_signal.back().first; int e = now_signal.back().second;
            if(start > s && start < e){
                now_signal.pop_back();
                now_signal.push_back(make_pair(s, end)); continue;
            }
        }
        now_signal.push_back(make_pair(start, end));
    }
    
    int range = 2 * w + 1;
    vector<int> len;
    len.push_back(now_signal[0].first - 1);
    for(int i = 0 ; i < now_signal.size() - 1 ; i++){
        len.push_back(now_signal[i + 1].first - now_signal[i].second - 1);
    }
    len.push_back(n - now_signal.back().second);
    
    for(auto i : len){
        if(i == 0) continue;
        answer += ((i + range - 1) / range);
    }

    return answer;
}
