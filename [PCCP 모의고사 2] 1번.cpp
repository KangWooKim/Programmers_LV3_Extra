// https://school.programmers.co.kr/learn/courses/15009/lessons/121687

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string command) {
    vector<int> answer;
    int x = 0; int y = 0; int r = 0;
    vector<char> rotation = {'U', 'R', 'D', 'L'};
    vector<int> gx = {0, 1, 0, -1};
    vector<int> gy = {1, 0, -1, 0};
    vector<int> bx = {0, -1, 0, 1};
    vector<int> by = {-1, 0, 1, 0};
    for(auto& co : command){
        if(co == 'R'){
            r += 1;
            if(r > 3) r = 0;
        }
        else if(co == 'L'){
            --r;
            if(r < 0) r = 3;
        }
        else if(co == 'G'){
            x += gx[r]; y += gy[r];
        }
        else if(co == 'B'){
            x += bx[r]; y += by[r];
        }
    }
    return {x, y};
}
