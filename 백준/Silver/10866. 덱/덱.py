import sys
from collections import deque

dq = deque()

# Reading the number of commands
number = int(sys.stdin.readline().strip())

def check_empty(dq):
    return not len(dq)

for _ in range(number):
    command = sys.stdin.readline().split()
    
    if command[0] == "push_front":
        dq.appendleft(int(command[1]))
        
    elif command[0] == "push_back":
        dq.append(int(command[1]))
        
    elif command[0] == "pop_front":
        if check_empty(dq):
            print(-1)
        else:
            print(dq.popleft())
    
    elif command[0] == "pop_back":
        if check_empty(dq):
            print(-1)
        else:
            print(dq.pop())
    
    elif command[0] == "size":
        print(len(dq))
    
    elif command[0] == "empty":
        print(1 if check_empty(dq) else 0)
    
    elif command[0] == "front":
        print(dq[0] if not check_empty(dq) else -1)
            
    elif command[0] == "back":
        print(dq[-1] if not check_empty(dq) else -1)