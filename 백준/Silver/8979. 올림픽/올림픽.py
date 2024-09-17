import sys

n, k = map(int, sys.stdin.readline().split())
rank = {}

# 국가별 메달 정보를 입력받기
for _ in range(n):
    c_id, gold, silver, bronze = map(int, sys.stdin.readline().split())
    rank[c_id] = [gold, silver, bronze, 0]

# 랭킹 계산
for key1, medal1 in rank.items():
    ranking = 1
    for key2, medal2 in rank.items():
        if key1 != key2:
            # 조건 1: 금메달 수 비교
            if medal1[0] < medal2[0]:
                ranking += 1
            # 조건 2: 금메달 수가 같으면 은메달 수 비교
            elif medal1[0] == medal2[0] and medal1[1] < medal2[1]:
                ranking += 1
            # 조건 3: 금, 은메달 수가 같으면 동메달 수 비교
            elif medal1[0] == medal2[0] and medal1[1] == medal2[1] and medal1[2] < medal2[2]:
                ranking += 1
                
    rank[key1][-1] = ranking # 국가별 랭킹 정보 업데이트

# k번 국가의 랭킹 출력
print(rank[k][-1])
