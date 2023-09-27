class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);

        dp[2] = 1; // dp[0] and dp[1] is meaningless
        for (int i = 3; i <= n; i++) { // the number to be broken
            for (int j = 1; j <= i/2; j++) { // the first multiplier; the max product is got by close multipliers
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            } 
        }
        return dp[n];
    }
};