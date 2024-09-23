import sys 
import math

def change_state(x):
    return 0 if x == 1 else 1

switch_num = int(sys.stdin.readline())  # Number of switches (positive integer <= 100)
switch = list(map(int, sys.stdin.readline().split()))  # Switch states (1 for on, 0 for off)

student_num = int(sys.stdin.readline())  # Number of students (positive integer <= 100)
earned_switch = [list(map(int, sys.stdin.readline().split())) for _ in range(student_num)]

for s, c in earned_switch:
    if s == 1:  # If male
        switch_index = switch_num // c
        switch_index = [coefficient * c for coefficient in range(1, switch_index + 1)]
        
        for si in switch_index:
            si -= 1  # Adjust for 0-based index
            switch[si] = change_state(switch[si])
    
    else:  # If female
        c -= 1  # Adjust for 0-based index
        index = 0  # Start from the center switch
        
        while (c - index >= 0 and c + index < len(switch) and 
               switch[c + index] == switch[c - index]):
            switch[c + index] = change_state(switch[c + index])
            switch[c - index] = change_state(switch[c - index])
            index += 1
        
        switch[c] = change_state(switch[c])

# Print the final states of switches
for i in range(switch_num):
    print(switch[i], end=" ")
    if (i + 1) % 20 == 0:  # Adjust for output formatting
        print()
