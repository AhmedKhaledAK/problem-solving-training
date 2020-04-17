class Solution {
    
    int row [4] = {-1, 1, 0, 0};
    int col [4] = {0, 0, -1, 1};
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != '0') {
                    traverse(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    void traverse (int i , int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++) {
            int nwi = i + row[k], nwj = j + col[k];
            if (isvalid(nwi,nwj, grid.size(), grid[0].size())) {
                if (grid[nwi][nwj] == '1') {
                    traverse(nwi, nwj, grid);
                }
            }
        }
    }
    
    bool isvalid (int i , int j, int rows, int cols){
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }
};
