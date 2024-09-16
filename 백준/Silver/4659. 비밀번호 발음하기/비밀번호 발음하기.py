import sys

def condition(string):
    moeum = ['a', 'e', 'i', 'o', 'u']
    
    # 조건 1: 모음 하나를 반드시 포함하여야 한다.
    moeum_cnt = 0
    
    for m in moeum:
        if m in string:
            moeum_cnt += 1
    
    if moeum_cnt == 0:
        return f'<{string}> is not acceptable.'
    
    # 조건 2: 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
    moeum_cnt = 0
    jaeum_cnt = 0
    for s in string: # 조건 2
        if s in moeum:
            moeum_cnt += 1
            jaeum_cnt = 0
        
        else:
            jaeum_cnt += 1
            moeum_cnt = 0
            
        if moeum_cnt >= 3 or jaeum_cnt >= 3:
            return f'<{string}> is not acceptable.'
        
    # 조건 3: 같은 글자가 연속적으로 두번 오면 안되나, ee와 oo는 허용한다.
    sequence_cnt = 1
    sequence_init = string[0]
    
    for i in range(1, len(string)):
        if string[i] != sequence_init:
            sequence_init = string[i]
            sequence_cnt = 1
        
        else:
            sequence_cnt += 1
        
        if sequence_cnt == 2:
            if sequence_init == 'e' or sequence_init == 'o':
                sequence_cnt = 1
            else:
                return f'<{string}> is not acceptable.'
    
    # 조건 1, 2, 3 모두 안겹친 경우 acceptable
    return f'<{string}> is acceptable.'   

while True:
    string = sys.stdin.readline().strip()
    
    if string == "end":
        break
        
    print(condition(string))