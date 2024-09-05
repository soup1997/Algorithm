import sys

string = list(sys.stdin.readline().strip())
bomb = list(sys.stdin.readline().strip())
e = len(bomb)

stack = []

for char in string:
    stack.append(char)
    
    if len(stack) >= e and stack[-1] == bomb[-1]:
        stringSeg = ''.join(stack[-e:])
        stringBomb = ''.join(bomb)
        
        if stringSeg == stringBomb:
            for _ in range(e):
                stack.pop()
                       
if stack:
    print(*stack, sep='')
else:
    print("FRULA")    