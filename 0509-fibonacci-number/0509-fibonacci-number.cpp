class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;

        int dp0 = 0;
        int dp1 = 1;

        int sum = 0;

        for (int i = 2; i <= n; i++) {
            sum = dp0 + dp1;
            dp0 = dp1;
            dp1 = sum;
        }
        
        return dp1;
    }
};