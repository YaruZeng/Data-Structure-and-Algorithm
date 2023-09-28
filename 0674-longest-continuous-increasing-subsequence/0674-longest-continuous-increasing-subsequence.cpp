class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        vector<int> dp(nums.size(), 1);

        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) dp[i] = dp[i - 1] + 1;
            result = max(result, dp[i]);
        }
        
        return result;
    }
};