string_hash = {}
string = input().upper()
 
for i in set(string):
    string_hash[i] = string.count(i)

values = list(string_hash.values())
max_value = max(values)

if values.count(max_value) != 1:
    print("?")

else:
    for key in string_hash.keys():
        if string_hash[key] == max_value:
            print(key)
            break