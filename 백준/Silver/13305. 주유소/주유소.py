import sys

n = int(sys.stdin.readline()) # 도시의 갯수
length = list(map(int, sys.stdin.readline().split())) # 도로의 길이
price = list(map(int, sys.stdin.readline().split())) # 주유소의 가격

minPrice = price[1]
cost = price[0] * length[0] # 처음에 기름 무조건 넣어야 함

# 가격을 최소화 하기 위해, 가장 싼 곳에서 가장 많이 구해야 한다. 따라서 가격의 최솟값을 찾아야 한다.
# 가장 싼곳에서 가야할 길이 만큼 기름을 구매한다.

for i in range(1, n-1):
    minPrice = min(minPrice, price[i])
    cost += minPrice * length[i]
    
print(cost)