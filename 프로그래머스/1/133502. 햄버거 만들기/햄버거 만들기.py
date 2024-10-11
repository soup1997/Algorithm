def solution(ingredient):
    temp = []
    cnt = 0
    
    for i in ingredient:
        temp.append(i)
        
        if temp[-4:] == [1, 2, 3, 1]: # 백준 문자열 폭발 문제와 완전 동일함
            cnt += 1
            # temp = temp[:len(temp)-4]
            del temp[-4:] # slicing은 복사가 이루어지므로 시간초과 발생할 수 있음, del이 훨씬 빠름
    
    return cnt