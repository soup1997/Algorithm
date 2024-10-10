def solution(s):
    if len(s) == 4 or len(s) == 6:
        for c in s:
            if not (c >= '0' and c <= '9'):
                return False
        
        return True

    else:        
        return False