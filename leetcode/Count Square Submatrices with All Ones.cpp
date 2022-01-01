class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i && j && matrix[i][j] && matrix[i - 1][j - 1] && matrix[i - 1][j] && matrix[i][j - 1]) {
                    matrix[i][j] = 1 + min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]});
                }
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};
