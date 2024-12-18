import sys

m = int(sys.stdin.readline())
s = []
series = [i for i in range(1, 21)]

for _ in range(m):
    command = sys.stdin.readline().split()
    
    if command[0] == "add":
        if int(command[1]) not in s:
            s.append(int(command[1]))

    elif command[0] == "remove":
        if int(command[1]) in s:
            s.remove(int(command[1]))
    
    elif command[0] == "check":
        if int(command[1]) in s:
            print(1) 
        else:
            print(0)
        
    elif command[0] == "toggle":
        if int(command[1]) in s:
            s.remove(int(command[1]))
        else:
            s.append(int(command[1]))
    
    elif command[0] == "all":
        s[:] = series
    
    else:
        s.clear()