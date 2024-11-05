import sys
sys.setrecursionlimit(10000)

graph = None
visited = None

def dfs(node):
    global visited, graph
    
    cnt = 1
    visited[node] = True
    
    for i in graph[node]:
        if not visited[i]:
            cnt += dfs(i)

    return cnt

def solution(n, wires):
    global visited, graph
    
    answer = n
    
    for i in range(len(wires)):
        visited = [False] * n
        graph = [[] for _ in range(n)]
        
        for j in range(len(wires)):
            if i == j:
                continue
                
            start = wires[j][0] - 1
            end = wires[j][1] - 1
            graph[start].append(end)
            graph[end].append(start)
            
        cnt = dfs(wires[0][0]-1)
        other_cnt = n - cnt
        diff = abs(cnt - other_cnt)
        answer = min(answer, diff)
        
    return answer