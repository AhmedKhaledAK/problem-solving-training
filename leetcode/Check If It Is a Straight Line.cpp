class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = (int) coordinates.size();
        if (n == 2) {
            return true; 
        }
        int x1, y1, x2, y2;
        double slope = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            x1 = coordinates[i][0];
            y1 = coordinates[i][1];
            x2 = coordinates[i + 1][0];
            y2 = coordinates[i + 1][1];
            
            if (slope == INT_MAX) {
                slope = (double) (y2 - y1) / (double) (x2 - x1);
                continue;
            }
            
            if ( (double) (y2 - y1) / (double) (x2 - x1) != slope) {
                return false;
            }
        }
        return true;
    }
};
