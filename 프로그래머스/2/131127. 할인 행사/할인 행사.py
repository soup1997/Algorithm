def solution(want, number, discount):
    answer = 0
    wants = {want[i]: number[i] for i in range(len(want))}
    
    for i in range(len(discount) - 9):
        wants_copied = wants.copy()
        
        for j in range(i, i + 10):
            if discount[j] in wants_copied:
                wants_copied[discount[j]] -= 1
        
        if all(count == 0 for count in wants_copied.values()): # sum(wants_copied.values() == 0의 반례, [1, -1, 0, 0, 0]
            answer += 1
        
    return answer