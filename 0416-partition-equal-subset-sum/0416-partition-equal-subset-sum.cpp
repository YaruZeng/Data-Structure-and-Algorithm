class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // get sum of a subset
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) return false;

        // construct a bag with size sum / 2, if dp[bagSize] == bagSize, return true
        int bagSize = sum / 2;

        vector<int> dp(bagSize + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[bagSize] == bagSize) return true;
        return false;
    }
};