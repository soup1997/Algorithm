import sys

def check():
    while True:
        a, b, c = map(int, sys.stdin.readline().split())
        lines = sorted([a, b, c])
        line_set = set(lines)
        
        if len(line_set) == 1 and 0 in line_set:
            break

        else:
            if lines[-1] >= (lines[0] + lines[1]):
                print("Invalid")
            elif len(line_set) == 1:
                print("Equilateral")
            elif len(line_set) == 2:
                print("Isosceles")
            else:
                print("Scalene")
            
check()