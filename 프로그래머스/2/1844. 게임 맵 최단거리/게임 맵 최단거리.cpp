#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

// 최단거리를 구하는 문제니까 BFS로 풀자
using namespace std;

int n, m;
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 인접 4방향
queue<vector<int>> q;

bool isVisited(int x, int y, vector<vector<bool>> &visited){
    return visited[x][y];
}

bool inRange(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool canGo(int x, int y, vector<vector<int>> &maps, vector<vector<bool>> &visited) {
    return inRange(x, y) && !visited[x][y] && maps[x][y] == 1;
}

int bfs(vector<int> root, vector<vector<int>> &maps, vector<vector<bool>> &visited){
    q.push(root);
    visited[root[0]][root[1]] = true;
    
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int dist = q.front()[2];
        q.pop();
        
        if(x == n-1 && y == m-1) return dist;
        
        for(int i=0; i < 4; i++){
            int dx = dirs[i][0], dy = dirs[i][1];
            if(canGo(x+dx, y+dy, maps, visited)){
                q.push({x+dx, y+dy, dist+1});
                visited[x+dx][y+dy] = true;
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    return bfs({0, 0, 1}, maps, visited);
}