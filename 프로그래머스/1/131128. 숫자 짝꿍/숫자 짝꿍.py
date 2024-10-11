def solution(X, Y):
    # 0부터 9까지의 숫자 카운트를 저장할 리스트
    X_count = [0] * 10
    Y_count = [0] * 10
    
    # X와 Y에서 각 숫자의 등장 횟수를 카운트
    for x in X:
        X_count[int(x)] += 1
    for y in Y:
        Y_count[int(y)] += 1
    
    # 공통으로 등장하는 숫자들의 최소 횟수를 구해 결과에 추가
    answer = []
    for i in range(10):
        count = min(X_count[i], Y_count[i])
        answer.extend([str(i)] * count)
    
    # 정답이 없는 경우
    if len(answer) == 0:
        return "-1"
    
    # 내림차순 정렬
    answer.sort(reverse=True)
    
    # 정답이 '0'으로만 이루어진 경우
    if answer[0] == '0':
        return '0'
    
    return ''.join(answer)