class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for index, value in enumerate(nums):
            complement = target - value
            if complement in hashmap:
                return [hashmap[complement], index]
            hashmap[value] = index
        
        return
        