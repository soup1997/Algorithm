import sys
from collections import deque
sys.setrecursionlimit(10000)

n, m, v = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n+1)]

# 양방향 그래프
for _ in range(m):
    start, end = map(int, sys.stdin.readline().split())
    graph[start].append(end)
    graph[end].append(start)

# 정점 번호가 작은 것부터 방문
for i in range(1, n+1):
    graph[i].sort()

def dfs(x):
    visited[x] = True # 현재 기준 정점 방문 처리
    print(x, end=" ")
    
    for currV in graph[x]:
        if not visited[currV]: # 방문되지 않았다면
            dfs(currV) # currV와 연결된 다른 정점들 탐색

def bfs(x):
    q = deque([x])
    visited[x] = True
    print(x, end=" ")
    
    while q:
        currV = q.popleft()
        for i in graph[currV]: # currV와 연결된 다른 정점들 탐색
            if not visited[i]:
                visited[i] = True # 방문 처리
                print(i, end=" ")
                q.append(i)

# DFS
visited = [False for _ in range(n+1)]
dfs(v)
print()

# BFS
visited = [False for _ in range(n+1)]
bfs(v)