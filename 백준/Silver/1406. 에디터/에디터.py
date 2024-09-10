import sys

S = list(sys.stdin.readline().strip())
rest = []

m = int(sys.stdin.readline())

for _ in range(m):
    command = sys.stdin.readline().split()
    
    if command[0] == "L":
        if S:
            rest.append(S.pop())
    
    elif command[0] == "D":  # The core operation of this problem
        if rest:
            S.append(rest.pop())
    
    elif command[0] == "B":
        if S:
            S.pop()
    
    else:
        S.append(command[1])

S.extend(reversed(rest))
print(''.join(S))
