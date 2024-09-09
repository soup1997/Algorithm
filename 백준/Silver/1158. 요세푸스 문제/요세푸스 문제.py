# 코드트리 원형순열에서의 인원제거와 완전 동일한 문제
# 원이라는건, 그냥 바로 원형 큐를 떠올리면 된다.

from collections import deque

n, k = map(int, input().split())
q = deque([i for i in range(1, n+1)])
answer = []
cnt = 1

while q:
    if cnt == k:
        answer.append(q.popleft())
        cnt = 1
    
    else:
        q.append(q.popleft())
        cnt += 1

string = map(str, answer)
string = ', '.join(string)
print(f"<{string}>")