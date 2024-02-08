class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hashmap = {}
        if len(s) != len(t):
            return False
        for i in range(len(s)):
            hashmap[s[i]] = hashmap.get(s[i], 0) + 1
            hashmap[t[i]] = hashmap.get(t[i], 0) - 1
            
        for key in hashmap.keys():
            if hashmap[key] != 0:
                return False
            
        return True