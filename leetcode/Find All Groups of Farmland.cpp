class Solution {
    vector<vector<int>> ans;
    pair<int, int> rightMost;
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int H = land.size();
        int W = land[0].size();
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (land[i][j] == 1) {
                    rightMost = {i, j};
                    dfs(land, i, j);
                    ans.push_back({i, j, rightMost.first, rightMost.second});
                }
            }
        }
        return ans;
    }
    
    void dfs (vector<vector<int>>& land, int i, int j) {
        if (i < 0 || j < 0 || i >= land.size() || j >= land[0].size() || land[i][j] == 0) {
            return;
        }
        pair<int, int> currentRightMost = {i, j};
        rightMost = max(currentRightMost, rightMost);
        land[i][j] = 0;
        dfs(land, i + 1, j);
        dfs(land, i, j + 1);
    }
};
