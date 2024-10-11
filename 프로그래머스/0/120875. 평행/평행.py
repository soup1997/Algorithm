import math

tmp = []
combs = []
def makeComb(idx, dots):
    if len(tmp) == 2:
        combs.append([tmp[0], tmp[1]])
    else:
        for i in range(idx, len(dots)):
            tmp.append(dots[i])
            makeComb(i+1, dots)
            tmp.pop()

def solution(dots):
    answer = 0
    makeComb(0, dots)

    for c in combs:
        rest = list(set(map(tuple, dots)) - set(map(tuple, c)))
        
        gradient1 = (rest[1][1] - rest[0][1]) / (rest[1][0] - rest[0][0])
        gradient2 = (c[1][1] - c[0][1]) / (c[1][0] - c[0][0])
        
        if gradient1 == gradient2:
            return 1
        
    return 0