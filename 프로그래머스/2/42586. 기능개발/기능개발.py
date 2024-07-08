def solution(progresses, speeds):
    answer = []
    
    # Calculate the remaining days for each task
    days = []
    for i, progress in enumerate(progresses):
        remains =  (100 - progress)
        # Calculate the required days considering the speed
        day = (remains // speeds[i]) if (remains % speeds[i]) == 0 else (remains // speeds[i]) + 1
        days.append(day)
    
    # Count the number of tasks that can be released together
    while days:
        # Take the first element as the benchmark
        top = days.pop(0)
        cnt = 1
        
        # Check subsequent tasks if they can be released together
        while days and top >= days[0]:
            days.pop(0)
            cnt += 1
        
        answer.append(cnt)
            
    return answer
