import sys

n = int(sys.stdin.readline())

for _ in range(n):
    stack = []
    ps = list(sys.stdin.readline().strip())
    print_flag = True
    
    for bracket in ps:
        if bracket == '(':
            stack.append(bracket)
        
        elif bracket == ')':
            if stack: # 스택이 차있다면
                stack.pop()
            
            else: # 스택이 비어있다면
                print("NO")
                print_flag = False
                break
    
    if print_flag:
        if stack: # 스택이 차있다면 VPS아님, 비어있다면 VPS
            print("NO")
        else:
            print("YES")