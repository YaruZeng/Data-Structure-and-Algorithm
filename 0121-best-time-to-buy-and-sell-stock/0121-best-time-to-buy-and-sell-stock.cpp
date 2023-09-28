class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]); // continue holding a stock or buy a stock today
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]); // continue not holding a stock or sell a stock today
        }

        return dp[len - 1][1];
    }
};