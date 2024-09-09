# 입력
n = int(input())
series = [int(input()) for _ in range(n)]

# 문제를 푸는데 필요한 tool
stack = []
results = []
idx = 0

for i in range(1, n+1):
    stack.append(i)
    results.append("+")

    while (stack and stack[-1] == series[idx]):
        stack.pop()
        results.append("-")
        idx += 1
    

if len(stack) == 0:
    print(*results, sep='\n')

else:
    print("NO")