class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral(n, vector<int>(n, 0));
        int row[4] = {0, 1, 0, -1};
        int col[4] = {1, 0, -1, 0};
        int dir, i, j, cnt;
        dir = i = j = cnt = 0;
        while (cnt != n*n) {
            while (i < n && j < n && i >= 0 && j >= 0 && spiral[i][j] == 0) {
                spiral[i][j] += ++cnt;
                i = i + row[dir];
                j = j + col[dir];
            }
            if (dir == 0) {
                j--;
            } else if (dir == 1) {
                i--;
            } else if (dir == 2) {
                j++;
            } else if (dir == 3) {
                i++;
            }
            dir = (dir + 1) % 4;
            i = i + row[dir];
            j = j + col[dir];
        }
        return spiral;
    }
};
