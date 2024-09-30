import sys

n = int(sys.stdin.readline())
meetings = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

# 회의가 빨리 끝나는 순서대로 정렬, 끝나는 시간이 같으면 시작하는 순서대로 정렬
meetings.sort(key=lambda x: (x[1], x[0]))

cnt = 1 # 최소 1개의 회의는 진행할 수 있으므로 1로 초기화

curr_meeting = meetings[0]

for i in range(1, len(meetings)):
    next_meeting = meetings[i]
    
    if curr_meeting[1] <= next_meeting[0]:
        cnt += 1
        curr_meeting = next_meeting
        
print(cnt)