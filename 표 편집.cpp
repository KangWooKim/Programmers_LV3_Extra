// https://school.programmers.co.kr/learn/courses/30/lessons/81303#
/*
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<int> delete_list;
    vector<int> v(n, 1);
    int now = k; int q = n - 1;
    for(auto& command : cmd){
        if(command[0] == 'U'){
            string s = command.substr(2, command.length() - 2);
            int x = stoi(s);
            while(x > 0){
                if(v[--now] == 1) x = x - 1;
            }
        }
        if(command[0] == 'D'){
            string s = command.substr(2, command.length() - 2);
            int x = stoi(s);
            while(x > 0){
                if(v[++now] == 1) x = x - 1;
            }
        }
        if(command[0] == 'C'){
            v[now] = 0;
            delete_list.push_back(now);
            bool a = false;
            if(now == q) {q--; a = true;}
            while(!a){
                now = now + 1;
                if(v[now] == 1) break;
            }
            while(a){
                --now;
                if(v[now] == 1) break;
            }
            
        }
        if(command[0] == 'Z'){
            v[delete_list.back()] = 1;
            if(q < delete_list.back()) q = delete_list.back();
            delete_list.pop_back();
        }
        
    }
    for(auto& i : v){
        if(i == 1) answer += "O";
        else answer += "X";
    }
    return answer;
}
*/

#include <bits/stdc++.h>

using namespace std;

struct vv{
    int me;
    int left;
    int right;
    
    vv(int a, int b, int c)
        : me(a), left(b), right(c){
            
        }
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    vector<vv> v;
    for(int i = 0 ; i < n ; i++){
        v.push_back(vv(i, i - 1, i + 1));
    }
    int now = k;
    vector<vv> delete_list;
    
    for(auto& c : cmd){
        if(c[0] == 'U'){
            int x = stoi(c.substr(2));
            for(int i = 0 ; i < x ; i++)
                now = v[now].left;
        }
        if(c[0] == 'D'){
            int x = stoi(c.substr(2));
            for(int i = 0 ; i < x ; i++)
                now = v[now].right;
        }
        if(c[0] == 'C'){
            delete_list.push_back(v[now]);
            answer[now] = 'X';
            int now_right = v[now].right;
            int now_left = v[now].left;
            
            if(now_right != n)
                v[now_right].left = now_left;
            
            if(now_left != -1)
                v[now_left].right = now_right;
            
            if(now_right == n) now = now_left;
            else now = now_right;
        }
        if(c[0] == 'Z'){
            auto vvv = delete_list.back();
            delete_list.pop_back();
            int r_left = vvv.left;
            int r_right = vvv.right;
            
            if(r_left != -1)
                v[r_left].right = vvv.me;
            if(r_right != n)
                v[r_right].left = vvv.me;
            
            answer[vvv.me] = 'O';
        }
    }
    
    return answer;
}
