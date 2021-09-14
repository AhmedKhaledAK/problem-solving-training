class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int minDis = INT_MAX;
        for (int i = 0; i < points.size(); i++)
        {
            vector<int> point = points[i];
            if (x == point[0] || y == point[1])
            {
                int dis = abs(x - point[0]) + abs(y - point[1]);
                if (minDis > dis)
                {
                    minDis = dis;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
