class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = (int) matrix.size();
        if (n == 0 || (int) matrix[0].size() == 0) {
            return false;
        }
        int m = (int) matrix[0].size();
        int i = 0, j = m - 1;
        
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] < target) {
                i++;
            } else if (matrix[i][j] > target) {
                j--;
            }
        }
        return false;
    }
};
