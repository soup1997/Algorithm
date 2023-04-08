import sys

def answer(bag, W):
    total_price = 0

    for weight, price in bag:
        if(W >= weight):
            total_price += weight * price
            W -= weight
        
        else:
            total_price += W * price
            break

    print(total_price)


bag = []
W, N = map(int, input().split(" "))

for _ in range(N):
    weight, price = map(int, input().split(" "))
    bag.append([weight, price])

bag.sort(key=lambda x: x[1], reverse=True) 
answer(bag, W)