class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int) nums.size();
        vector<vector<int>> ans;
        
        int sz = (1 << n);
        for (int i = 0; i < sz; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
