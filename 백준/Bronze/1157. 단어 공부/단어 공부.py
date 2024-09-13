import sys

string = sys.stdin.readline().strip().upper()
string_set = list(set(string))
char_cnt = [string.count(c) for c in string_set]

maximum = max(char_cnt)

if char_cnt.count(maximum) != 1: # maximum이 여러개 존재
    print("?")

else: # maximum이 1개만 존재
    max_idx = char_cnt.index(maximum)
    print(string_set[max_idx])