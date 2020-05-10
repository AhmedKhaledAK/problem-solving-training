class Solution {
private:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = (int) board.size();
        int m = (int) board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (bt(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool bt (vector<vector<char>>& board, string word, int i, int j, int len) {
        if (board[i][j] != word[len]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '.';
        len++;
        cout << "len: " << len << endl;
        if (len == word.length()) {
            return true;
        }
        for (int k = 0; k < 4; k++) {
            int nwi = i + row[k];
            int nwj = j + col[k];
            if (isvalid(nwi, nwj, board.size(), board[0].size()) 
                && board[nwi][nwj] != '.') {
                if (bt(board, word, nwi, nwj, len)) {
                    return true;
                }
            }
        }
        board[i][j] = temp;
        return false;
    }
    
    bool isvalid (int i, int j, int r, int c) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
};

