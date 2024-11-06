import heapq
from collections import deque

def solution(priorities, location):
    q = deque([])
    hq = [] # python은 디폴트 힙이 최소 힙
    
    for i in range(len(priorities)):
        q.append([i, priorities[i]])
        heapq.heappush(hq, -priorities[i])
    
    cnt = 1
    
    while hq:
        idx, priority = q.popleft()
        
        if priority != -hq[0]:
            q.append([idx, priority])
            
        else: # 가장 우선순위가 높은 프로세스 발견
            if idx == location:
                return cnt
            
            heapq.heappop(hq) # 실행되는 프로세스므로 hq에서도 제거
            cnt += 1
    
    return 0