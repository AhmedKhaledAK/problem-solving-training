class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int d[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1}};
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dis (n, vector<int>(n, -1));
        bool ok = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                } else {
                    ok = true;
                }
            }
        }
        if (!ok) {
            return -1;
        }
        int ans = -1;
        while (!q.empty()) {
            ans++;
            int sz = q.size();
            while (sz--) {
                auto cell = q.front();
                int r = cell.first;
                int c = cell.second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = r + d[i][0];
                    int nc = c + d[i][1];
                    if(nc >= 0 && nr >= 0 && nr < n && nc < m && grid[nr][nc] == 0)
                    {
                        grid[nr][nc] = 1;
                        q.push(make_pair(nr, nc));
                        
                    }
                }
            }
        }
        return ans;
    }
};
