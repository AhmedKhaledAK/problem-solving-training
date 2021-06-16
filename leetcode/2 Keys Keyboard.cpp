class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        if (n == 2) return 2;
        vector<int> dp(n + 1);
        dp[1] = 0;
        dp[2] = 2;
        for (int i = 3; i <=n; i++) {
            dp[i] = i;
            int j = i/2;
            while (j >= 1) {
                if (i % j == 0) dp[i] = min(dp[i], dp[j] + i/j);
                j--;
            }
        }
        return dp[n];
    }
};