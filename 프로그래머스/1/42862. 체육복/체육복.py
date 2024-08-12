def solution(n, lost, reserve):
    lost.sort()
    reserve.sort()
    
    for i in lost[:]: # 공통 요소 제거
        if i in reserve:
            reserve.remove(i)
            lost.remove(i)
            
    lost_copied = lost[:] # deep copy
    
    for i in lost_copied:
        if not(len(reserve)):
            break
        
        else:
            if i-1 in reserve:
                reserve.remove(i-1)
                lost.remove(i)

            elif i+1 in reserve:
                reserve.remove(i+1)
                lost.remove(i)        

    answer = n - len(lost)
    return answer