class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        // get the half weight of total stones
        int sum = 0;
        for (int stoneWeight : stones) {
            sum += stoneWeight;
        }
        int target = sum / 2;

        // construct a bag to pack half weight
        vector<int> dp(target + 1, 0);

        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - dp[target] - dp[target]; // the left stone weight
    }
};