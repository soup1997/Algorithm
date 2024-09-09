def solution(s):
    s_list = list(s)
    stack = []
    
    for char in s_list:
        if stack and stack[-1] == char:
            stack.pop()
        
        else:
            stack.append(char)
            
    answer = 1 if not stack else 0
    return answer