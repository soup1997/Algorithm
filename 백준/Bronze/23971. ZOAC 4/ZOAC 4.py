import sys
import math

H, W, N, M = map(int, sys.stdin.readline().split())

person_in_col = math.ceil(H / (N+1)) # 1열에 앉을 수 있는 사람의 수
person_in_row = math.ceil(W / (M+1)) # 1행에 앉을 수 있는 사람의 수

print(person_in_col * person_in_row)