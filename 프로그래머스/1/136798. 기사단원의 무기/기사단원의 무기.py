import math

def getDivisor(number):
    # N의 약수를 구할 때는, 1부터 N의 sqrt(N) 까지의 수만 0으로 나누어 떨어지는지 확인하면 된다!
    if number == 1:
        return 1

    divisor = []
    for i in range(1, int(math.sqrt(number)) + 1):
        if number % i == 0:
            divisor.append(i)
            if i != number // i: # 똑같은 숫자가 들어가는 것을 방지하기 위한 조건
                divisor.append(number // i)
    return len(divisor)
        
def solution(number, limit, power):
    ironWeight = 0
    for i in range(1, number + 1):
        divisor_count = getDivisor(i)
        
        if divisor_count > limit: # 제한수치를 초과한 기사
            ironWeight += power
        else: # 제한 수치 이하인 기사
            ironWeight += divisor_count
        
    return ironWeight
