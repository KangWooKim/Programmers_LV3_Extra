//https://school.programmers.co.kr/learn/courses/30/lessons/12920#

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    int start = -1; int end = 2e7; int mid = 0;
    while(start + 1 < end){
        mid = (start + end) / 2;
        int count = cores.size();
        for(auto c : cores){
            count += (mid / c);
        }
        if(count >= n) end = mid;
        else start = mid;
    }
    
    if(start == -1) return n;
    int count = cores.size();
    for(auto c : cores)
        count += (start / c);
    for(int i = 0 ; i < cores.size() ; i++){
        if((start + 1) % cores[i] == 0) count++;
        if(count == n) return i + 1;
    }
    
    return answer;
}
