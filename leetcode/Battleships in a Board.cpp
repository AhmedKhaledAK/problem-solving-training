class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int H = board.size();
        int W = board[0].size();
        int ans = 0;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (board[i][j] != 'X') continue;
                if (j > 0 && board[i][j - 1] == 'X') continue;
                if (i > 0 && board[i - 1][j] == 'X') continue;
                ans++;
            }
        }
        return ans;
    }
};
