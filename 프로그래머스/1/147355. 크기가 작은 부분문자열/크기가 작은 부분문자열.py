def solution(t, p):
    answer = 0
    
    for i in range(0, len(t)-len(p)+1):
        seg = t[i:i+len(p)]
        if(int(seg) <= int(p)):
            answer += 1
            
    return answer