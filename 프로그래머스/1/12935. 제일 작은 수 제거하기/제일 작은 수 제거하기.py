def solution(arr):
    if(len(arr) == 1):
        return [-1]
    
    answer = []
    minNum = min(arr)
    
    for a in arr:
        if a != minNum:
            answer.append(a)
            
    return answer