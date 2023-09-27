class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;

        int dp1 = 1;
        int dp2 = 2;

        int sum = 0;
        for (int i = 3; i <= n; i++) {
            sum = dp1 + dp2;
            dp1 = dp2;
            dp2 = sum;
        }

        return dp2;
    }
};