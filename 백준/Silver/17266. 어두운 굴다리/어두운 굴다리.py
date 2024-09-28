import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
lights = list(map(int, sys.stdin.readline().split()))

# 실패 케이스를 생각해보자
# 1. lights[0] - h > 0 --> 실패
# 2. lights[-1] + h < n --> 실패
# 3. lights[i]+h < light[i+1]-h --> 실패

for h in range(1, n+1):
    flag = True
    # 맨 왼쪽 가로등
    if lights[0] - h > 0:
        flag = False
    
    elif lights[-1] + h < n:
        flag = False
    
    else:
        for i in range(m-1):
            if lights[i] + h < lights[i+1] - h:
                flag = False
                break
         
    if flag:
        print(h)
        break