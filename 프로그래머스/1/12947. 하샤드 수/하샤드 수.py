def solution(x):
    strX = str(x)
    total = sum([int(c) for c in strX])
    
    if x % total == 0:
        answer = True
    
    else:
        answer = False
    
    return answer