#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int grid[500][500] = {0, };
bool visited[500][500] = {false, };
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상하좌우
queue<pair<int, int>> q;


bool inRange(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool isVisited(int x, int y){
    return visited[x][y];
}

bool canGo(int x, int y){
    return inRange(x, y) && !isVisited(x, y) && grid[x][y] == 1;
}

int bfs(pair<int, int> pos){  
    int area = 1; // 시작점도 포함하므로 1로 시작
    
    q.push({pos.first, pos.second}); // 방문 안했으면 큐에 집어 넣는다
    visited[pos.first][pos.second] = true; // 방문처리
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop(); // 방문처리 했으므로 큐에서 제거
        
        for(int i=0; i < 4; i++){
            int dx = dirs[i][0], dy = dirs[i][1];
            
            if(canGo(x+dx, y+dy)){
                q.push({x+dx, y+dy});
                visited[x+dx][y+dy] = true;
                area++; // 그림의 넓이증가
            }
        }
    }
    return area;
}

int main(int argc, char** argv){
    int maxArea = 0;
    
    cin >> n >> m;
    
    // grid 생성
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    
    int paintingNum = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(canGo(i, j)){ // 그림인 경우에만 BFS 시작
                int area = bfs({i, j});
                maxArea = max(maxArea, area);
                paintingNum++;
            }
        }
    }
    cout << paintingNum << "\n" << maxArea;
    return 0;
}