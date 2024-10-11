def solution(players, callings):
    position = {player:idx for idx, player in enumerate(players)}
    
    for c in callings:
        rank = position[c] # 호명당한 선수의 현재 순위
        
        position[players[rank]] -= 1 # 호명당한 선수의 순위를 앞당김
        position[players[rank-1]] += 1 # 호명당한 선수의 앞에 있는 선수
        players[rank-1], players[rank] = players[rank], players[rank-1] # 두 선수의 위치를 바꿈
    
    return players