class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int sub = 2; sub <= n; sub++) {
            for (int st = 0; st < n - sub + 1; st++) {
                int e = st + sub - 1;
                if (s[st] == s[e] && sub == 2) {
                    dp[st][e] = 2;
                } else if (s[st] == s[e]) {
                    dp[st][e] = dp[st + 1][e - 1] + 2;
                } else {
                    dp[st][e] = max(dp[st][e - 1], dp[st + 1][e]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
