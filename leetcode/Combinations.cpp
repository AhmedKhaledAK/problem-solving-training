class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        bt(0, n, k, v, ans);
        return ans;
    }
    
    void bt (int i, int n, int k, vector<int>& v, vector<vector<int>>& ans) {
        if ((int) v.size() == k) {
            ans.push_back(v);
            return;
        }
        for (int j = i + 1; j <= n; j++) {
            v.push_back(j);
            bt(j, n, k, v, ans);
            v.pop_back();
        }
    }
    
};
