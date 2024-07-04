from heapq import *

# python의 heapq는 default가 최소 힙

def solution(scoville, K):
    if K == 0:
        return -1
    
    else:
        answer = 0
        heapify(scoville)
        
        while scoville[0] < K:
            root1 = heappop(scoville)
            root2 = heappop(scoville)
            heappush(scoville, root1 + (2 * root2))
            answer += 1

        return answer