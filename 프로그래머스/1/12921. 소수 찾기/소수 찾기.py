import math

def checkPrimeNumber(x):
    # 2부터 x의 제곱근까지의 숫자
    for i in range(2, int(math.sqrt(x) + 1)):
    	if x % i == 0: # 나눠떨어지는 숫자가 있으면 소수가 아님
        	return False
        
    return True	
    
def solution(n):
    answer = 0
    
    for i in range(2, n+1):
        if checkPrimeNumber(i):
            answer += 1
            
    return answer