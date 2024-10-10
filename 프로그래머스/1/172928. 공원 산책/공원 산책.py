H = None
W = None
grid = []

def inRange(cx, cy):
    return 0 <= cx < H and 0 <= cy < W

def isnotWall(cx, cy, nx, ny):
    if cx == nx:  # 같은 행에서 이동
        for j in range(min(cy, ny), max(cy, ny) + 1):
            if grid[cx][j] == 'X':
                return False
    elif cy == ny:  # 같은 열에서 이동
        for i in range(min(cx, nx), max(cx, nx) + 1):
            if grid[i][cy] == 'X':
                return False
    return True

def canGo(cx, cy, nx, ny):
    return inRange(nx, ny) and isnotWall(cx, cy, nx, ny)

def solution(park, routes):
    global H, W, grid
    
    H = len(park)
    W = len(park[0])
    grid = [list(row) for row in park]  # park를 2D 리스트로 변환
    
    # 시작점 찾기
    for i in range(H):
        if 'S' in park[i]:
            sx, sy = i, park[i].index('S')
            break
    
    # 현재 로봇 강아지의 위치 (cx, cy)
    cx, cy = sx, sy
    
    # 명령에 따라 이동 시작
    for r in routes:
        direction, step = r.split(' ')
        step = int(step)
        
        if direction == "E" and canGo(cx, cy, cx, cy + step):
            cy += step
        elif direction == "S" and canGo(cx, cy, cx + step, cy):
            cx += step
        elif direction == "W" and canGo(cx, cy, cx, cy - step):
            cy -= step
        elif direction == "N" and canGo(cx, cy, cx - step, cy):
            cx -= step
        
    return [cx, cy]
