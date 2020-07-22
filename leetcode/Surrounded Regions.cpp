class Solution {
    
    int r[4] = {0, 0, 1, -1};
    int c[4] = {1, -1, 0, 0};
    
public:
    void solve(vector<vector<char>>& board) {
        if ((int) board.size() == 0) {
            return;
        }
        int H = (int) board.size();
        int W = (int) board[0].size();
        
        for (int i = 0; i < H; i++) {
            if (i == 0 || i == H - 1) {
                for (int j = 0; j < W; j++) {
                    if (board[i][j] == 'O') {
                        dfs({i, j}, board);
                    }
                }
            } else {
                if (board[i][0] == 'O') {
                    dfs({i, 0}, board);
                }
                if (board[i][W - 1] == 'O') {
                    dfs({i, W - 1}, board);
                }
            }
        }
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    void dfs(pair<int, int> p, vector<vector<char>>& board) {
        board[p.first][p.second] = '.';
        for (int i = 0; i < 4; i++) {
            int ni = p.first + r[i];
            int nj = p.second + c[i];
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
                if (board[ni][nj] == 'O') {
                    dfs({ni, nj}, board);
                }
            }
        }
    }
};
