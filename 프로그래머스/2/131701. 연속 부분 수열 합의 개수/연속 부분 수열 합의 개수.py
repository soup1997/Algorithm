from collections import deque

def solution(elements):
    cases = set()
    dq = deque(elements)
    length = 1
    
    while length <= len(elements):
        for i in range(len(elements)):
            dq.rotate(1)
            cases.add(sum(list(dq)[:length]))
            
        length += 1
        
    return len(cases)