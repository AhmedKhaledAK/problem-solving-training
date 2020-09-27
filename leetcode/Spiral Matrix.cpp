class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return {};
        }
        int R = matrix.size(), C = matrix[0].size(); 
        vector<int> ans;
        vector<vector<bool>> seen(R, vector<bool>(C));
        
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        
        int r, c, di;
        r = c = di = 0;
        
        for (int i = 0; i < R * C; i++) {
            ans.push_back(matrix[r][c]);
            seen[r][c] = true;
            int nr = r + dr[di];
            int nc = c + dc[di];
            if (0 <= nr && nr < R && 0 <= nc && nc < C && !seen[nr][nc]) {
                r = nr;
                c = nc;
            } else {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }
        
        return ans;
    }
};

