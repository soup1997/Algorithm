# 동전을 적절히 사용해서 그 가치의 합을 K
# 이때 필요한 동전 개수의 최솟값을 구하는 프로그램

import sys

n, k = map(int, sys.stdin.readline().split())
coins = [int(sys.stdin.readline()) for _ in range(n)] # 동전의 가치 Ai가 오름차순, 배수 관계

cnt = 0

for i in range(len(coins)-1, -1, -1):
    if k == 0:
        break
        
    cnt += k // coins[i]
    k %= coins[i]

print(cnt)