class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        //     i - s         j - p
        bool dp[slen+1][plen+1]; 
        
        memset(dp, 0, sizeof(dp));
    
        dp[0][0] = true;
        
        for (int i = 1; i < plen+1; i++) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-2];
            }
        }
        
        for (int i = 1; i < slen+1; i++) {
            for (int j = 0; j < plen+1; j++) {
                if (j == 0) {
                    dp[i][j] = false;
                    continue;
                }
                if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*' && 
                           (
                               dp[i][j-2] || 
                               (
                                   dp[i-1][j] && 
                                   (
                                       p[j-2] == '.' || p[j-2] == s[i-1]
                                   )
                               )
                           
                           )) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[slen][plen];
    }
};
