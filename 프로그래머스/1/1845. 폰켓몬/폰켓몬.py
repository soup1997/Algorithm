def solution(nums):
    pocket = {i: nums.count(i) for i in nums}
    monster_type =  len(list(pocket.keys()))
    answer = monster_type if monster_type < (len(nums) / 2) else (len(nums) / 2)
        
    return answer