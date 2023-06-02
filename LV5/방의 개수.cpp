// https://school.programmers.co.kr/learn/courses/30/lessons/49190

#include <vector>
#include <set>
using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solution(vector<int> arrows) {
    int answer = 0;
    set<pair<int, int>> nodes; 
    set<pair<pair<int, int>, pair<int, int>>> edges;
    int x = 0;
    int y = 0;
    
    for (int i = 0; i < arrows.size(); i++) {
        for (int j = 0; j < 2; j++) { 
            int nx = x + dx[arrows[i]];
            int ny = y + dy[arrows[i]];
            
            if (nodes.count({nx, ny}) && !edges.count({{x, y}, {nx, ny}})) {
                answer++;
            }
            
            nodes.insert({x, y});
            nodes.insert({nx, ny});
            
            edges.insert({{x, y}, {nx, ny}});
            edges.insert({{nx, ny}, {x, y}});
            
            x = nx;
            y = ny;
        }
    }
    
    return answer;
}
