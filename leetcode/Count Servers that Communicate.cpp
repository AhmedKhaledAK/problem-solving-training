class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        int m = (int) grid[0].size();
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && (rows[i] > 1 || cols[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
