// https://school.programmers.co.kr/learn/courses/30/lessons/340213?language=cpp

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

// "mm:ss" 형식을 초 단위 정수로 변환하는 함수
int toSeconds(const string &timeStr) {
    int minutes, seconds;
    sscanf(timeStr.c_str(), "%d:%d", &minutes, &seconds);
    return minutes * 60 + seconds;
}
 
// 초 단위 정수를 "mm:ss" 형식의 문자열로 변환하는 함수
string toTimeStr(int seconds) {
    int minutes = seconds / 60;
    int sec = seconds % 60;
    char buf[6];
    sprintf(buf, "%02d:%02d", minutes, sec);
    return string(buf);
}
 
// solution 함수: video_len, pos, op_start, op_end, commands를 받아 최종 위치를 반환
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int videoLen = toSeconds(video_len);
    int current = toSeconds(pos);
    int opStart = toSeconds(op_start);
    int opEnd = toSeconds(op_end);
    
    // 시작 위치가 오프닝 구간에 있다면 op_end로 건너뛰기
    if(current >= opStart && current <= opEnd) {
        current = opEnd;
    }
    
    // commands 처리
    for(auto &cmd : commands) {
        if(cmd == "prev") {
            // 10초 전으로 이동: 현재 위치가 10초 미만이면 0초로 이동
            if(current < 10)
                current = 0;
            else
                current -= 10;
        } else if(cmd == "next") {
            // 10초 후로 이동: 남은 시간이 10초 미만이면 마지막 위치로 이동
            if(videoLen - current < 10)
                current = videoLen;
            else
                current += 10;
        }
        
        // 이동 후 현재 위치가 오프닝 구간에 있다면 자동으로 op_end로 건너뛰기
        if(current >= opStart && current <= opEnd) {
            current = opEnd;
        }
    }
    
    return toTimeStr(current);
}
