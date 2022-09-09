// https://school.programmers.co.kr/learn/courses/30/lessons/12971

#include <bits/stdc++.h>
using namespace std;



int solution(vector<int> sticker)
{
    int answer =0;
    if(sticker.size() == 1) return sticker[0];

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    vector<int> sticker1(sticker.size(), 0);
    vector<int> sticker2(sticker.size(), 0);
    
    sticker1[0] = sticker[0];
    sticker1[1] = sticker[0];
    sticker2[0] = 0;
    sticker2[1] = sticker[1];
    
    for(int i = 2 ; i < sticker.size() - 1 ; i++)
        sticker1[i] = max(sticker1[i - 2] + sticker[i], sticker1[i - 1]);
    
    for(int i = 2 ; i < sticker.size() ; i++)
        sticker2[i] = max(sticker2[i - 2] + sticker[i], sticker2[i - 1]);
    
    return max(sticker1[sticker.size() - 2], sticker2[sticker.size() - 1]);
}
