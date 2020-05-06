class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = (int) obstacleGrid.size(), m = (int) obstacleGrid[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0) && obstacleGrid[i][j] != 1) {
                    if (j != 0 && dp[i][j - 1] == 0) {
                        continue;
                    }
                    if (i != 0 && dp[i - 1][j] == 0) {
                        continue;
                    }
                    dp[i][j] = 1;
                    continue;
                }
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};
