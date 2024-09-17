import sys

n = int(sys.stdin.readline())
data = [list(map(int, sys.stdin.readline().split()))for _ in range(n)]

for i in range(len(data)):
    ranking = 1
    for j in range(len(data)):
        if data[i][0] < data[j][0] and data[i][1] < data[j][1]:
            ranking += 1
    print(ranking, end=' ')