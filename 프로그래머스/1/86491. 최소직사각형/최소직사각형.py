from heapq import *

def solution(sizes):
    width = []
    height = []
    
    for size in sizes:
        if size[0] < size[1]:
            size[0], size[1] = size[1], size[0]
    
        width.append(size[0])
        height.append(size[1])
        
    return max(width) * max(height)