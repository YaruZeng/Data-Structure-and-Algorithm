class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // pos - neg = target
        // pos + neg = sum
        // pos = (target + sum) / 2, target + sum >= 0, (target + sum) % 2 = 0

        int sum = 0;
        for (int num : nums) sum += num;

        if ((target + sum) % 2 != 0 || target + sum < 0) return 0;
        int pos = (target + sum) / 2;

        // construct a bag to count the combinations of nums that sum up to pos
        vector<int> dp(pos + 1, 0);
        dp[0] = 1; // to make it feasible
        for (int i = 0; i < nums.size(); i++) {
            for (int j = pos; j >= nums[i]; j--) {
                dp[j] = dp[j] + dp[j - nums[i]]; // dp[i]: not put nums[i], dp[j - nums[i]]: put nums[i]
            }
        }
        return dp[pos];
    }
};