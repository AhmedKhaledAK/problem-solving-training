class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        int oddRows, oddCols;
        oddRows = oddCols = 0;
        for (int i = 0; i < indices.size(); i++) {
            row[indices[i][0]]++;
            col[indices[i][1]]++;
        }
        for (int cell : row) {
            if (cell % 2 == 1) oddRows++;
        }
        for (int cell : col) {
            if (cell %2 == 1) oddCols++;
        }
        return oddRows * n + oddCols * m - 2 * oddRows * oddCols;
    }
};
