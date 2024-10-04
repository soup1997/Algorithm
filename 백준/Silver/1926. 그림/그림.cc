#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int grid[500][500] = {0, };
bool visited[500][500] = {false, };
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상하좌우
int area = 1; // 그림의 넓이

bool inRange(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool isVisited(int x, int y){
    return visited[x][y];
}

bool canGo(int x, int y){
    return inRange(x, y) && !isVisited(x, y) && grid[x][y] == 1;
}

void dfs(pair<int, int> pos){
    visited[pos.first][pos.second] = true; // 방문처리
    
    int x = pos.first;
    int y = pos.second;
               
    for(int i=0; i < 4; i++){
        int dx = dirs[i][0], dy = dirs[i][1];
            
        if(canGo(x+dx, y+dy)){
            area++; // 그림의 넓이증가
            dfs({x+dx, y+dy});
        }
    }
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
                dfs({i, j});
                maxArea = max(maxArea, area);
                area = 1; // 전역변수 area 초기화
                paintingNum++;
            }
        }
    }
    cout << paintingNum << "\n" << maxArea;
    return 0;
}