def solution(hp):
    damage = [5, 3, 1]
    num = [0, 0, 0]
    
    num[0] = hp // damage[0]
    num[1] = (hp % damage[0]) // damage[1]
    num[2] = ((hp % damage[0]) % damage[1]) // damage[2]

    answer = sum(num)
    return answer