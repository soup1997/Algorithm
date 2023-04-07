import sys

def sum(A, B, index):
    print("Case #{0}: {1}".format(index+1, A+B))

N = int(input())

for i in range(N):
    A, B = map(int, input().split(" "))
    sum(A, B, i)
