def solution(answers):
    answer = []
    score = [0, 0, 0]
    
    p1 = [1, 2, 3, 4, 5]  # Pattern for participant 1
    p2 = [2, 1, 2, 3, 2, 4, 2, 5]  # Pattern for participant 2
    p3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]  # Pattern for participant 3
    
    for i in range(len(answers)):
        if answers[i] == p1[i % len(p1)]:
            score[0] += 1
        if answers[i] == p2[i % len(p2)]:
            score[1] += 1
        if answers[i] == p3[i % len(p3)]:
            score[2] += 1
    
    answer = [i + 1 for i in range(3) if score[i] == max(score)]
    
    return answer
