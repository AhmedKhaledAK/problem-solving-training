class Solution {
private:
    int inf;
    int rows, cols;
    
    int getMinHealth(int currCell, int nextRow, int nextCol, vector<vector<int>>& dp) {
        if (nextRow >= rows || nextCol >= cols) {
            return inf;
        }
        
        int nextCell = dp[nextRow][nextCol];
        return max(1, nextCell - currCell);
    }
    
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        rows = dungeon.size();
        cols = dungeon[0].size();
        inf = INT_MAX;
        vector<vector<int>> dp(rows, vector<int> (cols));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dp[i][j] = inf;
            }
        }
        
        int currCell, rightHealth, downHealth, nextHealth, minHealth;
        for (int row = rows - 1; row >= 0; --row) {
          for (int col = cols - 1; col >= 0; --col) {
            currCell = dungeon[row][col];

            rightHealth = getMinHealth(currCell, row, col + 1, dp);
            downHealth = getMinHealth(currCell, row + 1, col, dp);
            nextHealth = min(rightHealth, downHealth);

            if (nextHealth != inf) {
              minHealth = nextHealth;
            } else {
              minHealth = currCell >= 0 ? 1 : 1 - currCell;
            }
            dp[row][col] = minHealth;
          }
        }
        return dp[0][0];
    }
};
