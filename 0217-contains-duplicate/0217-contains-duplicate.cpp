class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // Solution1: time complexity O(n), space timplexity O(n)
        // unordered_map<int, int> hash;
        // for (int num : nums) {
        //     hash[num]++;
        //     if (hash[num] > 1) {
        //         return true;
        //     }
        // }
        // return false;
        
        // Solution2: time complexity O(nlogn), space timplexity O(1)
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] == nums[i]) return true;
        }
        return false;
    }
};