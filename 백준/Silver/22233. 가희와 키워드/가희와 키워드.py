import sys
n, m = map(int, sys.stdin.readline().split())
note = {sys.stdin.readline().rstrip(): 1 for _ in range(n)}

for _ in range(m):
    keywords = sys.stdin.readline().rstrip().split(",")
    
    for k in keywords:
        if k in note:
            note[k] -= 1
            
            if not note[k] < 0:
                n -= 1
    print(n)