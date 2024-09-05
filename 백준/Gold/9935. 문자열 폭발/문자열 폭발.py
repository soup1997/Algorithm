import sys

string = list(sys.stdin.readline().strip())
bomb = sys.stdin.readline().strip()

stack = []

for char in string:
    stack.append(char)
    
    if len(stack) >= len(bomb):
        stringSeg = ''.join(stack[-len(bomb):])
        
        if stringSeg == bomb:
            for _ in range(len(bomb)):
                stack.pop()
                       
if stack:
    print(*stack, sep='')
else:
    print("FRULA")
                     
        
    
        
        
        
    