class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # get the count of each num
        count = {}
        for num in nums:
            count[num] = count.get(num, 0) + 1
        
        # get the count: list (sorted)
        freq = [[] for i in range(len(nums) + 1)]
        for n, c in count.items():
            freq[c].append(n)
            
        
        # get the k top frequent elements
        res = []
        for i in range(len(freq) - 1, 0, -1):
            for n in freq[i]:
                res.append(n)
                if len(res) == k:
                    return res
                
        