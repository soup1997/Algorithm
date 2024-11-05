#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool visited[100] = {false, };
vector<vector<int>> graph(100);

int dfs(int x){
    int cnt = 1;
    visited[x] = true;
    
    for(auto n : graph[x]){
        if(!visited[n]){
            cnt += dfs(n);
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for(int i = 0; i < wires.size(); i++){
        graph.assign(100, vector<int>());  // Clear the graph
        fill(visited, visited + n, false);  // Reset visited array
        
        for(int j = 0; j < wires.size(); j++){
            if(i != j){ // 하나씩 끊어서 그래프 생성하기
                int a = wires[j][0] - 1;
                int b = wires[j][1] - 1;
                graph[a].push_back(b); // 양방향 그래프
                graph[b].push_back(a); // 양방향 그래프 
            }
        }
        
        int cnt = dfs(wires[0][0]);
        int otherCnt = n - cnt;
        int diff = abs(cnt - otherCnt);
        
        answer = min(answer, diff);
    }
    
    return answer;
}