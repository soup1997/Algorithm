def solution(participant, completion):
    participant.sort()
    completion.append("z")
    completion.sort()

    for (i, j) in zip(participant, completion):
        if i != j:
            return i