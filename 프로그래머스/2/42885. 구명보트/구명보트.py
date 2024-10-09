def solution(people, limit):
    answer = 0
    people.sort() # 정렬 후 몸무게 큰 사람과 작은 사람을 짝지음

    idx1, idx2 = 0, len(people) - 1
    
    while(idx1 <= idx2):  # 두 명씩 구출해서 다 구출할 때까지 비교
        minWeight = people[idx1]
        maxWeight = people[idx2]
        
        if(minWeight + maxWeight <= limit):  # limit 보다 작거나 같으면 둘다 구출 가능
            idx1 += 1
            idx2 -= 1
            
        else: # 안되면 일단 몸무게 큰 사람부터 먼저 구출
            idx2 -= 1    
            
        answer += 1
        
    return answer