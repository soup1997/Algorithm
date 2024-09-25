# 우선순위
# 1.자주 나오는 단어일수록 앞에 배치한다.
# 2.해당 단어의 길이가 길수록 앞에 배치한다.
# 3.알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다 (이건 건드릴 수가 없음)
import sys

n, m = map(int, sys.stdin.readline().split()) # 단어의 갯수, 외울 단어의 길이 기준
dictionary = {}

for _ in range(n):
    word = sys.stdin.readline().strip()
    if len(word) >= m: # 길이가 m 이상이어야 함
        if word not in dictionary:  # 'None' 체크 대신 'in' 사용
            dictionary[word] = 0
        
        else:
            dictionary[word] += 1

# 가장 많이 나오는 단어가 가장 앞에 배치됨 (제일 작은 -값)
# 단어가 길수록 앞에 배치됨 (제일 작은 -값)
# 알파벳 사전 순으로 정렬됨
dictionary = sorted(dictionary, key=lambda x: (-dictionary[x], -len(x), x))
print(*dictionary, sep="\n")