#include <iostream>
#include <queue>
#include <utility> // pair
#include <algorithm> // max

using namespace std;

int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char** argv) {
    int n, m;
    int max_size = 0, num = 0;
    cin >> n >> m;
    queue<pair<int, int>> Q;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 1 && vis[i][j] == 0){
                int size = 0;
                queue<pair<int, int>> Q;
                
                vis[i][j] = 1; // 시작점 방문 표시
                Q.push(make_pair(i, j)); // 시작점 큐에 삽입, bfs 시작
                       
                while(!Q.empty()){
                    pair<int, int> curr = Q.front();
                    Q.pop();
                    size++;
                    
                    for(int dir = 0; dir < 4; dir++){
                        int nx = curr.first + dx[dir];
                        int ny = curr.second + dy[dir];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push(make_pair(nx, ny));
                    }
                }
                max_size = max(max_size, size);
                num++;
            }
        }
    }
    cout << num << "\n" << max_size;
    return 0;
}