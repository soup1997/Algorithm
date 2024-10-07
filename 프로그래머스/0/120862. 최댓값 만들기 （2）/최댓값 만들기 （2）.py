def solution(numbers):
    answer = 0
    numbers.sort()
    
    if numbers[0] < 0 and numbers[1] < 0:
        tmpMax1 = numbers[0] * numbers[1]
        tmpMax2 = numbers[-1] * numbers[-2]
        if tmpMax1 > tmpMax2:
            return tmpMax1
    
    return numbers[-1] * numbers[-2]