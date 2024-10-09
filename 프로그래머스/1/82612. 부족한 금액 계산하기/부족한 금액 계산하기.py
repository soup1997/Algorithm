def solution(price, money, count):
    answer = 0
    cnt = 1
    
    while(cnt <= count):
        answer += (price * cnt)
        cnt += 1
    
    if answer > money:
        return answer - money
    
    else:
        return 0