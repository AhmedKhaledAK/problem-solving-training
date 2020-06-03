class Solution {
    
    static bool cmp(vector<int> a, vector<int> b) {
        return abs(a[0] - a[1]) > abs(b[0] - b[1]);
    }
    
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = (int) costs.size(), a, b, ans;
        a = b = n / 2;
        ans = 0;
        sort(costs.begin(), costs.end(), cmp);
        
        for (int i = 0; i < n; i++) {
            if (b == 0 || (a > 0 && costs[i][0] <= costs[i][1])) {
                a--;
                ans += costs[i][0];
            } else {
                b--;
                ans += costs[i][1];
            }
        }
        return ans;
    }
};
