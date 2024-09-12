def solution(arr1, arr2):
    answer = []
    for vec1, vec2 in zip(arr1, arr2):
        row = []
        for i in range(len(vec1)):
            row.append(vec1[i] + vec2[i])
        
        answer.append(row)
        
    return answer