def solution(nums):
    pocket = {i: nums.count(i) for i in nums}
    max_get = len(nums) / 2
    monster_type =  len(list(pocket.keys()))

    if monster_type < max_get:
        answer = monster_type
        
    else:
        answer = max_get
        
    return answer