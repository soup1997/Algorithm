# Greedy 알고리즘
# damage가 등차 수열 관계를 가지고 있기 때문에 가장 큰 수 부터 차례대로 하는 것이 최소 개미의 수
# 등차수열, 등비수열, 배수의 관계를 가지고 있기 때문에 가능한 솔루션, 아니라면 최적해가 될 수 없음
def solution(hp):
    damage = [5, 3, 1]
    num = [0, 0, 0]
    
    num[0] = hp // damage[0]
    num[1] = (hp % damage[0]) // damage[1]
    num[2] = ((hp % damage[0]) % damage[1]) // damage[2]

    answer = sum(num)
    return answer
