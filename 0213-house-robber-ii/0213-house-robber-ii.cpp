class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        // the head and the tail cannot be stolen at the same night
        int result1 = robRange(nums, 0, nums.size() - 2); // include the head, not include the tail
        int result2 = robRange(nums, 1, nums.size() - 1); // not include the head, include the tail

        return max(result1, result2);
    }

    int robRange(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        if (end - start == 1) return max(nums[start], nums[start + 1]);

        vector<int> dp(nums.size(), 0); // cover the max index in nums

        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[end];
    }
};