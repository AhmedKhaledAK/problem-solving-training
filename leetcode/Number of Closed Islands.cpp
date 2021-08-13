class Solution {
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};
    bool ok = true;
public:
    int closedIsland(vector<vector<int>>& grid) {
        int H = grid.size();
        if (H == 0) return 0;
        int W = grid[0].size();
        if (W == 0) return 0;
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        int ans = 0;
        for (int i = 1; i < H - 1; i++) {
            for (int j = 1; j < W - 1; j++) {
                if (!visited[i][j] && grid[i][j] == 0) {
                    dfs(grid, H, W, visited, i, j);
                    if (ok) ans++;
                    ok = true;
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int H, int W, vector<vector<bool>>& visited, int i, int j) {
        if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
            ok = false;
            return;
        }
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int ni = i + row[k];
            int nj = j + col[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj] && grid[ni][nj] == 0) {
                dfs(grid, H, W, visited, ni, nj);
            }
        }
    }
};
