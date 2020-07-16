class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int H = triangle.size();
        
        vector<int> dp;
        dp = triangle[0];
        
        for (int i = 1; i < H; i++) {
            vector<int> temp(triangle[i].size());
            vector<int> tr = triangle[i];
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    temp[j] = tr[j] + dp[0];
                } else if (j == i) {
                    temp[j] = tr[j] + dp[dp.size() - 1];
                } else {
                    temp[j] = tr[j] + min(dp[j - 1], dp[j]);
                }
            }
            dp = temp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
