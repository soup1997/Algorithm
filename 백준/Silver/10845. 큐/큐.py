import sys

N = int(sys.stdin.readline())
q = []

for i in range(N) :
    command = sys.stdin.readline().split()

    if command[0] == 'push' : q.append(command[1])

    elif command[0] == 'pop' : 
        print(q.pop(0)) if len(q) != 0 else print(-1)

    elif command[0] == 'size' : print(len(q))

    elif command[0] == 'empty' :
        print(1) if len(q) == 0 else print(0)
            
    elif command[0] == 'front' :
        print(-1) if len(q) == 0 else print(q[0])
    
    elif command[0] == 'back' :
        print(-1) if len(q) == 0 else print(q[-1])