# 임스와 여러 번 미니게임을 플레이하고자 하는 사람이 있으나, 
# 임스는 한 번 같이 플레이한 사람과는 다시 플레이하지 않습니다.

import sys

n, game = sys.stdin.readline().split()
mini_game = {"Y": 2-1, "F": 3-1, "O": 4-1} # 임스를 포함해야 하므로 1씩 빼기
players = [sys.stdin.readline().strip() for _ in range(int(n))]
players = set(players)

answer = len(players) // mini_game[game]
print(answer)