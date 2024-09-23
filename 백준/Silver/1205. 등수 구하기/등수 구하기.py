import sys

# N >= 0, 리스트에 있는 점수의 갯수
# 10 <= P <= 50, 랭킹에 올라갈 수 있는 점수의 갯수
n, taesu, p = map(int, sys.stdin.readline().split())

scores = list(map(int, sys.stdin.readline().split()))
scores = scores[:]

ranking = 1

if n == 0:
    print(ranking)

else:
    if n >= p and min(scores) >= taesu:
        print(-1)
    
    else:
        for score in scores:
            if score > taesu:
                ranking += 1
         
        print(ranking)