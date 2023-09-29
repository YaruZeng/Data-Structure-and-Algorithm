class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int result = nums[0]; // in case all nums < 0
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};