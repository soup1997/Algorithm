import math
import sys

H, W, N, M = map(int, sys.stdin.readline().split())

a = math.ceil(H/(N+1))
b = math.ceil(W/(M+1))
answer = a*b 

print(answer)