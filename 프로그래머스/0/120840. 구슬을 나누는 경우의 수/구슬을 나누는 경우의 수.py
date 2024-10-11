import math

def solution(balls, share):
    if balls == share:
        return 1
    else:
        return math.comb(balls, share)