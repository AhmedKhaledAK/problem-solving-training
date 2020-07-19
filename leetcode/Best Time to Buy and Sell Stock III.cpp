class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int) prices.size();
        if (n == 0) {
            return 0;
        }
        vector<int> left_dp(n), right_dp(n);
        int mn = prices[0], mx = prices[n - 1];
        left_dp[0] = 0, right_dp[n - 1] = 0;
        for (int i = 1; i < n; i++) {
            mn = min(mn, prices[i]);
            left_dp[i] = max(left_dp[i - 1], prices[i] - mn);
        }
        for (int i = n - 2; i >= 0; i--) {
            mx = max(mx, prices[i]);
            right_dp[i] = max(right_dp[i + 1], mx - prices[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, left_dp[i] + right_dp[i]);
        }
        return ans;
    }
};
