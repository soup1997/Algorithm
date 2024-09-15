import sys
from itertools import combinations

n, k = map(int, sys.stdin.readline().split())
homes = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]
maximum_dist = []

for shelter in combinations(homes, k):
    if n != k:
        n_shelter = list(set(homes) - set(map(tuple, shelter))) # 대피소가 아닌 집들
        
    else:
        n_shelter = shelter
        
    distances = []
    
    for i in n_shelter:
        min_dist = 10000000000
        for j in shelter:
            dist = (abs(i[0]-j[0]) + abs(i[1]-j[1]))
            min_dist = min(min_dist, dist)
        distances.append(min_dist)
    
    maximum_dist.append(max(distances))

print(min(maximum_dist))