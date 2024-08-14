def solution(s):
    stack = []

    if s[0] == ')':
        return False
    
    else:
        for i in range(len(s)):
            if s[i] == '(': # push
                stack.append(s[i])
        
            elif not len(stack): # empty check
                return False
            
            else: # pop
                stack.pop(-1)
        
        answer = True if not len(stack) else False
        return answer