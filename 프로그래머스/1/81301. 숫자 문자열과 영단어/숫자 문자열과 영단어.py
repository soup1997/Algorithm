def convert(s):
    if s == "zero":
        return '0'
    elif s == "one":
        return '1'
    elif s == "two":
        return '2'
    elif s == "three":
        return '3'
    elif s == "four":
        return '4'
    elif s == "five":
        return '5'
    elif s == "six":
        return '6'
    elif s == "seven":
        return '7'
    elif s == "eight":
        return '8'
    elif s == "nine":
        return '9'
    
def solution(s):
    answer = ""
    tmp = ""
    numbers = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    
    for c in s:
        if c >= '0' and c <= '9':
            answer += c
        else:
            tmp += c
            if tmp in numbers:
                answer += convert(tmp)
                tmp = ""               
            
    return int(answer)