def solution(keymap, targets):
    answer = []
    memory = {}
    
    for k in keymap: # keymap을 완전 탐색하면서 최소 인덱스가 무엇인지 확인하기, memory 업데이트
        for i in range(len(k)):
            memory[k[i]] = (i + 1) if k[i] not in memory else min(memory[k[i]], i+1)
    
    for t in targets:
        cnt = 0
        for i in range(len(t)):
            if t[i] in memory:
                cnt += memory[t[i]]
            else:
                cnt = -1
                break
        answer.append(cnt)

    return answer