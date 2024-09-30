import sys

series = list(sys.stdin.readline().rstrip())

idx = 0
num = 1

while True:
    s_num = str(num)
    for s in s_num:
        if series[idx] == s:
            idx += 1
    
            if idx == len(series):
                print(num)
                exit()

    num += 1