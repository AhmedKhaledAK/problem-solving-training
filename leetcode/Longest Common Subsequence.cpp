class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        string s = text1, t = text2;
        int dp[s.length()+1][t.length()+1];
        
        for(int i =0; i <= s.length(); i++){
            for(int j = 0; j <= t.length(); j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s.length()][t.length()];
    }
};
