import sys

transmission = input().split(" ")
result = '0'

for gear in transmission:
    result += gear

result = result[1:] # 0제거

if result == "12345678":
    print("ascending")

elif result == "87654321":
    print("descending")

else:
    print("mixed")

