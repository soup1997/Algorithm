import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    teams = list(map(int, sys.stdin.readline().split())) # 팀 번호를 나타내는 n개의 정수
    notQualified = []
    
    # 자격없는 팀 걸러내기
    for i in set(teams):
        if teams.count(i) < 6: # 6명 미만이므로 자격 X
            notQualified.append(i)
    
    # 차집합 이용, 자격있는 팀만 board 생성
    team_list = list(set(teams) - set(notQualified))
    board = {team:[0, 0, 0] for team in team_list} # 자격이 있는 팀 [총점, 카운트 변수, 5번째 선수의 점수]
    
    # 자격있는 팀만 board 업데이트
    score = 1
    for j in teams:
        if j not in notQualified:
            board[j][1] += 1 # 5번째 선수 카운트를 위한 카운팅 변수
            
            if board[j][1] <= 4:
                board[j][0] += score 
            
            if board[j][1] == 5: # 5번째 선수라면
                board[j][2] = score
            
            score += 1
     
    board = sorted(board, key=lambda x:(board[x][0], board[x][2]))
    print(board[0])