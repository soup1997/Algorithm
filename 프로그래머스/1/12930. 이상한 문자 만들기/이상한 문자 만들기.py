def solution(s):
    # 각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열
    answer = []
    s_list = s.split(" ")
    
    for i in s_list:
        tmp = ""
        for j in range(len(i)):
            if j == 0:
                tmp += i[j].upper()
            else:
                if j % 2 == 0:
                    tmp += i[j].upper()
                else:
                    tmp += i[j].lower()
        answer.append(tmp)
        
    answer = ' '.join(answer)
    
    return answer