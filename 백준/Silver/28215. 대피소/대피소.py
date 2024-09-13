import sys
from itertools import combinations

# Read input
n, k = map(int, sys.stdin.readline().split())
homes = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

maximum_dist = []

# Iterate over all combinations of k shelters
for shelter in combinations(homes, k):
    n_shelter = list(set(map(tuple, homes)) - set(map(tuple, shelter)))  # Non-shelter homes
    
    distances = []
    
    # Calculate the minimum distance from each non-shelter home to the closest shelter
    for i in n_shelter:
        min_dist = float('inf')  # Use float('inf') for initial comparison
        for j in shelter:
            dist = abs(i[0] - j[0]) + abs(i[1] - j[1])
            min_dist = min(min_dist, dist)
        distances.append(min_dist)
    
    # Compute the maximum of the minimum distances for this set of shelters
    maximum_dist.append(max(distances))

# Output the minimum of the maximum distances
print(min(maximum_dist))
