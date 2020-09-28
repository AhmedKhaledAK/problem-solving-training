class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int R = board.size(), C = board[0].size();
        bool todo = false;
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c + 2 < C; c++) {
                int candy = abs(board[r][c]);
                if (candy != 0 && candy == abs(board[r][c + 1]) 
                    && candy == abs(board[r][c + 2])) {
                    board[r][c] = board[r][c + 1] = board[r][c + 2] = -candy;
                    todo = true;
                }
            }
        }
        
        for (int r = 0; r + 2 < R; r++) {
            for (int c = 0; c < C; c++) {
                int candy = abs(board[r][c]);
                if (candy != 0 && candy == abs(board[r + 1][c]) 
                    && candy == abs(board[r + 2][c])) {
                    board[r][c] = board[r + 1][c] = board[r + 2][c] = -candy;
                    todo = true;
                }
            }
        }
        
        for (int c = 0; c < C; c++) {
            int write = R - 1;
            for (int r = R - 1; r >= 0; r--) {
                if (board[r][c] > 0) {
                    board[write--][c] = board[r][c];
                }
            }
            while(write >= 0) {
                board[write--][c] = 0;
            }
            
        }
        
        return todo ? candyCrush(board) : board;
    }
};
