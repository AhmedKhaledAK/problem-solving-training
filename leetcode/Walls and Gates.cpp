class Solution {
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n == 0) {
            return;
        }
        int m = rooms[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            pair<int, int> pr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = pr.first + row[i];
                int nc = pr.second + col[i];
                
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || rooms[nr][nc] != INT_MAX) {
                    continue;
                }
                rooms[nr][nc] = rooms[pr.first][pr.second] + 1;
                q.push({nr, nc});
            }
        }
    }
};
