import sys

def get_average(S, A, B):
    avg = 0
    number = B - (A-1)

    for i in range(A-1, B):
        avg += S[i]
    
    return avg / number

N, K = map(int , input().split(' '))
S = list(map(int, input().split(' ')))

for i in range(K):
    A, B = map(int, input().split(' '))
    result = get_average(S, A, B)
    print('{0:.2f}'.format(result))
    