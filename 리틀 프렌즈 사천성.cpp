// https://school.programmers.co.kr/learn/courses/30/lessons/1836

#include <bits/stdc++.h>

using namespace std;

bool clean(vector<string>& board, pair<int, int>& p1, pair<int, int>& p2){
    if(p1.first == p2.first){
        for(int i  = min(p1.second + 1, p2.second + 1) ; i < max(p1.second, p2.second) ; i++){
            if(board[p1.first][i] != '.') return false;
        }
    }
    else if(p1.second == p2.second){
        for(int i = min(p1.first, p2.first) + 1 ; i < max(p1.first, p2.first) ; i++){
            if(board[i][p1.second] != '.') return false;
        }
    }
    return true;
}

bool can_erase(vector<string>& board, map<char, vector<pair<int, int>>>& mp, char c){
    auto p1 = mp[c][0]; auto p2 = mp[c][1];
    if(p1.first == p2.first){
        return clean(board, p1, p2);
    }
    else if(p1.second == p2.second){
        return clean(board, p1, p2);
    }
    else{
        auto p3 = make_pair(p1.first, p2.second); auto p4 = make_pair(p2.first, p1.second);
        if(board[p3.first][p3.second] != '.' && board[p4.first][p4.second] != '.') return false;
        bool a = clean(board, p1, p3) && clean(board, p2, p3);
        bool b = clean(board, p1, p4) && clean(board, p2, p4);
        return ((a && board[p3.first][p3.second] == '.') || (b && board[p4.first][p4.second] == '.'));
    }
    
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    map<char, vector<pair<int, int>>> mp;
    vector<char> list;
    
    for(int i = 0 ; i < board.size() ; i++){
        for(int j = 0 ; j < board[i].length() ; j++){
            if(board[i][j] == '.' || board[i][j] == '*') continue;
            mp[board[i][j]].push_back(make_pair(i, j));
            if(find(list.begin(), list.end(), board[i][j]) == list.end()) list.push_back(board[i][j]);
        }
    }
    sort(list.begin(), list.end());
    
    int cnt = 0;
    while(cnt != list.size()){
        bool erase = false;
        for(int i = 0 ; i < list.size() ; i++){
            if(mp[list[i]].size() == 0) continue;
            if(can_erase(board, mp, list[i])){
                auto p1 = mp[list[i]][0]; auto p2 = mp[list[i]][1];
                board[p1.first][p1.second] = '.'; board[p2.first][p2.second] = '.';
                mp[list[i]].clear();
                answer.push_back(list[i]);
                erase = true; break;
            }
        }
        if(erase){++cnt; continue;}
        if(!erase){answer = "IMPOSSIBLE"; break;}
    }
    
    return answer;
}
