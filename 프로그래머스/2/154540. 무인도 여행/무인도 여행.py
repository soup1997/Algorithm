import sys
sys.setrecursionlimit(10000)

n, m = 0, 0
directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
grid, visited = [] , []

def inRange(x, y):
    return x >= 0 and x < n and y >= 0 and y < m

def isX(x, y):
    return grid[x][y] == "X"

def isVisited(x, y):
    return visited[x][y]

def canGo(x, y):
    return (inRange(x, y)) and (not isX(x, y)) and (not isVisited(x, y))

def dfs(x, y):
    visited[x][y] = True
    area = int(grid[x][y])
    
    for direction in directions:
        dx, dy = direction[0], direction[1]
        nx, ny = x + dx, y + dy
        
        if canGo(nx, ny):
            area += dfs(nx, ny)
            
    return area

def solution(maps):
    global n, m, grid, visited
    
    answer = []
    grid = maps[:]
    n = len(maps)
    m = len(maps[0])
    
    visited = [[False] * m for _ in range(n)]  # visited 리스트 초기화
        
    for i in range(n):
        for j in range(m):
            if canGo(i, j):
                area = dfs(i, j)
                answer.append(area)
    
    if not answer:
        return [-1]
    
    else:
        return sorted(answer)