class Solution {
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board);
    }
    
    bool sudokuSolver (vector<vector<char>>& board) {
        
        pair<int, int> rc = findEmptySpot(board);
        if (rc.first == -1) {
            return true;
        }
        
        for (char c = '1'; c <= '9'; c++) {
            if (isSafe(board, rc.first, rc.second, c)) {
                board[rc.first][rc.second] = c;
                if (sudokuSolver(board)) {
                    return true;
                }
                board[rc.first][rc.second] = '.';
            }
        }
        return false;
    }
    
    pair<int, int> findEmptySpot(vector<vector<char>>& board) {
        int H = (int) board.size();
        int W = (int) board[0].size();
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (board[i][j] == '.') {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
    
    
    bool UsedInRow(vector<vector<char>>& board, int row, int num) {
        int W = board[0].size();
        for (int col = 0; col < W; col++)  
            if (board[row][col] == num)  
                return true;  
        return false;  
    }  
  
    bool UsedInCol(vector<vector<char>>& board, int col, char num) { 
        int H = board.size();
        for (int row = 0; row < H; row++)  
            if (board[row][col] == num)  
                return true;  
        return false;  
    }  
  
    bool UsedInBox(vector<vector<char>>& board, int boxStartRow, 
                   int boxStartCol, char num) {  
        for (int row = 0; row < 3; row++)  
            for (int col = 0; col < 3; col++)  
                if (board[row + boxStartRow] 
                        [col + boxStartCol] == num)  
                    return true;  
        return false;  
    } 
    
    bool isSafe(vector<vector<char>>& board, int row, int col, char num)  {
        return !UsedInRow(board, row, num) &&  
           !UsedInCol(board, col, num) &&  
           !UsedInBox(board, row - row % 3 ,  
                      col - col % 3, num) &&  
            board[row][col] == '.';
    }  
};
