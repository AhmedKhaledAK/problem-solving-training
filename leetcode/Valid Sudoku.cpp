class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int H = (int) board.size();
        int W = (int) board[0].size();
        
        for (int i = 0; i < H; i++) {
            unordered_map<int, bool> mp;
            for (int j = 0; j < W; j++) {
                if (board[i][j] != '.') {
                    if (mp.find(board[i][j]) != mp.end()) {
                        return false;
                    }
                    mp[board[i][j]] = true;
                }
            }
        }
        
        for (int i = 0; i < W; i++) {
            unordered_map<int, bool> mp;
            for (int j = 0; j < H; j++) {
                if (board[j][i] != '.') {
                    if (mp.find(board[j][i]) != mp.end()) {
                        return false;
                    }
                    mp[board[j][i]] = true;
                }
            }
        }
        
        for (int i = 0; i <= 6; i += 3) {
            for (int j = 0; j <= 6; j += 3) {
                if (!traverse(i, j, i + 3, j + 3, board)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool traverse (int si, int sj, int A, int B, vector<vector<char>>& board) {
        unordered_map<int, bool> mp;
        for (int i = si; i < A; i++) {
            for (int j = sj; j < B; j++) {
                if (board[i][j] != '.') {
                    if (mp.find(board[i][j]) != mp.end()) {
                        return false;
                    }
                    mp[board[i][j]] = true;
                }
            }
        }
        return true;
    }
};
