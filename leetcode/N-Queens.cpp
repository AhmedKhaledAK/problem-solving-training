class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < n; j++) {
                s += '.';
            }
            board.push_back(s);
        }
        
        vector<vector<string>> boards;
        
        solveNQueens(n, 0, board, boards);
        
        return boards;
    }
    
    void solveNQueens (int n, int col, vector<string>& board, 
                       vector<vector<string>>& boards) {
        if (col >= n) {
            boards.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(i, col, n, board)) {
                board[i][col] = 'Q';
                solveNQueens(n, col + 1, board, boards);
                board[i][col] = '.';
            }
        }
    }
    
    bool isSafe(int row, int col, int n, vector<string>& board) {
        int i, j; 
  
        for (i = 0; i < col; i++) 
            if (board[row][i] == 'Q') 
                return false; 

        for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
            if (board[i][j] == 'Q') 
                return false; 

        for (i = row, j = col; j >= 0 && i < n; i++, j--) 
            if (board[i][j] == 'Q') 
                return false; 
        
        return true;
    }
    
};
