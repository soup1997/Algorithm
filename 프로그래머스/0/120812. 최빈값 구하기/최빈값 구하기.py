def solution(array):
    answer = []
    set_array = set(array)
    
    for sa in set_array:
        answer.append([array.count(sa), sa])
    
    answer.sort(key=lambda x: x[0], reverse=True)
    
    if len(answer) >= 2 and answer[1][0] == answer[0][0]:
        return -1
    
    else:
        return answer[0][1]
