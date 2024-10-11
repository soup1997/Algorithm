def setRange(newChar):
    return chr(ord('a') + ((ord(newChar) - ord('a')) % 26))

def solution(s, skip, index):
    answer = ''
    skip = set(skip)  # 효율성을 위해 set으로 변환
    
    for c in s:
        cnt = 0
        newChar = c
        
        while cnt < index:
            newChar = setRange(chr(ord(newChar) + 1))  # 다음 문자로 이동
            
            if newChar not in skip:  # skip에 없으면 count 증가
                cnt += 1
        
        answer += newChar
    
    return answer
