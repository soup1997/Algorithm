#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 
// 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.

using namespace std;

int n, m;
int grid[1000][1000] = {0, };
bool visited[1000][1000] = {false, };

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상하좌우
queue<pair<int, int>> q;

bool inRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool canGo(int x, int y) {
    return inRange(x, y) && grid[x][y] == 0; // 아직 익지 않은 토마토
}

pair<int, int> bfs() {  
    int day = 0;
    int ripeTomato = 0;    // 익은 토마토의 수
    
    while (!q.empty()) {
        int size = q.size(); // 현재 레벨의 크기

        for (int s = 0; s < size; s++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop(); // 큐에서 제거
            ripeTomato++; // 익은 토마토 수 증가

            for (int i = 0; i < 4; i++) {
                int dx = dirs[i][0], dy = dirs[i][1];         
                if (canGo(x + dx, y + dy)) {
                    grid[x + dx][y + dy] = 1; // 토마토를 익었다고 표시
                    q.push({x + dx, y + dy}); // 익은 토마토를 큐에 추가
                }
            }
        }

        if (!q.empty()) day++; // 큐에 아직 토마토가 남아 있으면 하루가 지나야 함
    }

    return {ripeTomato, day};
}

int main() {
    int totalTomato = 0;
    pair<int, int> ans;
    cin >> m >> n;
    
    // grid 생성
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 0 || grid[i][j] == 1) {
                if(grid[i][j] == 1){
                    q.push({i, j}); // 1인지점 모두 큐에 넣기
                }
                totalTomato++; // 총 토마토의 갯수 세기
            }
        }
    }
    
    ans = bfs();

    // 모든 토마토가 익었는지 확인
    if (ans.first == totalTomato) {
        cout << ans.second << "\n"; // 모든 토마토가 익었다면 걸린 일수 출력
    } else {
        cout << -1 << "\n"; // 익지 못하는 경우
    }
    return 0;
}
