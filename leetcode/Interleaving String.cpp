class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3) {
            return false;
        }
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1));
        
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 && j == 0) { // this means that s3 is also empty
                    dp[i][j] = true;
                    continue;
                }
                char c = s3[i + j - 1];
                if (i == 0) {   // s3 maybe from s2
                    if (s2[j - 1] == c) {
                        dp[i][j] = dp[i][j - 1];
                    }
                } else if (j == 0) {    // s3 maybe from s1
                    if (s1[i - 1] == c) {
                        dp[i][j] = dp[i - 1][j];
                    }
                } else if (s1[i - 1] == c && s2[j - 1] != c) {
                    dp[i][j] = dp[i - 1][j];
                } else if (s1[i - 1] != c && s2[j - 1] == c) {
                    dp[i][j] = dp[i][j - 1];
                } else if (s1[i - 1] == c && s2[j - 1] == c) {
                    dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
