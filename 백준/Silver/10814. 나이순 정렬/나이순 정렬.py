import sys

n = int(sys.stdin.readline())
guest = []

cnt = 1
for _ in range(n):
    age, name = sys.stdin.readline().split()
    guest.append([age, name, cnt])
    cnt += 1
    
guest.sort(key=lambda x: (int(x[0]), x[2]))

for g in guest:
    print(g[0], g[1])