// https://school.programmers.co.kr/learn/courses/30/lessons/60059

#include <bits/stdc++.h>

using namespace std;

int p;

void rotation(vector<vector<int>>& v){
    vector<vector<int>> v1 = v;
    v.clear();
    for(int i = 0 ; i < v1.size() ; i++){
        vector<int> vv;
        for(int j = v1.size() - 1 ; j > -1 ; j--){
            vv.push_back(v1[j][i]);
        }
        v.push_back(vv);
    }
}

bool check_answer(vector<vector<int>>& v1, vector<vector<int>> v2, int& i, int& j){
    if(v1.size() + i > v2.size() || v1.size() + j > v2.size()) return false;
    for(int a = 0 ; a < v1.size() ; a++){
        for(int b = 0 ; b < v1.size() ; b++){
            v2[a + i][b + j] = v2[a + i][b + j] ^ v1[a][b];
        }
    }
    int tot = 0;
    for(int a = p ; a < 2 * p ; a++){
        for(int b = p ; b < 2 * p ; b++){
            tot += v2[a][b];
        }
    }
    if(tot == p * p) return true;
    else return false;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    p = lock.size();
    vector<vector<int>> lockk(3 * p, vector<int>(3 * p, 0));
    for(int i = 0 ; i < lock.size() ; i++){
        for(int j = 0 ; j < lock.size() ; j++){
            lockk[p + i][p + j] = lock[i][j];
        }
    }
    for(int r = 0 ; r < 4 ; r++){
        for(int i = 0 ; i < lockk.size() ; i++){
            for(int j = 0 ; j < lockk.size() ; j++){
                if(check_answer(key, lockk, i , j)) return true;
            }
        }
        
        
        rotation(key);
    }
    return false;
}
