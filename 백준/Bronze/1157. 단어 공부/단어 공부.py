import sys

string = sys.stdin.readline().strip().upper()
string_hash = {c: string.count(c) for c in set(string)}

values = list(string_hash.values())
max_value = max(values)

if values.count(max_value) != 1:
    print("?")

else:
    for key in string_hash.keys():
        if string_hash[key] == max_value:
            print(key)
            break