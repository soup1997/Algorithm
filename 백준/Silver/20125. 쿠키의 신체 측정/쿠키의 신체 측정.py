import sys

n = int(sys.stdin.readline())
cookie = [list(sys.stdin.readline().strip()) for _ in range(n)] # 문자열이라서 통째로 입력받음, split 불가

def find_heart():
    heart_pos = [1, 1]
    for i in range(n):
        for j in range(n):
            if cookie[i][j].count("*") == 1: # cookie[i]가 하나의 문자열이므로 [j]까지 접근해야함
                heart_pos[0] = i + 1 + 1 # 머리는 심장 바로 윗 칸에 1칸 크기로 있다.
                heart_pos[1] = cookie[i].index("*") + 1 # 심장의 열 위치 찾음
                print(*heart_pos)       
                heart_pos[0] -= 1
                heart_pos[1] -= 1
            
                return heart_pos

h_pos = find_heart()
left_arm = cookie[h_pos[0]][:h_pos[1]].count("*")
right_arm = cookie[h_pos[0]][h_pos[1]+1:].count("*")
waist, left_leg, right_leg = 0, 0, 0

for i in range(h_pos[0]+1, n):
    if cookie[i][h_pos[1]] == "*":
        waist += 1
    
    else:
        if cookie[i][h_pos[1]-1] == "*":
            left_leg += 1
    
        if cookie[i][h_pos[1]+1] == "*":
            right_leg += 1

print(left_arm, right_arm, waist, left_leg, right_leg)