class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        vector<int> dp(nums.size(), 1); // the max length of increasing subsequence ending with nums[i]
        int result = 0;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};