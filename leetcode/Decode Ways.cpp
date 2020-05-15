class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = n > 0 && s[0] == '0' ? 0 : 1;
        cout << dp[1];
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] - '0' >= 1) {
                dp[i] += dp[i - 1];
            }
            int val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (val >= 10 && val <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
