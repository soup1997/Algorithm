def solution(progresses, speeds):
    answer = []
    
    # 남은 일수 계산하기
    days = []
    for i, progress in enumerate(progresses):
        remains =  (100 - progress)
        day = (remains // speeds[i]) if (remains % speeds[i]) == 0 else (remains // speeds[i]) + 1
        days.append(day)
    
    # 배포가능 기능 갯수 세기
    while len(days):
        top, cnt = days.pop(0), 1
        
        while len(days) and top >= days[0]:
            days.pop(0)
            cnt += 1
        
        answer.append(cnt)
            
    return answer