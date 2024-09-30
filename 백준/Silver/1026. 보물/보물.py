import sys

# S = A[0] × B[0] + ... + A[N-1] × B[N-1] 를 작게하는 최소 값
n = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))

# 전략: B의 max와 A의 min이 곱해지면 된다

A_new = sorted(A) # 오름차순 정렬 
B_new = sorted(B, reverse=True) # 내림차순 정렬
total = sum([A_new[i]*B_new[i] for i in range(n)])

print(total)