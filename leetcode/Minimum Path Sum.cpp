class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                if (i == 0) {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                    continue;
                } 
                if (j == 0) {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                    continue;
                }
                
                dp[i][j] = min(grid[i][j] + dp[i-1][j], grid[i][j] + dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};
