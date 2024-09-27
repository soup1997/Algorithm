s = input().rstrip()
idx = 0
stack = []
ans = []
while idx < len(s):
    stack.append(s[idx])
    
    if s[idx] == "<": # tag 검출
        stack.pop() # append 취소
        S = ''
        while stack:
            S += stack.pop()
        if S != '':
            ans.append(S)
        start = idx
        while s[idx] != ">": # tag 닫힐 때까지 idx 증가
            idx += 1
        ans.append(s[start:idx+1]) # tag 통째로 ans에 저장
            
    elif s[idx] == " ": # 공백 검출
        stack.pop() # append 취소
        S = ''
        while stack:
            S += stack.pop()
        ans.append(S)
        ans.append(" ")
    
    elif idx == len(s)-1: # 문자열 끝 도달
        S = ''
        while stack:
            S += stack.pop()
        ans.append(S)
    
    idx += 1
    
print(*ans, sep="")