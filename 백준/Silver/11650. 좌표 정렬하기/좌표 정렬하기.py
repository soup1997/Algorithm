import sys

n = int(sys.stdin.readline())
coord = []
for _ in range(n):
    x, y = map(int, sys.stdin.readline().split())
    coord.append([x, y])

coord.sort(key=lambda x: (x[0], x[1]))

for x, y in coord:
    print(x, y)