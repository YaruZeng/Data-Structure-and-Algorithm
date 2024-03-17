class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = dict()
        freq = [[] for i in range(len(nums) + 1)]
        
        # get the count of each num
        for num in nums:
            count[num] = count.get(num, 0) + 1
            
        # construct the freq arrays (index: count, value: the list of nums which occurs index times)
        for num, count in count.items():
            freq[count].append(num)
            
        res = []
        for i in range(len(freq) - 1, 0, -1):
            for num in freq[i]:
                res.append(num)
                if len(res) == k:
                    return res