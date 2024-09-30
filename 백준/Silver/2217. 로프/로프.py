import sys
n = int(sys.stdin.readline())
weight = [int(sys.stdin.readline()) for _ in range(n)] # 각 로프가 버틸 수 있는 최대 중량

weight.sort(reverse=True) # 내림차순 정렬
ans = max(weight)
for i in range(n):
    ans = max(ans, (weight[i] * (i+1)))

print(ans)