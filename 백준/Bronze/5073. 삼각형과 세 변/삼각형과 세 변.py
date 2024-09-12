import sys

while True:
    edges = sorted(list(map(int, sys.stdin.readline().split())))
    
    if edges[0] == 0:
        break
    
    # 가장 먼저 삼각형을 만들 수 있느냐 없느냐 부터 판단하고 들어가자
    if edges[0] + edges[1] <= edges[2]: # 삼각형을 만들 수 없는 경우
        print("Invalid")
    
    else: # 삼각형을 만들 수 있는 경우
        if edges[0] == edges[1] and edges[1] == edges[2]:
            print("Equilateral")
    
        elif edges[0] != edges[1] and edges[1] != edges[2] and edges[0] != edges[2]:
            print("Scalene")
    
        else:
            print("Isosceles")