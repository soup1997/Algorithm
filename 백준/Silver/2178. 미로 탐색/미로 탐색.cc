#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

char board[100][100];
bool visit[100][100];
int dist[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char** argv){
    int N, M;
    queue<pair<int, int>> Q;
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < M; j++){
            board[i][j] = str[j];
        }
    }
    
    dist[0][0] = 0; // origin point
    visit[0][0] = 1;
    Q.push(make_pair(0, 0));
    
    while(!Q.empty()){
        pair<int, int> curr = Q.front();
        Q.pop();
        
        for(int dir = 0; dir < 4; dir++){
            int nx = curr.first + dx[dir];
            int ny = curr.second + dy[dir];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visit[nx][ny] || board[nx][ny] == '0') continue;
            visit[nx][ny] = 1;
            dist[nx][ny] = dist[curr.first][curr.second] + 1;        
            Q.push(make_pair(nx, ny));
        }
    }
    cout << dist[N-1][M-1] + 1;
    return 0;
}