import sys

p, m = map(int, sys.stdin.readline().split())
rooms = []

for i in range(p):
    level, name = sys.stdin.readline().split()
    level = int(level)

    if i == 0:
        rooms.append([]) # 방 생성
        rooms[-1].append([level, name]) # 유저 추가
        
    else:
        flag = False
        
        for j in range(len(rooms)):
            if (level >= (rooms[j][0][0]-10) and level <= (rooms[j][0][0]+10)) and len(rooms[j]) < m:
                    rooms[j].append([level, name])
                    flag = True
                    break
            
        if not flag: # 유저가 방에 추가되지 못함
            rooms.append([]) # 방 생성
            rooms[-1].append([level, name]) # 유저 추가

for r in range(len(rooms)):
    rooms[r].sort(key=lambda x : x[1])
    print("Started!" if len(rooms[r]) == m else "Waiting!")

    for level, name in rooms[r]:
        print(level, name)