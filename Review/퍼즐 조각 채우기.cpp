// https://school.programmers.co.kr/learn/courses/30/lessons/84021

#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void standard(vector<vector<pair<int, int>>>& v){
    for(auto & v1 : v){
        int minx = 99; int miny = 99;
        for(auto& p : v1){
            minx = min(minx, p.second);
            miny = min(miny, p.first);
        }
        for(auto& p : v1){
            p.first -= miny;
            p.second -= minx;
        }
        sort(v1.begin(), v1.end());
    }
}

void Rotation(vector<vector<pair<int, int>>>& puzzles)
{
    for(auto& v : puzzles){
        int m = -1;
        for(auto& p : v){
            m = max(m, max(p.first, p.second));
        }
        for(auto& p : v){
            p = make_pair(m - p.second, p.first);
        }
    }

    standard(puzzles);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    for(int i = 0 ; i < game_board.size() ; i++){
        for(int j = 0 ; j < game_board[i].size() ; j++){
            if(game_board[i][j] == 1) game_board[i][j] = 0;
            else game_board[i][j] = 1;
        }
    }
    
    vector<vector<pair<int, int>>> puzzles;
    int visit[table.size()][table.size()];
    for(int i = 0 ; i < table.size() ; i++){
        for(int j = 0 ; j < table.size() ; j++)
            visit[i][j] = false;
    }
    
    for(int y = 0 ; y < table.size() ; y++){
        for(int x = 0 ; x < table[y].size() ; x++){
            if(table[y][x] == 1 && !visit[y][x]){
                queue<pair<int, int>> q; q.push({y, x});
                vector<pair<int, int>> puzzle; puzzle.push_back({y, x}); visit[y][x] = true;
                while(!q.empty()){
                    int nwx = q.front().second; int nwy = q.front().first;
                    q.pop();
                    for(int i = 0 ; i < dx.size() ; i++){
                        int nx = nwx + dx[i]; int ny = nwy + dy[i];
                        if(nx < 0 || ny < 0 || nx >= table.size() || ny >= table.size()) continue;
                        if(!visit[ny][nx] && table[ny][nx] == 1){
                            visit[ny][nx] = true; q.push({ny, nx}); puzzle.push_back({ny, nx});
                        }
                    }
                }
                puzzles.push_back(puzzle);
            }
        }
    }
    
    standard(puzzles);
    
    vector<vector<pair<int, int>>> blanks;
    for(int i = 0 ; i < table.size() ; i++){
        for(int j = 0 ; j < table.size() ; j++)
            visit[i][j] = false;
    }
    
    for(int y = 0 ; y < game_board.size() ; y++){
        for(int x = 0 ; x < game_board[y].size() ; x++){
            if(game_board[y][x] == 1 && !visit[y][x]){
                queue<pair<int, int>> q; q.push({y, x});
                vector<pair<int, int>> blank; blank.push_back({y, x}); visit[y][x] = true;
                while(!q.empty()){
                    int nwx = q.front().second; int nwy = q.front().first;
                    q.pop();
                    for(int i = 0 ; i < dx.size() ; i++){
                        int nx = nwx + dx[i]; int ny = nwy + dy[i];
                        if(nx < 0 || ny < 0 || nx >= game_board.size() || ny >= game_board.size()) continue;
                        if(!visit[ny][nx] && game_board[ny][nx] == 1){
                            visit[ny][nx] = true; q.push({ny, nx}); blank.push_back({ny, nx});
                        }
                    }
                }
                blanks.push_back(blank);
            }
        }
    }
    
    standard(blanks);
    
    for(int i = 0 ; i < 4 ; i++){
        for(int a = 0 ; a < blanks.size() ; a++){
            for(int b = 0 ; b < puzzles.size() ; b++){
                if(blanks[a].size() == puzzles[b].size()){
                    int cnt = 0;
                    for(int c = 0 ; c < puzzles[b].size() ; c++){
                        if(blanks[a][c] == puzzles[b][c]) cnt++;
                        else break;
                    }
                    if(cnt == puzzles[b].size()){
                        answer += puzzles[b].size();
                        puzzles.erase(puzzles.begin() + b);
                        blanks.erase(blanks.begin() + a);
                        a--;
                        break;
                    }
                }
            }
        }
        Rotation(puzzles);
    }
    
    return answer;
}
