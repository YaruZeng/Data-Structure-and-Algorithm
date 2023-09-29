class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();

        vector<vector<int>> dp(lenS + 1, vector<int>(lenT + 1, 0));

        for (int i = 1; i <= lenS; i++) {
            for (int j = 1; j <= lenT; j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[lenS][lenT] == lenS ? true : false;
    }
};