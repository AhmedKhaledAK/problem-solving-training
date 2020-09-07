class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = (int) points.size();
        vector<int> dists(n);
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            dists[i] = dist(points[i]);
        }
        
        sort(dists.begin(), dists.end());
        
        int distK = dists[K - 1];
        
        for (int i = 0; i < n; i++) {
            if (dist(points[i]) <= distK) {
                ans.push_back(points[i]);
            }
        }
        
        return ans;
    }
    
    int dist(vector<int> point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    
};
