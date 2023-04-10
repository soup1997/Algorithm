import sys

K, P, N = map(int, input().split())
mod = 1000000007

for _ in range(N):
    K = (K * P) % mod

print(K)
