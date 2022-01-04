class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = (int)points.size();
        unordered_map<int, unordered_set<int>> mp;
        for (vector<int> point : points) {
            int x = point[0];
            int y = point[1];
            mp[x].insert(y);
        }
        double ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dx1 = points[j][0] - points[i][0];
                int dy1 = points[j][1] - points[i][1];
                
                for (int k = j + 1; k < n; k++) {
                    int dx2 = points[k][0] - points[i][0];
                    int dy2 = points[k][1] - points[i][1];
                    
                    if (dy1 * dy2 + dx1 * dx2 != 0) {
                        continue;
                    }
                    int x = dx1 + points[k][0];
                    int y = dy1 + points[k][1];
                    
                    if (mp.find(x) != mp.end() && mp[x].find(y) != mp[x].end()) {
                        double area = sqrt(dx1 * dx1 + dy1 * dy1) * sqrt(dx2 * dx2 + dy2 * dy2);
                        ans = min(area, ans);
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
