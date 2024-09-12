# 보트로 가장 무거운 사람과 가장 가벼운 사람을 같이 묶어서 처리하는게 핵심
from collections import deque

def solution(people, limit):
    boat = 0
    people = deque(sorted(people))
    
    while len(people) > 1:
        if people[0] + people[-1] <= limit: # 최댓값과 최솟값 묶어서 보트태움
            boat += 1
            people.pop()    # 최대 빼기
            people.popleft()    # 최소 빼기
            
        else:
            boat += 1
            people.pop() # 최대 빼기
            
    if people:  # people에 1명 남아있는 경우 처리
        boat += 1
                
    return boat