candidate = []
def makeComb():
    if len(candidate) == m:
        print(*candidate)
    
    else:
        for s in series:
            if (len(candidate) == 0) or (s not in candidate):
                candidate.append(s)
                makeComb()
                candidate.pop() 

n, m = map(int, input().split())
series = [i for i in range(1, n+1)]
makeComb()