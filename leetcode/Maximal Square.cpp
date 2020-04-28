class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int H = (int) matrix.size();
        if (H == 0 || matrix[0].empty()) {
            return 0;
        }
        int W = matrix[0].size();
        vector<vector<int>> dp (H, vector<int>(W)); // initialized with zeros at first
        int ans = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0) {
                        dp[i][j] += min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                    }
                    ans = max(dp[i][j], ans);
                }
            }
        }
        return ans * ans;
    }
};
