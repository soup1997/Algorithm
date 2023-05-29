import sys

while True:
    s = []
    check = True
    string = sys.stdin.readline().rstrip() # sys.stdin.readline에는 자동적으로 "\n"을 추가시킴, rstrip()으로 개행문자제거
    
    if string == ".": break
    
    for c in string:
        if (c == '(') or (c == '['): s.append(c)
    
        elif (c == ')'):
            if (len(s)!= 0) and (s[-1] == '('): s.pop()
            
            else:
                check = False
                break
    
        elif (c == ']'):
            if (len(s)!= 0) and (s[-1] == '['): s.pop()
            
            else:
                check = False
                break
    
    if (len(s) == 0) and (check): print("yes")
    else: print("no")