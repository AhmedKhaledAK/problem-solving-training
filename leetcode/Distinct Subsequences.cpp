class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.length(), nt = t.length();
        vector<vector<long long>> dp(ns + 1, vector<long long>(nt + 1));
        
        for (int i = 0; i <= ns; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= ns; i++) {
            for (int j = 1; j <= nt; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[ns][nt];
    }
};
