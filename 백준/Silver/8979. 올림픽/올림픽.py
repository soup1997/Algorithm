import sys

n, k = map(int, sys.stdin.readline().split())
rank = {}

for _ in range(n):
    c_id, gold, silver, bronze = map(int, sys.stdin.readline().split())
    rank[c_id] = [gold, silver, bronze, 0]


for key1, medal1 in rank.items():
    ranking = 1
    for key2, medal2 in rank.items():
        if key1 != key2: # 이중 반복문 돌면서 자기 자신을 검사할 필요 없음
            
            if medal1[0] < medal2[0]: # 조건 1: 금메달 수가 더 많은 나라
                ranking += 1
        
            elif medal1[0] == medal2[0]: # 조건 2: 금메달 수가 같으면, 은메달 수가 더 많은 나라
                if medal1[1] < medal2[1]:
                    ranking += 1
            
            else: # 조건 3: 금, 은메달 수가 모두 같으면, 동메달 수가 더 많은 나라 
                if medal1[2] < medal2[2]:
                    ranking += 1
                    
    rank[key1][-1] = ranking # 랭킹 정보 업데이트

print(rank[k][-1])