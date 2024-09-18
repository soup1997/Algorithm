from functools import cmp_to_key

def compare(x, y):
    s1 = x + y
    s2 = y + x
    
    if int(s1) > int(s2):
        return -1
    
    elif int(s1) < int(s2):
        return 1

    else:
        return 0
    
def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key=cmp_to_key(compare))
    answer = str(int(''.join(numbers))) # 앞에 0이 나오는 경우 처리해야함
    return answer