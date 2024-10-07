def convBin(num1, num2, n):
    s1 =""
    s2 = ""
    
    while(num1 != 0):
        s1 = str(num1 % 2) + s1
        num1 //= 2
    
    while(num2 != 0):
        s2 = str(num2 % 2) + s2
        num2 //= 2
    
    # zero padding
    s1 = "0" * (n - len(s1)) + s1
    s2 = "0" * (n - len(s2)) + s2
    
    return (s1, s2)

def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        a, b = arr1[i], arr2[i]
        sa, sb = convBin(a, b, n)
        tmp = ""
        for j in range(n):
            if sa[j] == '1' or sb[j] == '1':
                tmp += "#"
            else:
                tmp += " "
        answer.append(tmp)
        
    return answer