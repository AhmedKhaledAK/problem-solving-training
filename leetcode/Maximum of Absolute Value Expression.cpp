class Solution {
    int signs[2] = {-1, 1};
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        for (int s1 : signs)
        {
            for (int s2 : signs)
            {
                int mn = INT_MAX;
                int mx = INT_MIN;
                for (int i = 0; i < arr1.size(); i++)
                {
                    int cal = s1 * arr1[i] + s2 * arr2[i] + i;
                    mn = min(cal, mn);
                    mx = max(cal, mx);
                }
                ans = max(ans, mx - mn);
            }
        }
        return ans;
    }
};
