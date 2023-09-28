class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0]; // hold a stock the first time
        dp[0][3] = -prices[0]; // hold a stock the second time

        for (int i = 1; i < prices.size(); i++) {
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]); // not hold a stock for the first period
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]); // not hold a stock for the second period
        }

        return dp[prices.size() - 1][4];
    }
};