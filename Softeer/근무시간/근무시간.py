import sys

def calc_time(start, end):
    sH, sM = map(int, start)
    eH, eM = map(int, end)

    totalHour = eH - sH
    totalMin = 0
    
    if sM < eM:
        totalMin = eM - sM
    
    elif sM > eM:
        totalMin = (60-sM) + eM
        totalHour -= 1
    
    else:
        pass

    return totalHour * 60 + totalMin

res = 0

for _ in range(5):
    start, end = input().split(" ")
    startTime = start.split(":")
    endTime = end.split(":")

    res += calc_time(startTime, endTime)

print(res)


