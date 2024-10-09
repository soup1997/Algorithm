def solution(a, b, n):
    answer = 0
    while n >= a:
        coke = (n // a) * b  # 얻을 수 있는 콜라의 갯수
        answer += coke
        n = n % a + coke  # 남은 빈 병에 새로 받은 콜라의 빈 병을 더해줌
    return answer