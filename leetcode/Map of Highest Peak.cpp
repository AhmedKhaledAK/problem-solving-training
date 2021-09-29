class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int H = isWater.size();
        int W = isWater[0].size();
        vector<vector<int>> heights(H, vector<int>(W, INT_MAX));
        queue<pair<int,int>> shortestPaths;
        int r[4] = {0, 1, -1, 0};
        int c[4] = {1, 0, 0, -1};
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (isWater[i][j] == 1)
                {
                    heights[i][j] = 0;
                    shortestPaths.push({i, j});
                }
            }
        }
        while (!shortestPaths.empty())
        {
            int i = shortestPaths.front().first;
            int j = shortestPaths.front().second;
            shortestPaths.pop();
            for (int k = 0; k < 4; k++)
            {
                int newI = i + r[k];
                int newJ = j + c[k];
                if (newI >= 0  && newI < H && newJ >= 0 && newJ < W 
                    && heights[newI][newJ] > 1 + heights[i][j])
                {
                    heights[newI][newJ] = 1 + heights[i][j];
                    shortestPaths.push({newI, newJ});
                }
            }
        }
        return heights;
    }
};
